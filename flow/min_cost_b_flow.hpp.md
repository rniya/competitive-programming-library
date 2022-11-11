---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/min_cost_b_flow.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n#line 1 \"atcoder/mincostflow.hpp\"\
    \n\n\n\n#line 6 \"atcoder/mincostflow.hpp\"\n#include <limits>\n#include <queue>\n\
    #line 9 \"atcoder/mincostflow.hpp\"\n\n#line 1 \"atcoder/internal_csr.hpp\"\n\n\
    \n\n#line 7 \"atcoder/internal_csr.hpp\"\n\nnamespace atcoder {\nnamespace internal\
    \ {\n\ntemplate <class E> struct csr {\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)\n\
    \        : start(n + 1), elist(edges.size()) {\n        for (auto e : edges) {\n\
    \            start[e.first + 1]++;\n        }\n        for (int i = 1; i <= n;\
    \ i++) {\n            start[i] += start[i - 1];\n        }\n        auto counter\
    \ = start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n#line 1 \"atcoder/internal_queue.hpp\"\n\n\n\n#line 5 \"atcoder/internal_queue.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class T> struct simple_queue\
    \ {\n    std::vector<T> payload;\n    int pos = 0;\n    void reserve(int n) {\
    \ payload.reserve(n); }\n    int size() const { return int(payload.size()) - pos;\
    \ }\n    bool empty() const { return pos == int(payload.size()); }\n    void push(const\
    \ T& t) { payload.push_back(t); }\n    T& front() { return payload[pos]; }\n \
    \   void clear() {\n        payload.clear();\n        pos = 0;\n    }\n    void\
    \ pop() { pos++; }\n};\n\n}  // namespace internal\n\n}  // namespace atcoder\n\
    \n\n#line 12 \"atcoder/mincostflow.hpp\"\n\nnamespace atcoder {\n\ntemplate <class\
    \ Cap, class Cost> struct mcf_graph {\n  public:\n    mcf_graph() {}\n    explicit\
    \ mcf_graph(int n) : _n(n) {}\n\n    int add_edge(int from, int to, Cap cap, Cost\
    \ cost) {\n        assert(0 <= from && from < _n);\n        assert(0 <= to &&\
    \ to < _n);\n        assert(0 <= cap);\n        assert(0 <= cost);\n        int\
    \ m = int(_edges.size());\n        _edges.push_back({from, to, cap, 0, cost});\n\
    \        return m;\n    }\n\n    struct edge {\n        int from, to;\n      \
    \  Cap cap, flow;\n        Cost cost;\n    };\n\n    edge get_edge(int i) {\n\
    \        int m = int(_edges.size());\n        assert(0 <= i && i < m);\n     \
    \   return _edges[i];\n    }\n    std::vector<edge> edges() { return _edges; }\n\
    \n    std::pair<Cap, Cost> flow(int s, int t) {\n        return flow(s, t, std::numeric_limits<Cap>::max());\n\
    \    }\n    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {\n      \
    \  return slope(s, t, flow_limit).back();\n    }\n    std::vector<std::pair<Cap,\
    \ Cost>> slope(int s, int t) {\n        return slope(s, t, std::numeric_limits<Cap>::max());\n\
    \    }\n    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit)\
    \ {\n        assert(0 <= s && s < _n);\n        assert(0 <= t && t < _n);\n  \
    \      assert(s != t);\n\n        int m = int(_edges.size());\n        std::vector<int>\
    \ edge_idx(m);\n\n        auto g = [&]() {\n            std::vector<int> degree(_n),\
    \ redge_idx(m);\n            std::vector<std::pair<int, _edge>> elist;\n     \
    \       elist.reserve(2 * m);\n            for (int i = 0; i < m; i++) {\n   \
    \             auto e = _edges[i];\n                edge_idx[i] = degree[e.from]++;\n\
    \                redge_idx[i] = degree[e.to]++;\n                elist.push_back({e.from,\
    \ {e.to, -1, e.cap - e.flow, e.cost}});\n                elist.push_back({e.to,\
    \ {e.from, -1, e.flow, -e.cost}});\n            }\n            auto _g = internal::csr<_edge>(_n,\
    \ elist);\n            for (int i = 0; i < m; i++) {\n                auto e =\
    \ _edges[i];\n                edge_idx[i] += _g.start[e.from];\n             \
    \   redge_idx[i] += _g.start[e.to];\n                _g.elist[edge_idx[i]].rev\
    \ = redge_idx[i];\n                _g.elist[redge_idx[i]].rev = edge_idx[i];\n\
    \            }\n            return _g;\n        }();\n\n        auto result =\
    \ slope(g, s, t, flow_limit);\n\n        for (int i = 0; i < m; i++) {\n     \
    \       auto e = g.elist[edge_idx[i]];\n            _edges[i].flow = _edges[i].cap\
    \ - e.cap;\n        }\n\n        return result;\n    }\n\n  private:\n    int\
    \ _n;\n    std::vector<edge> _edges;\n\n    // inside edge\n    struct _edge {\n\
    \        int to, rev;\n        Cap cap;\n        Cost cost;\n    };\n\n    std::vector<std::pair<Cap,\
    \ Cost>> slope(internal::csr<_edge>& g,\n                                    \
    \        int s,\n                                            int t,\n        \
    \                                    Cap flow_limit) {\n        // variants (C\
    \ = maxcost):\n        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0\n     \
    \   // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge\n\
    \n        // dual_dist[i] = (dual[i], dist[i])\n        std::vector<std::pair<Cost,\
    \ Cost>> dual_dist(_n);\n        std::vector<int> prev_e(_n);\n        std::vector<bool>\
    \ vis(_n);\n        struct Q {\n            Cost key;\n            int to;\n \
    \           bool operator<(Q r) const { return key > r.key; }\n        };\n  \
    \      std::vector<int> que_min;\n        std::vector<Q> que;\n        auto dual_ref\
    \ = [&]() {\n            for (int i = 0; i < _n; i++) {\n                dual_dist[i].second\
    \ = std::numeric_limits<Cost>::max();\n            }\n            std::fill(vis.begin(),\
    \ vis.end(), false);\n            que_min.clear();\n            que.clear();\n\
    \n            // que[0..heap_r) was heapified\n            size_t heap_r = 0;\n\
    \n            dual_dist[s].second = 0;\n            que_min.push_back(s);\n  \
    \          while (!que_min.empty() || !que.empty()) {\n                int v;\n\
    \                if (!que_min.empty()) {\n                    v = que_min.back();\n\
    \                    que_min.pop_back();\n                } else {\n         \
    \           while (heap_r < que.size()) {\n                        heap_r++;\n\
    \                        std::push_heap(que.begin(), que.begin() + heap_r);\n\
    \                    }\n                    v = que.front().to;\n            \
    \        std::pop_heap(que.begin(), que.end());\n                    que.pop_back();\n\
    \                    heap_r--;\n                }\n                if (vis[v])\
    \ continue;\n                vis[v] = true;\n                if (v == t) break;\n\
    \                // dist[v] = shortest(s, v) + dual[s] - dual[v]\n           \
    \     // dist[v] >= 0 (all reduced cost are positive)\n                // dist[v]\
    \ <= (n-1)C\n                Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;\n\
    \                for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n       \
    \             auto e = g.elist[i];\n                    if (!e.cap) continue;\n\
    \                    // |-dual[e.to] + dual[v]| <= (n-1)C\n                  \
    \  // cost <= C - -(n-1)C + 0 = nC\n                    Cost cost = e.cost - dual_dist[e.to].first\
    \ + dual_v;\n                    if (dual_dist[e.to].second - dist_v > cost) {\n\
    \                        Cost dist_to = dist_v + cost;\n                     \
    \   dual_dist[e.to].second = dist_to;\n                        prev_e[e.to] =\
    \ e.rev;\n                        if (dist_to == dist_v) {\n                 \
    \           que_min.push_back(e.to);\n                        } else {\n     \
    \                       que.push_back(Q{dist_to, e.to});\n                   \
    \     }\n                    }\n                }\n            }\n           \
    \ if (!vis[t]) {\n                return false;\n            }\n\n           \
    \ for (int v = 0; v < _n; v++) {\n                if (!vis[v]) continue;\n   \
    \             // dual[v] = dual[v] - dist[t] + dist[v]\n                //   \
    \      = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n                //\
    \         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,\n             \
    \   //         t) + dual[t] + shortest(s, v) = shortest(s, v) -\n            \
    \    //         shortest(s, t) >= 0 - (n-1)C\n                dual_dist[v].first\
    \ -= dual_dist[t].second - dual_dist[v].second;\n            }\n            return\
    \ true;\n        };\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n        std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \        while (flow < flow_limit) {\n            if (!dual_ref()) break;\n  \
    \          Cap c = flow_limit - flow;\n            for (int v = t; v != s; v =\
    \ g.elist[prev_e[v]].to) {\n                c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n\
    \            }\n            for (int v = t; v != s; v = g.elist[prev_e[v]].to)\
    \ {\n                auto& e = g.elist[prev_e[v]];\n                e.cap += c;\n\
    \                g.elist[e.rev].cap -= c;\n            }\n            Cost d =\
    \ -dual_dist[s].first;\n            flow += c;\n            cost += c * d;\n \
    \           if (prev_cost_per_flow == d) {\n                result.pop_back();\n\
    \            }\n            result.push_back({flow, cost});\n            prev_cost_per_flow\
    \ = d;\n        }\n        return result;\n    }\n};\n\n}  // namespace atcoder\n\
    \n\n#line 7 \"flow/min_cost_b_flow.hpp\"\n\ntemplate <class Cap, class Cost> struct\
    \ min_cost_b_flow {\n    min_cost_b_flow() {}\n    explicit min_cost_b_flow(int\
    \ n) : n(n), graph(n + 2), b(n), sum(Cost{}) {}\n\n    int add_edge(int from,\
    \ int to, Cap lower, Cap upper, Cost cost) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        assert(lower <= upper);\n\
    \        if (cost < 0) {\n            std::swap(from, to);\n            std::swap(lower,\
    \ upper);\n            lower *= -1;\n            upper *= -1;\n            cost\
    \ *= -1;\n        }\n        b[from] -= lower;\n        b[to] += lower;\n    \
    \    sum += cost * lower;\n        return graph.add_edge(from, to, upper - lower,\
    \ cost);\n    }\n\n    void add_supply(int v, Cap x) {\n        assert(0 <= v\
    \ and v < n);\n        b[v] += x;\n    }\n\n    void add_demand(int v, Cap x)\
    \ {\n        assert(0 <= v and v < n);\n        b[v] -= x;\n    }\n\n    std::pair<bool,\
    \ Cost> flow() {\n        int source = n, sink = source + 1;\n        Cap positive{},\
    \ negative{};\n        for (int v = 0; v < n; v++) {\n            if (b[v] > 0)\
    \ {\n                graph.add_edge(source, v, b[v], 0);\n                positive\
    \ += b[v];\n            } else if (b[v] < 0) {\n                graph.add_edge(v,\
    \ sink, -b[v], 0);\n                negative += -b[v];\n            }\n      \
    \  }\n        if (positive != negative) return make_pair(false, Cost{});\n   \
    \     auto res = graph.flow(source, sink);\n        Cap flow = res.first;\n  \
    \      Cost cost = res.second;\n        if (flow < positive) return make_pair(false,\
    \ Cost{});\n        return make_pair(true, sum + cost);\n    }\n\nprivate:\n \
    \   int n;\n    atcoder::mcf_graph<Cap, Cost> graph;\n    std::vector<Cap> b;\n\
    \    Cost sum;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#include \"atcoder/mincostflow\"\n\ntemplate <class Cap, class\
    \ Cost> struct min_cost_b_flow {\n    min_cost_b_flow() {}\n    explicit min_cost_b_flow(int\
    \ n) : n(n), graph(n + 2), b(n), sum(Cost{}) {}\n\n    int add_edge(int from,\
    \ int to, Cap lower, Cap upper, Cost cost) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        assert(lower <= upper);\n\
    \        if (cost < 0) {\n            std::swap(from, to);\n            std::swap(lower,\
    \ upper);\n            lower *= -1;\n            upper *= -1;\n            cost\
    \ *= -1;\n        }\n        b[from] -= lower;\n        b[to] += lower;\n    \
    \    sum += cost * lower;\n        return graph.add_edge(from, to, upper - lower,\
    \ cost);\n    }\n\n    void add_supply(int v, Cap x) {\n        assert(0 <= v\
    \ and v < n);\n        b[v] += x;\n    }\n\n    void add_demand(int v, Cap x)\
    \ {\n        assert(0 <= v and v < n);\n        b[v] -= x;\n    }\n\n    std::pair<bool,\
    \ Cost> flow() {\n        int source = n, sink = source + 1;\n        Cap positive{},\
    \ negative{};\n        for (int v = 0; v < n; v++) {\n            if (b[v] > 0)\
    \ {\n                graph.add_edge(source, v, b[v], 0);\n                positive\
    \ += b[v];\n            } else if (b[v] < 0) {\n                graph.add_edge(v,\
    \ sink, -b[v], 0);\n                negative += -b[v];\n            }\n      \
    \  }\n        if (positive != negative) return make_pair(false, Cost{});\n   \
    \     auto res = graph.flow(source, sink);\n        Cap flow = res.first;\n  \
    \      Cost cost = res.second;\n        if (flow < positive) return make_pair(false,\
    \ Cost{});\n        return make_pair(true, sum + cost);\n    }\n\nprivate:\n \
    \   int n;\n    atcoder::mcf_graph<Cap, Cost> graph;\n    std::vector<Cap> b;\n\
    \    Cost sum;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/min_cost_b_flow.hpp
  requiredBy: []
  timestamp: '2022-10-23 23:11:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/min_cost_b_flow.hpp
layout: document
title: Minimum Cost b-flow
---

## 概要
Minimum Cost b-flow を解くための補助ライブラリ．
この考え方に従うと容量下限や負のコストの辺が存在するような最小費用流のグラフを簡単に構成できる．

## 双対問題

## 問題例
- [AtCoder Regular Contest 137 E - Bakery](https://atcoder.jp/contests/arc137/tasks/arc137_e)