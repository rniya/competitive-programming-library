---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/ConvexHullTrick.hpp
    title: Convex Hull Trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links:
    - https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/ConvexHullTrick.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/ConvexHullTrick.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\
    \ cin >> N;\n    vector<long long> a(N);\n    for (int i=0;i<N;++i) cin >> a[i];\n\
    \n    ConvexHullTrick<long long> CHT;\n\n    for (long long i=0;i<N;++i) CHT.add(-2*i,a[i]+i*i);\n\
    \    for (long long i=0;i<N;++i) cout << CHT.query_monotone_inc(i)+i*i << '\\\
    n';\n}"
  dependsOn:
  - base.hpp
  - datastructure/ConvexHullTrick.hpp
  isVerificationFile: false
  path: test/atcoder/colopl2018_final_c.cpp
  requiredBy: []
  timestamp: '2020-09-19 23:47:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/colopl2018_final_c.cpp
layout: document
redirect_from:
- /library/test/atcoder/colopl2018_final_c.cpp
- /library/test/atcoder/colopl2018_final_c.cpp.html
title: test/atcoder/colopl2018_final_c.cpp
---