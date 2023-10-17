---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: "Formal Power Series\uFF08\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\uFF09"
  - icon: ':heavy_check_mark:'
    path: src/util/modint.hpp
    title: modint (input/output)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/FormalPowerSeries.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse\"\
    \n\n#include \"polynomial/FormalPowerSeries.hpp\"\n#include \"util/modint.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\nusing FPS = FormalPowerSeries<mint>;\n\
    \nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, K;\n    long long M;\n    std::cin >> N >> K >> M;\n    std::vector<std::pair<int,\
    \ mint>> f;\n    for (; K--;) {\n        int i, a;\n        std::cin >> i >> a;\n\
    \        f.emplace_back(i, a);\n    }\n\n    auto b = FPS::pow_sparse(f, M, N);\n\
    \    for (int i = 0; i < N; i++) std::cout << b[i] << (i + 1 == N ? '\\n' : '\
    \ ');\n}"
  dependsOn:
  - src/polynomial/FormalPowerSeries.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/pow_of_formal_power_series_sparse.test.cpp
  requiredBy: []
  timestamp: '2023-09-18 22:25:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/pow_of_formal_power_series_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/pow_of_formal_power_series_sparse.test.cpp
- /verify/test/yosupo/pow_of_formal_power_series_sparse.test.cpp.html
title: test/yosupo/pow_of_formal_power_series_sparse.test.cpp
---