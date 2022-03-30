#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>


using std::cout, std::endl, std::string;

std::string operator"" _s(const char* p, size_t n) {
    return std::string{p};
}
int main(int argc, char** argv) {

    std::vector<int> ints{1,2,3,4,5,6,7,8,9,10};
    auto sum = std::accumulate(ints.begin(), ints.end(), 0);
    cout << "sum is " << sum << endl;

    std::vector<string> names{"Pete"_s, "Wendy"_s, "Katherine"_s, "Bella"_s};
    std::string comma_sep = std::accumulate(names.begin()+1, names.end(), names[0],
         [] (string lhs, string rhs) { return lhs + "," + rhs; });
    cout << "comma_sep =  " << comma_sep << endl;

    std::stringstream ss;
    copy(names.begin(), names.end(), std::ostream_iterator<string>(ss, ","));
    string s = ss.str();
    s.erase(s.size()-1);     // or s.pop_back();
    cout << "comma_sep2 = " << s << endl;
}
