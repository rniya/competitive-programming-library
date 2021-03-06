#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G"
#define ERROR 0.000001

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Circle c_1, c_2;
    cin >> c_1 >> c_2;
    vector<Point> res;
    for (auto l : common_tangent(c_1, c_2)) res.emplace_back(contain(c_1, l.a) ? l.a : l.b);
    sort(res.begin(), res.end());
    for (auto p : res) cout << p << '\n';
}