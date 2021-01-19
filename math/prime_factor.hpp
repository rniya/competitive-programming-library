#pragma once
#include "../base.hpp"

/**
 * @brief 素因数分解
 */
template <typename T> map<T, int> prime_factor(T n) {
    map<T, int> res;
    for (T i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}