---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1678.test.cpp
    title: test/yukicoder/1678.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/PrimalDualonDAG.md
    document_title: Primal Dual on DAG
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"flow/PrimalDualonDAG.hpp\"\
    \n\n/**\n * @brief Primal Dual on DAG\n * @docs docs/flow/PrimalDualonDAG.md\n\
    \ */\ntemplate <typename Cap, typename Cost> struct PrimalDualonDAG {\n    const\
    \ Cost inf = numeric_limits<Cost>::max() / 2;\n    struct edge {\n        int\
    \ to;\n        Cap cap;\n        Cost cost;\n        int rev;\n        edge(int\
    \ to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}\n\
    \    };\n    vector<vector<edge>> G;\n    vector<pair<int, int>> pos;\n    vector<Cost>\
    \ h, dist;\n    vector<int> prevv, preve, indeg, ord;\n    PrimalDualonDAG(int\
    \ n) : G(n), h(n), dist(n), prevv(n), preve(n), indeg(n, 0) {}\n    int add_edge(int\
    \ from, int to, Cap cap, Cost cost) {\n        pos.emplace_back(from, G[from].size());\n\
    \        G[from].emplace_back(to, cap, cost, G[to].size());\n        G[to].emplace_back(from,\
    \ 0, -cost, G[from].size() - 1);\n        if (cap > 0) indeg[to]++;\n        return\
    \ pos.size() - 1;\n    }\n    tuple<int, int, Cap, Cap, Cost> get_edge(int i)\
    \ {\n        auto e = G[pos[i].first][pos[i].second];\n        auto re = G[e.to][e.rev];\n\
    \        return {pos[i].first, e.to, e.cap + re.cap, re.cap, e.cost};\n    }\n\
    \    vector<tuple<int, int, Cap, Cap, Cost>> edges() {\n        vector<tuple<int,\
    \ int, Cap, Cap, Cost>> res;\n        for (size_t i = 0; i < pos.size(); i++)\
    \ res.emplace_back(get_edge(i));\n        return res;\n    }\n    bool topological_sort()\
    \ {\n        queue<int> que;\n        for (size_t i = 0; i < G.size(); i++) {\n\
    \            if (indeg[i] == 0) {\n                que.emplace(i);\n         \
    \   }\n        }\n\n        while (!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            ord.emplace_back(v);\n            for (const\
    \ auto& e : G[v]) {\n                if (e.cap > 0 && --indeg[e.to] == 0) {\n\
    \                    que.emplace(e.to);\n                }\n            }\n  \
    \      }\n\n        return (*max_element(indeg.begin(), indeg.end()) == 0);\n\
    \    }\n    void calc_potential(int s) {\n        fill(h.begin(), h.end(), inf);\n\
    \        h[s] = 0;\n\n        for (int& v : ord) {\n            if (h[v] == inf)\
    \ continue;\n            for (const auto& e : G[v]) {\n                if (e.cap\
    \ > 0) {\n                    h[e.to] = min(h[e.to], h[v] + e.cost);\n       \
    \         }\n            }\n        }\n    }\n    void dijkstra(int s) {\n   \
    \     struct P {\n            Cost c;\n            int v;\n            P(Cost\
    \ c, int v) : c(c), v(v) {}\n            bool operator<(const P& rhs) const {\
    \ return c > rhs.c; }\n        };\n        priority_queue<P> pq;\n        fill(dist.begin(),\
    \ dist.end(), inf);\n        dist[s] = 0;\n        pq.emplace(dist[s], s);\n\n\
    \        while (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n\
    \            int v = p.v;\n            if (dist[v] < p.c) continue;\n        \
    \    for (size_t i = 0; i < G[v].size(); i++) {\n                auto& e = G[v][i];\n\
    \                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])\
    \ {\n                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];\n   \
    \                 prevv[e.to] = v;\n                    preve[e.to] = i;\n   \
    \                 pq.emplace(dist[e.to], e.to);\n                }\n         \
    \   }\n        }\n    }\n    vector<pair<Cap, Cost>> slope(int s, int t, Cap lim)\
    \ {\n        assert(topological_sort());\n        calc_potential(s);\n       \
    \ Cap f = 0;\n        Cost c = 0, pre = -1;\n        vector<pair<Cap, Cost>> res;\n\
    \        res.emplace_back(f, c);\n\n        while (f < lim) {\n            dijkstra(s);\n\
    \            if (dist[t] == inf) break;\n            for (size_t v = 0; v < G.size();\
    \ v++) h[v] = min(h[v] + dist[v], inf);\n            Cap d = lim - f;\n      \
    \      for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \            for (int v = t; v != s; v = prevv[v]) {\n                auto& e\
    \ = G[prevv[v]][preve[v]];\n                e.cap -= d;\n                G[v][e.rev].cap\
    \ += d;\n            }\n            f += d;\n            c += h[t] * d;\n    \
    \        if (pre == h[t]) res.pop_back();\n            res.emplace_back(f, c);\n\
    \            pre = c;\n        }\n\n        return res;\n    }\n    Cost min_cost_flow(int\
    \ s, int t, Cap f) {\n        auto res = slope(s, t, f).back();\n        return\
    \ res.first == f ? res.second : -1;\n    }\n    pair<Cap, Cost> min_cost_max_flow(int\
    \ s, int t) { return slope(s, t, numeric_limits<Cap>::max()).back(); }\n    vector<pair<Cap,\
    \ Cost>> min_cost_slope(int s, int t) { return slope(s, t, numeric_limits<Cap>::max());\
    \ }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Primal Dual on DAG\n\
    \ * @docs docs/flow/PrimalDualonDAG.md\n */\ntemplate <typename Cap, typename\
    \ Cost> struct PrimalDualonDAG {\n    const Cost inf = numeric_limits<Cost>::max()\
    \ / 2;\n    struct edge {\n        int to;\n        Cap cap;\n        Cost cost;\n\
    \        int rev;\n        edge(int to, Cap cap, Cost cost, int rev) : to(to),\
    \ cap(cap), cost(cost), rev(rev) {}\n    };\n    vector<vector<edge>> G;\n   \
    \ vector<pair<int, int>> pos;\n    vector<Cost> h, dist;\n    vector<int> prevv,\
    \ preve, indeg, ord;\n    PrimalDualonDAG(int n) : G(n), h(n), dist(n), prevv(n),\
    \ preve(n), indeg(n, 0) {}\n    int add_edge(int from, int to, Cap cap, Cost cost)\
    \ {\n        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, cost, G[to].size());\n        G[to].emplace_back(from, 0, -cost, G[from].size()\
    \ - 1);\n        if (cap > 0) indeg[to]++;\n        return pos.size() - 1;\n \
    \   }\n    tuple<int, int, Cap, Cap, Cost> get_edge(int i) {\n        auto e =\
    \ G[pos[i].first][pos[i].second];\n        auto re = G[e.to][e.rev];\n       \
    \ return {pos[i].first, e.to, e.cap + re.cap, re.cap, e.cost};\n    }\n    vector<tuple<int,\
    \ int, Cap, Cap, Cost>> edges() {\n        vector<tuple<int, int, Cap, Cap, Cost>>\
    \ res;\n        for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));\n\
    \        return res;\n    }\n    bool topological_sort() {\n        queue<int>\
    \ que;\n        for (size_t i = 0; i < G.size(); i++) {\n            if (indeg[i]\
    \ == 0) {\n                que.emplace(i);\n            }\n        }\n\n     \
    \   while (!que.empty()) {\n            int v = que.front();\n            que.pop();\n\
    \            ord.emplace_back(v);\n            for (const auto& e : G[v]) {\n\
    \                if (e.cap > 0 && --indeg[e.to] == 0) {\n                    que.emplace(e.to);\n\
    \                }\n            }\n        }\n\n        return (*max_element(indeg.begin(),\
    \ indeg.end()) == 0);\n    }\n    void calc_potential(int s) {\n        fill(h.begin(),\
    \ h.end(), inf);\n        h[s] = 0;\n\n        for (int& v : ord) {\n        \
    \    if (h[v] == inf) continue;\n            for (const auto& e : G[v]) {\n  \
    \              if (e.cap > 0) {\n                    h[e.to] = min(h[e.to], h[v]\
    \ + e.cost);\n                }\n            }\n        }\n    }\n    void dijkstra(int\
    \ s) {\n        struct P {\n            Cost c;\n            int v;\n        \
    \    P(Cost c, int v) : c(c), v(v) {}\n            bool operator<(const P& rhs)\
    \ const { return c > rhs.c; }\n        };\n        priority_queue<P> pq;\n   \
    \     fill(dist.begin(), dist.end(), inf);\n        dist[s] = 0;\n        pq.emplace(dist[s],\
    \ s);\n\n        while (!pq.empty()) {\n            auto p = pq.top();\n     \
    \       pq.pop();\n            int v = p.v;\n            if (dist[v] < p.c) continue;\n\
    \            for (size_t i = 0; i < G[v].size(); i++) {\n                auto&\
    \ e = G[v][i];\n                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost\
    \ + h[v] - h[e.to]) {\n                    dist[e.to] = dist[v] + e.cost + h[v]\
    \ - h[e.to];\n                    prevv[e.to] = v;\n                    preve[e.to]\
    \ = i;\n                    pq.emplace(dist[e.to], e.to);\n                }\n\
    \            }\n        }\n    }\n    vector<pair<Cap, Cost>> slope(int s, int\
    \ t, Cap lim) {\n        assert(topological_sort());\n        calc_potential(s);\n\
    \        Cap f = 0;\n        Cost c = 0, pre = -1;\n        vector<pair<Cap, Cost>>\
    \ res;\n        res.emplace_back(f, c);\n\n        while (f < lim) {\n       \
    \     dijkstra(s);\n            if (dist[t] == inf) break;\n            for (size_t\
    \ v = 0; v < G.size(); v++) h[v] = min(h[v] + dist[v], inf);\n            Cap\
    \ d = lim - f;\n            for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \            for (int v = t; v != s; v = prevv[v]) {\n                auto& e\
    \ = G[prevv[v]][preve[v]];\n                e.cap -= d;\n                G[v][e.rev].cap\
    \ += d;\n            }\n            f += d;\n            c += h[t] * d;\n    \
    \        if (pre == h[t]) res.pop_back();\n            res.emplace_back(f, c);\n\
    \            pre = c;\n        }\n\n        return res;\n    }\n    Cost min_cost_flow(int\
    \ s, int t, Cap f) {\n        auto res = slope(s, t, f).back();\n        return\
    \ res.first == f ? res.second : -1;\n    }\n    pair<Cap, Cost> min_cost_max_flow(int\
    \ s, int t) { return slope(s, t, numeric_limits<Cap>::max()).back(); }\n    vector<pair<Cap,\
    \ Cost>> min_cost_slope(int s, int t) { return slope(s, t, numeric_limits<Cap>::max());\
    \ }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/PrimalDualonDAG.hpp
  requiredBy: []
  timestamp: '2021-09-11 01:27:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1678.test.cpp
documentation_of: flow/PrimalDualonDAG.hpp
layout: document
redirect_from:
- /library/flow/PrimalDualonDAG.hpp
- /library/flow/PrimalDualonDAG.hpp.html
title: Primal Dual on DAG
---
## 概要

## 計算量

## 問題例
[AtCoder Beginner Contest 214 H - Collecting](https://atcoder.jp/contests/abc214/tasks/abc214_h)

## 参照
[負辺を含む最小費用流について(Attack the Moles) - sigma425のブログ](https://sigma425.hatenablog.com/entry/2014/10/12/122018?utm_source=pocket_mylist)