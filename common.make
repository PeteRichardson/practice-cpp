SOURCES		:= $(PROG_NAME).cpp
OBJECTS 	 = $(subst .cpp,.o,$(SOURCES))
BUILDDIR    := build
SYSLIBROOT	:= /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk

all : setup $(PROG_NAME) Makefile

setup :
	clear
	$(info # Building $(PROG_NAME) using sources $(SOURCES))
	@mkdir -p build

$(PROG_NAME) : $(BUILDDIR)/$(OBJECTS)
	$(info # ----------  LINKING  ----------)
	ld -o $@ \
    -arch arm64 \
    -demangle \
    -platform_version macos 12.0.0 12.1 \
    -syslibroot $(SYSLIBROOT) \
    -lSystem -lc++ $(EXTRA_LIBS) \
    $^

$(BUILDDIR)/%.o : %.cpp
	$(info # ---------- COMPILING ----------)
	g++ -c -g -O0 -std=c++20 -o $@ $<

clean :
	$(info # Cleaning)
	rm -f $(PROG_NAME)
	rm -rf build/ ${PROG_NAME}.dsym/