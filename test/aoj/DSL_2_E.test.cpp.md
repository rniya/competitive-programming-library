---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/LazySegmentTree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/LazySegmentTree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/LazySegmentTree.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,q;\
    \ cin >> n >> q;\n\n    auto f=[](int a,int b){return a+b;};\n    LazySegmentTree<int,int>\
    \ seg(n,f,f,f,0,0);\n\n    for (;q--;){\n        int c,s,t,x,i; cin >> c;\n  \
    \      if (!c){\n            cin >> s >> t >> x;\n            seg.update(s-1,t,x);\n\
    \        } else {\n            cin >> i;\n            cout << seg[i-1] << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_E.test.cpp
- /verify/test/aoj/DSL_2_E.test.cpp.html
title: test/aoj/DSL_2_E.test.cpp
---