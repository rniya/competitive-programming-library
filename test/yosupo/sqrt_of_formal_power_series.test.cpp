#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "polynomial/FormalPowerSeries.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;
using FPS = FormalPowerSeries<mint>;

// https://ei1333.github.io/library/math/combinatorics/mod-sqrt.cpp
namespace ei1333 {

template <typename T> T mod_pow(T x, int64_t n, const T& p) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret % p;
}

template <typename T> T mod_sqrt(const T& a, const T& p) {
    if (a == 0) return 0;
    if (p == 2) return a;
    if (mod_pow(a, (p - 1) >> 1, p) != 1) return -1;
    T b = 1;
    while (mod_pow(b, (p - 1) >> 1, p) == 1) ++b;
    T e = 0, m = p - 1;
    while (m % 2 == 0) m >>= 1, ++e;
    T x = mod_pow(a, (m - 1) >> 1, p);
    T y = a * (x * x % p) % p;
    (x *= a) %= p;
    T z = mod_pow(b, m, p);
    while (y != 1) {
        T j = 0, t = y;
        while (t != 1) {
            j += 1;
            (t *= t) %= p;
        }
        z = mod_pow(z, T(1) << (e - j - 1), p);
        (x *= z) %= p;
        (z *= z) %= p;
        (y *= z) %= p;
        e = j;
    }
    return x;
}

}  // namespace ei1333

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    FPS a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    auto get_sqrt = [&](mint x) { return ei1333::mod_sqrt<int64_t>(x.val(), mint::mod()); };
    FPS b = a.sqrt(get_sqrt);
    if (b.empty()) {
        std::cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < N; i++) std::cout << b[i] << (i + 1 == N ? '\n' : ' ');
}