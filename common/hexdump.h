#ifndef HEXDUMP_H
#define HEXDUMP_H

#include <iomanip>
#include <iostream>
#include <memory>

// utility: keeps states of an ostream, restores on destruction
template <typename T>
struct ostream_state {
  explicit ostream_state(std::basic_ostream<T>& stream)
      : stream_{stream}, flags_{stream.flags()}, fill_{stream.fill()} {}

  ostream_state(const ostream_state& other) = delete;
  ostream_state& operator=(const ostream_state& other) = delete;

  ostream_state(ostream_state&& other) = delete;
  ostream_state& operator=(ostream_state&& other) = delete;

  ~ostream_state() {
    stream_.flags(flags_);
    stream_.fill(fill_);
  }

private:
  std::basic_ostream<T>&                    stream_;
  std::ios_base::fmtflags                   flags_;
  typename std::basic_ostream<T>::char_type fill_;
};

namespace detail {
inline void print_adr(std::ostream& os, const std::byte* adr) {
    os << std::setw(19) << std::setfill(' ') << adr; // NOLINT
}

inline void print_fill_advance(std::ostream& os, const std::byte*& buf, std::size_t cnt,
                               const std::string& str) {
  while (cnt-- != 0U) {
    ++buf; // NOTE: unusually this in passsed in by ref and we advance it. NOLINT
    os << str;
  }
}

inline void print_hex(std::ostream& os, const std::byte* buf, std::size_t linesize, std::size_t pre,
                      std::size_t post) {
  print_fill_advance(os, buf, pre, "-- ");
  {
    os << std::setfill('0') << std::hex;
    auto cnt = linesize - pre - post;
    while (cnt-- != 0U) os << std::setw(2) << static_cast<unsigned>(*buf++) << ' '; // NOLINT
  }
  print_fill_advance(os, buf, post, "-- ");
}

inline void print_ascii(std::ostream& os, const std::byte* buf, std::size_t linesize,
                        std::size_t pre, std::size_t post) {
  print_fill_advance(os, buf, pre, ".");
  auto cnt = linesize - pre - post;
  while (cnt-- != 0U) {
    os << (std::isprint(static_cast<unsigned char>(*buf)) != 0 ? static_cast<char>(*buf) : '.');
    ++buf; // NOLINT
  }
  print_fill_advance(os, buf, post, ".");
}
} // namespace detail

inline std::ostream& hex_dump(std::ostream& os, const std::byte* buffer, std::size_t bufsize) {
  if (buffer == nullptr || bufsize == 0) return os;

  constexpr std::size_t linesize{16};
  const std::byte*      buf{buffer};
  std::size_t           pre =
      reinterpret_cast<std::size_t>(buffer) % linesize; // Size of pre-buffer area  NOLINT
  bufsize += pre;
  buf -= pre; // NOLINT

  auto state = ostream_state{os}; // save stream setting and restore at end of scope
  while (bufsize != 0U) {
    std::size_t post = bufsize < linesize ? linesize - bufsize : 0;

    detail::print_adr(os, buf);
    os << ": ";
    detail::print_hex(os, buf, linesize, pre, post);
    os << " | ";
    detail::print_ascii(os, buf, linesize, pre, post);
    os << "\n";

    buf += linesize; // NOLINT
    bufsize -= linesize - post;
    pre = 0;
  }
  return os;
}

namespace dbg {
  class memdump {
  public:
    memdump(const void* buf, std::size_t bufsz)
        : buffer_{reinterpret_cast<const std::byte*>(buf)}, bufsize_{bufsz} {}

    template <typename T>
    explicit memdump(const T& buf)
        : buffer_{reinterpret_cast<const std::byte*>(&buf)}, bufsize_{sizeof(T)} {}

    // It's UB to access `+ 1`th byte of a string_view so we don't, despite most
    // targets of string_views (ie std::string or string literal) having '\0'.
    template <>
    explicit memdump(const std::string_view& buf)
        : buffer_{reinterpret_cast<const std::byte*>(&buf)}, bufsize_{sizeof(buf)} {
      child_       = std::make_unique<memdump>(buf.data(), buf.size());
      child_label_ = "string viewed";
    }

    // There is some debate but we believe str[size()] is legal via [] or *
    // but UB via iterator. So here we DO show the '`0' terminator.
    template <>
    explicit memdump(const std::string& buf)
        : buffer_{reinterpret_cast<const std::byte*>(&buf)}, bufsize_{sizeof(buf)} {
      auto data_byte_ptr = reinterpret_cast<const std::byte*>(buf.data());
      if (!(data_byte_ptr > buffer_ && data_byte_ptr < buffer_ + bufsize_)) {
        // not SBO, show the real string as well
        child_ = std::make_unique<memdump>(buf.data(), buf.size() + 1);
        child_label_ = "heap string";
      }
    }

    friend std::ostream& operator<<(std::ostream& os, const memdump& memdump) {
      hex_dump(os, memdump.buffer_, memdump.bufsize_); // NOLINT
      if (memdump.child_) os << std::setw(19) << memdump.child_label_ << ":\n" << *(memdump.child_);
      return os;
    }

  private:
    const std::byte* buffer_;
    std::size_t      bufsize_;

    std::unique_ptr<memdump> child_ = nullptr;
    std::string         child_label_;
  };

    template <typename T>
    void dump(std::ostream& out, std::string message, T& obj) {
        out << message << " [size " << sizeof obj << " bytes]:\n";
        out << dbg::memdump(obj) << std::endl;
    }
}

#endif