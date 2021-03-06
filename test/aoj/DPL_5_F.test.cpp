#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F"

#include "../../base.hpp"
#include "../../combinatorics/combination.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<1000000007>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination<mint> COM(1010);
    int n, k;
    cin >> n >> k;

    cout << COM.C(n - 1, n - k) << '\n';
}