---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/graph/BipartiteGraph.md
    document_title: "2\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/BipartiteGraph.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief 2\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\n * @docs docs/graph/BipartiteGraph.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct BipartiteGraph{\n \
    \   vector<vector<int>> G;\n    vector<int> color,root;\n    BipartiteGraph(int\
    \ n):G(n),color(n,-1),root(n,-1){}\n    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n    bool dfs(int v,int c,int r){\n    \
    \    color[v]=c; root[v]=r;\n        for (int u:G[v]){\n            if (color[u]==c)\
    \ return false;\n            if (color[u]<0&&!dfs(u,c^1,r)) return false;\n  \
    \      }\n        return true;\n    }\n    bool build(){\n        for (int v=0;v<G.size();++v){\n\
    \            if (color[v]<0&&!dfs(v,0,v)){\n                return false;\n  \
    \          }\n        }\n        return true;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/BipartiteGraph.hpp
  requiredBy: []
  timestamp: '2020-09-10 12:32:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/BipartiteGraph.hpp
layout: document
redirect_from:
- /library/graph/BipartiteGraph.hpp
- /library/graph/BipartiteGraph.hpp.html
title: "2\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---
## 概要

## 計算量