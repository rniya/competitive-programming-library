#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../base.hpp"
#include "../../convolution/NumberTheoreticTransform.hpp"
#include "../../modulo/modint.hpp"
#include "../../polynomial/FormalPowerSeries.hpp"

using mint = modint<998244353>;
using FPS = FormalPowerSeries<mint>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    NumberTheoreticTransform<998244353> NTT;
    auto mul = [&](const FPS::Poly& a, const FPS::Poly& b) {
        auto res = NTT.multiply(a, b);
        return FPS::Poly(res.begin(), res.end());
    };
    FPS::set_mul(mul);

    int N;
    cin >> N;
    FPS a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    FPS b = a.exp();
    for (int i = 0; i < N; i++) cout << b[i] << (i + 1 == N ? '\n' : ' ');
}