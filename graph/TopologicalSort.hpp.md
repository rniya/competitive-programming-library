---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_4_B.test.cpp
    title: test/aoj/GRL_4_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/TopologicalSort.md
    document_title: Topological Sort
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/TopologicalSort.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Topological Sort\n * @docs docs/graph/TopologicalSort.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct TopologicalSort{\n\
    \    vector<vector<int>> G;\n    vector<int> seen,order;\n    TopologicalSort(int\
    \ n):G(n),seen(n){}\n    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n\
    \    }\n    void dfs(int v){\n        seen[v]=1;\n        for (int u:G[v]){\n\
    \            if (!seen[u]) dfs(u);\n        }\n        order.emplace_back(v);\n\
    \    }\n    vector<int> build(){\n        for (int i=0;i<G.size();++i){\n    \
    \        if (!seen[i]) dfs(i);\n        }\n        reverse(order.begin(),order.end());\n\
    \        return order;\n    }\n    int operator[](int i){return order[i];}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/TopologicalSort.hpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_4_B.test.cpp
documentation_of: graph/TopologicalSort.hpp
layout: document
redirect_from:
- /library/graph/TopologicalSort.hpp
- /library/graph/TopologicalSort.hpp.html
title: Topological Sort
---
## 概要

## 計算量