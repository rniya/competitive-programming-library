---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: combinatorics/BellNumber.hpp
    title: "\u30D9\u30EB\u6570"
  - icon: ':question:'
    path: combinatorics/combination.hpp
    title: combination
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ combinatorics/combination.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../combinatorics/combination.hpp\"\n#include \"../../combinatorics/BellNumber.hpp\"\
    \n\nusing mint=modint<1000000007>;\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int n,k; cin >> n >> k;\n\n    cout << bell_number<mint>(n,k) << '\\n';\n\
    }"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - combinatorics/combination.hpp
  - combinatorics/BellNumber.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_G.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_5_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_G.test.cpp
- /verify/test/aoj/DPL_5_G.test.cpp.html
title: test/aoj/DPL_5_G.test.cpp
---