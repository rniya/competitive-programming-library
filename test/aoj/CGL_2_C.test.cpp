#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C"
#define ERROR 0.00000001

#include <iomanip>
#include "geometry/crosspoint.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    int q;
    std::cin >> q;
    for (; q--;) {
        Segment<double> s, t;
        std::cin >> s >> t;
        auto res = crosspoint(s, t);
        std::cout << res << '\n';
    }
}