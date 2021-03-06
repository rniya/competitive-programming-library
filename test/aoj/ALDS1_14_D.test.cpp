#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_D"

#include "../../base.hpp"
#include "../../string/SuffixArray.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string T;
    int Q;
    cin >> T >> Q;

    SuffixArray SA(T);

    for (; Q--;) {
        string P;
        cin >> P;
        cout << (SA.count(P) > 0) << '\n';
    }
}