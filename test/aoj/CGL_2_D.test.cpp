#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D"

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int q;
    cin >> q;
    for (; q--;) {
        Segment s_1, s_2;
        cin >> s_1 >> s_2;
        cout << distance(s_1, s_2) << '\n';
    }
}