---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: linearalgebra/characteristic_polynomial.hpp
    title: Characteristic Polynomial
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/characteristic_polynomial
    links:
    - https://judge.yosupo.jp/problem/characteristic_polynomial
  bundledCode: "#line 1 \"test/yosupo/characteristic_polynomial.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/characteristic_polynomial\"\n\n#line\
    \ 2 \"base.hpp\"\n#define LOCAL\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (size_t i =\
    \ 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \"\
    \ \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr\
    \ != m.end();) {\n        os << '(' << itr->first << ',' << itr->second << ')';\n\
    \        if (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n    \
    \    os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, size_t N> ostream& operator<<(ostream& os, const array<T,\
    \ N>& v) {\n    for (size_t i = 0; i < N; i++) {\n        os << v[i] << (i + 1\
    \ == N ? \"\" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename\
    \ T> void print_tuple(ostream&, const T&) {}\ntemplate <int i, typename T, typename\
    \ H, class... Args> void print_tuple(ostream& os, const T& t) {\n    if (i) os\
    \ << ',';\n    os << get<i>(t);\n    print_tuple<i + 1, T, Args...>(os, t);\n\
    }\ntemplate <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>&\
    \ t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>, Args...>(os, t);\n\
    \    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate <class\
    \ Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n    cerr\
    \ << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate\
    \ <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate\
    \ <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\nint topbit(signed\
    \ t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(long long t)\
    \ { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(signed a) { return\
    \ a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long long a) { return a == 0 ?\
    \ 64 : __builtin_ctzll(a); }\nint popcount(signed t) { return __builtin_popcount(t);\
    \ }\nint popcount(long long t) { return __builtin_popcountll(t); }\nbool ispow2(int\
    \ i) { return i && (i & -i) == i; }\nlong long MSK(int n) { return (1LL << n)\
    \ - 1; }\n\ntemplate <class T> T ceil(T x, T y) {\n    assert(y >= 1);\n    return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <class T> T floor(T x, T y)\
    \ {\n    assert(y >= 1);\n    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\n\
    template <class T1, class T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T1, class T2> inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n  \
    \      a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <typename\
    \ T> void mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n}\ntemplate <typename T> int lwb(const vector<T>& v, const\
    \ T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }\n#pragma endregion\n\
    #line 5 \"modulo/modint.hpp\"\n\ntemplate <uint64_t Modulus> class modint {\n\
    \    using i64 = int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \n    static_assert(Modulus < static_cast<uint32_t>(1) << 31, \"Modulus must be\
    \ less than 2**31\");\n    static constexpr u32 mod = Modulus;\n    u32 v;\n\n\
    public:\n    constexpr modint(const i64 x = 0) noexcept : v(x < 0 ? mod - 1 -\
    \ (-(x + 1) % mod) : x % mod) {}\n    constexpr u32& val() noexcept { return v;\
    \ }\n    constexpr const u32& val() const noexcept { return v; }\n    constexpr\
    \ modint operator+(const modint& rhs) const noexcept { return modint(*this) +=\
    \ rhs; }\n    constexpr modint operator-(const modint& rhs) const noexcept { return\
    \ modint(*this) -= rhs; }\n    constexpr modint operator*(const modint& rhs) const\
    \ noexcept { return modint(*this) *= rhs; }\n    constexpr modint operator/(const\
    \ modint& rhs) const noexcept { return modint(*this) /= rhs; }\n    constexpr\
    \ modint& operator+=(const modint& rhs) noexcept {\n        v += rhs.v;\n    \
    \    if (v >= mod) v -= mod;\n        return *this;\n    }\n    constexpr modint&\
    \ operator-=(const modint& rhs) noexcept {\n        if (v < rhs.v) v += mod;\n\
    \        v -= rhs.v;\n        return *this;\n    }\n    constexpr modint& operator*=(const\
    \ modint& rhs) noexcept {\n        v = (u64)v * rhs.v % mod;\n        return *this;\n\
    \    }\n    constexpr modint& operator/=(const modint& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n    constexpr modint pow(long long n) const noexcept\
    \ {\n        assert(0 <= n);\n        modint self(*this), res(1);\n        while\
    \ (n > 0) {\n            if (n & 1) res *= self;\n            self *= self;\n\
    \            n >>= 1;\n        }\n        return res;\n    }\n    constexpr modint\
    \ inv() const noexcept {\n        assert(*this != 0);\n        return pow(mod\
    \ - 2);\n    }\n    constexpr modint& operator++() noexcept {\n        if (++v\
    \ == mod) v = 0;\n        return *this;\n    }\n    constexpr modint& operator--()\
    \ noexcept {\n        if (v == 0) v = mod;\n        return --v, *this;\n    }\n\
    \    constexpr modint operator++(int) noexcept {\n        modint t = *this;\n\
    \        return ++*this, t;\n    }\n    constexpr modint operator--(int) noexcept\
    \ {\n        modint t = *this;\n        return --*this, t;\n    }\n    constexpr\
    \ modint operator-() const noexcept { return modint(mod - v); }\n    template\
    \ <class T> friend constexpr modint operator+(T x, modint y) noexcept { return\
    \ modint(x) + y; }\n    template <class T> friend constexpr modint operator-(T\
    \ x, modint y) noexcept { return modint(x) - y; }\n    template <class T> friend\
    \ constexpr modint operator*(T x, modint y) noexcept { return modint(x) * y; }\n\
    \    template <class T> friend constexpr modint operator/(T x, modint y) noexcept\
    \ { return modint(x) / y; }\n    constexpr bool operator==(const modint& rhs)\
    \ const noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const modint&\
    \ rhs) const noexcept { return v != rhs.v; }\n    constexpr bool operator!() const\
    \ noexcept { return !v; }\n    friend std::istream& operator>>(std::istream& s,\
    \ modint& rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n\
    \        return s;\n    }\n    friend std::ostream& operator<<(std::ostream& s,\
    \ const modint& rhs) noexcept { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n\
    \ * @docs docs/modulo/modint.md\n */\n#line 4 \"linearalgebra/characteristic_polynomial.hpp\"\
    \n\ntemplate <typename T> std::vector<T> characteristic_polynomial(std::vector<std::vector<T>>\
    \ M) {\n    assert(M.empty() or M.size() == M[0].size());\n    int n = M.size();\n\
    \    // reduce M to upper Hessenberg form\n    for (int j = 0; j < n - 2; j++)\
    \ {\n        for (int i = j + 2; i < n; i++) {\n            if (M[i][j] != 0)\
    \ {\n                std::swap(M[j + 1], M[i]);\n                for (int k =\
    \ 0; k < n; k++) std::swap(M[k][j + 1], M[k][i]);\n                break;\n  \
    \          }\n        }\n        if (M[j + 1][j] == 0) continue;\n        auto\
    \ inv = T(1) / M[j + 1][j];\n        for (int i = j + 2; i < n; i++) {\n     \
    \       auto coef = M[i][j] * inv;\n            for (int k = j; k < n; k++) M[i][k]\
    \ -= coef * M[j + 1][k];\n            for (int k = 0; k < n; k++) M[k][j + 1]\
    \ += coef * M[k][i];\n        }\n    }\n\n    // compute the characteristic polynomial\
    \ of upper Hessenberg matrix M\n    std::vector<std::vector<T>> p(n + 1);\n  \
    \  p[0] = {T(1)};\n    for (int i = 0; i < n; i++) {\n        p[i + 1].resize(i\
    \ + 2);\n        for (int j = 0; j <= i; j++) {\n            p[i + 1][j + 1] +=\
    \ p[i][j];\n            p[i + 1][j] -= p[i][j] * M[i][i];\n        }\n       \
    \ T betas = 1;\n        for (int j = i - 1; j >= 0; j--) {\n            betas\
    \ *= M[j + 1][j];\n            T coef = -betas * M[j][i];\n            for (int\
    \ k = 0; k <= j; k++) p[i + 1][k] += coef * p[j][k];\n        }\n    }\n    return\
    \ p[n];\n}\n\n/**\n * @brief Characteristic Polynomial\n * @docs docs/linearalgebra/characteristic_polynomial.md\n\
    \ * @see https://arxiv.org/abs/1104.3769\n */\n#line 6 \"test/yosupo/characteristic_polynomial.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N;\n    cin >> N;\n    vector<vector<mint>> a(N, vector<mint>(N));\n\
    \    for (int i = 0; i < N; i++) {\n        for (int j = 0; j < N; j++) {\n  \
    \          cin >> a[i][j];\n        }\n    }\n\n    auto p = characteristic_polynomial(a);\n\
    \    for (int i = 0; i <= N; i++) cout << p[i] << (i == N ? '\\n' : ' ');\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/characteristic_polynomial\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../linearalgebra/characteristic_polynomial.hpp\"\n\nusing mint = modint<998244353>;\n\
    \nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\n\
    \    cin >> N;\n    vector<vector<mint>> a(N, vector<mint>(N));\n    for (int\
    \ i = 0; i < N; i++) {\n        for (int j = 0; j < N; j++) {\n            cin\
    \ >> a[i][j];\n        }\n    }\n\n    auto p = characteristic_polynomial(a);\n\
    \    for (int i = 0; i <= N; i++) cout << p[i] << (i == N ? '\\n' : ' ');\n  \
    \  return 0;\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - linearalgebra/characteristic_polynomial.hpp
  isVerificationFile: true
  path: test/yosupo/characteristic_polynomial.test.cpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/characteristic_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/characteristic_polynomial.test.cpp
- /verify/test/yosupo/characteristic_polynomial.test.cpp.html
title: test/yosupo/characteristic_polynomial.test.cpp
---