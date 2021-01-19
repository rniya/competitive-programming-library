---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/geometry.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../geometry/geometry.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n; cin\
    \ >> n;\n    Polygon g(n); cin >> g;\n    cout << is_convex(g) << '\\n';\n}"
  dependsOn:
  - base.hpp
  - geometry/geometry.hpp
  isVerificationFile: true
  path: test/aoj/CGL_3_B.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_3_B.test.cpp
- /verify/test/aoj/CGL_3_B.test.cpp.html
title: test/aoj/CGL_3_B.test.cpp
---