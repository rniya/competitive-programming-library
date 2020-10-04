#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../combinatorics/combination.hpp"

using mint=modint<1000000007>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination<mint> COM(2010);
    int n,k; cin >> n >> k;

    cout << COM.C(n+k-1,k-1) << '\n';
}