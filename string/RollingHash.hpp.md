---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1370.test.cpp
    title: test/aoj/1370.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  - icon: ':x:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/string/RollingHash.md
    document_title: Rolling Hash
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/RollingHash.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Rolling Hash\n * @docs docs/string/RollingHash.md\n */\n\n\
    #pragma once\n\n#include \"../base.hpp\"\n\nclass RollingHash{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    static const u64 mod=(1ULL<<61)-1;\n    const\
    \ u64 base;\n    vector<u64> hash,power;\n    static inline u64 add(u64 a,u64\
    \ b){\n        if ((a+=b)>=mod) a-=mod;\n        return a;\n    }\n    static\
    \ inline u64 mul(u64 a,u64 b){\n        u128 c=(u128)a*b;\n        return add(c>>61,c&mod);\n\
    \    }\n\npublic:\n    static inline u64 generate_base(){\n        mt19937_64\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n        uniform_int_distribution<u64>\
    \ rand(2,RollingHash::mod-1);\n        return rand(mt);\n    }\n    RollingHash(u64\
    \ base=generate_base()):base(base){}\n    template<typename T>\n    RollingHash(const\
    \ T &s,u64 base=generate_base()):base(base){\n        int n=s.size();\n      \
    \  hash.assign(n+1,0);\n        power.assign(n+1,0);\n        power[0]=1;\n  \
    \      for (int i=0;i<n;++i){\n            hash[i+1]=add(mul(hash[i],base),s[i]);\n\
    \            power[i+1]=mul(power[i],base);\n        }\n    }\n    u64 query(int\
    \ l,int r) const {\n        return add(hash[r],mod-mul(hash[l],power[r-l]));\n\
    \    }\n    int lcp(int a,int b) const {\n        int len=min(hash.size()-a,hash.size()-b);\n\
    \        int lb=0,ub=len;\n        while (ub-lb>1){\n            int mid=(lb+ub)>>1;\n\
    \            (query(a,a+mid)==query(b,b+mid)?lb:ub)=mid;\n        }\n        return\
    \ lb;\n    }\n    template<typename T>\n    u64 get(const T &t){\n        u64\
    \ res=0;\n        for (int i=0;i<t.size();++i) res=add(mul(res,base),t[i]);\n\
    \        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/RollingHash.hpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/ALDS1_14_B.test.cpp
  - test/aoj/1370.test.cpp
  - test/yukicoder/430.test.cpp
documentation_of: string/RollingHash.hpp
layout: document
redirect_from:
- /library/string/RollingHash.hpp
- /library/string/RollingHash.hpp.html
title: Rolling Hash
---
## 概要
$\bmod 2^{61}-1$で基数は$\left[2,2^{61}-1\right)$の乱数によるRolling Hash.
- `generate_base()`：基数を生成する. 2つ以上の文字列に対しては同じ基数を用いねばならないので注意.
- `query(l,r)`：$[l,r)$のhash値を返す.
- `lcp(a,b)`：$a$文字目を$b$文字目を始点としたLongest Common Prefixの長さを返す.
- `get(t)`：文字列$t$のhash値を返す.

## 計算量
- `generate_base()`：$O(1)$
- `query(l,r)`：$O(1)$
- `lcp(a,b)`；$O(\log n)$
- `get(t)`：$O(|t|)$

## 問題例
[Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 1) C. Morse Code](https://codeforces.com/contest/1129/problem/C) $\bmod$の値が小さいとかなりの確率で衝突し, hash値を2つもとうとするとTLEにハマるので, このRolling Hashが有効.

## 参照
[安全で爆速なRollingHashの話 - Qiita](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)