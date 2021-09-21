---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/util/binary_conversion.md
    document_title: "\u6587\u5B57\u5217\u306E2\u9032\u5909\u63DB"
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"util/binary_conversion.hpp\"\
    \n\n/**\n * @brief \u6587\u5B57\u5217\u306E2\u9032\u5909\u63DB\n * @docs docs/util/binary_conversion.md\n\
    \ */\n\nvector<bool> binary_conversion(const string& s) {\n    using u64 = uint64_t;\n\
    \n    vector<u64> num(s.size() / 9 + 10, 0);\n    for (size_t i = 0; i < s.size();\
    \ i += 9) {\n        const string t = s.substr(i, 9);\n        u64 add = 0, mul\
    \ = 1;\n        for (const auto c : t) {\n            add = add * 10 + (c - '0');\n\
    \            mul *= 10;\n        }\n        for (auto& d : num) {\n          \
    \  d = d * mul + add;\n            add = d >> 32;\n            d -= add << 32;\n\
    \        }\n    }\n\n    vector<bool> res(num.size() * 32);\n    for (size_t i\
    \ = 0; i < num.size(); i++) {\n        for (size_t j = 0; j < 32; j++) {\n   \
    \         res[i * 32 + j] = num[i] >> j & 1;\n        }\n    }\n\n    while (!res.empty()\
    \ && !res.back()) res.pop_back();\n    return res;\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u6587\u5B57\u5217\
    \u306E2\u9032\u5909\u63DB\n * @docs docs/util/binary_conversion.md\n */\n\nvector<bool>\
    \ binary_conversion(const string& s) {\n    using u64 = uint64_t;\n\n    vector<u64>\
    \ num(s.size() / 9 + 10, 0);\n    for (size_t i = 0; i < s.size(); i += 9) {\n\
    \        const string t = s.substr(i, 9);\n        u64 add = 0, mul = 1;\n   \
    \     for (const auto c : t) {\n            add = add * 10 + (c - '0');\n    \
    \        mul *= 10;\n        }\n        for (auto& d : num) {\n            d =\
    \ d * mul + add;\n            add = d >> 32;\n            d -= add << 32;\n  \
    \      }\n    }\n\n    vector<bool> res(num.size() * 32);\n    for (size_t i =\
    \ 0; i < num.size(); i++) {\n        for (size_t j = 0; j < 32; j++) {\n     \
    \       res[i * 32 + j] = num[i] >> j & 1;\n        }\n    }\n\n    while (!res.empty()\
    \ && !res.back()) res.pop_back();\n    return res;\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: util/binary_conversion.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/binary_conversion.hpp
layout: document
redirect_from:
- /library/util/binary_conversion.hpp
- /library/util/binary_conversion.hpp.html
title: "\u6587\u5B57\u5217\u306E2\u9032\u5909\u63DB"
---
## 概要
文字列を2進法に変換する.

## 問題例
[Codeforces Round #285 (Div. 1) D. Misha and XOR](https://codeforces.com/contest/504/problem/D)

## 参照
https://twitter.com/noshi91/status/1324274752228192257