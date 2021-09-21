---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryIndexedTree.hpp
    title: Binary Indexd Tree (Fenwick Tree)
  - icon: ':heavy_check_mark:'
    path: tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 2 \"base.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#pragma region Macros\ntypedef\
    \ long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef\
    \ unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n     \
    \   os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();)\
    \ {\n        os << '(' << itr->first << ',' << itr->second << ')';\n        if\
    \ (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n  \
    \      os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&, const T&)\
    \ {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 4 \"datastructure/BinaryIndexedTree.hpp\"\
    \n\ntemplate <typename T> struct BinaryIndexedTree {\n    BinaryIndexedTree(int\
    \ n) : n(n), data(n) {}\n\n    void add(int k, T x) {\n        assert(0 <= k &&\
    \ k < n);\n        for (k++; k <= n; k += k & -k) data[k - 1] += x;\n    }\n\n\
    \    T query(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        return sum(r) - sum(l);\n    }\n\n    T operator[](int i) const { return\
    \ query(i, i + 1); }\n\n    int lower_bound(T x) const {\n        if (x <= 0)\
    \ return 0;\n        int cur = 0, k = 1;\n        while (k < n) k <<= 1;\n   \
    \     for (; k > 0; k >>= 1) {\n            if (cur + k <= n && data[cur + k -\
    \ 1] < x) {\n                x -= data[cur + k - 1];\n                cur += k;\n\
    \            }\n        }\n        return cur;\n    }\n    int upper_bound(T x)\
    \ const { return lower_bound(x + 1); }\n\nprivate:\n    int n;\n    std::vector<T>\
    \ data;\n\n    T sum(int r) const {\n        T res = 0;\n        for (; r > 0;\
    \ r -= r & -r) res += data[r - 1];\n        return res;\n    }\n};\n\n/**\n *\
    \ @brief Binary Indexd Tree (Fenwick Tree)\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */\n#line 5 \"tree/HeavyLightDecomposition.hpp\"\n\nstruct HeavyLightDecomposition\
    \ {\n    HeavyLightDecomposition(int n)\n        : n(n), time(0), G(n), par(n,\
    \ -1), sub(n), dep(n, 0), head(n), tree_id(n, -1), vertex_id(n, -1) {}\n    void\
    \ add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    void build(std::vector<int> roots = {0}) {\n        int tree_id_cur\
    \ = 0;\n        for (int& r : roots) {\n            assert(0 <= r && r < n);\n\
    \            dfs_sz(r);\n            head[r] = r;\n            dfs_hld(r, tree_id_cur++);\n\
    \        }\n    }\n\n    int idx(int v) const { return vertex_id[v]; }\n\n   \
    \ int lca(int u, int v) const {\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n        for (;;\
    \ v = par[head[v]]) {\n            if (vertex_id[u] > vertex_id[v]) std::swap(u,\
    \ v);\n            if (head[u] == head[v]) return u;\n        }\n    }\n\n   \
    \ int distance(int u, int v) const {\n        assert(0 <= u && u < n);\n     \
    \   assert(0 <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n    \
    \    return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n    template <typename\
    \ F> void query_path(int u, int v, const F& f, bool vertex = false) const {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u]\
    \ == tree_id[v]);\n        int p = lca(u, v);\n        for (auto& e : ascend(u,\
    \ p)) f(e.second, e.first + 1);\n        if (vertex) f(vertex_id[p], vertex_id[p]\
    \ + 1);\n        for (auto& e : descend(p, v)) f(e.first, e.second + 1);\n   \
    \ }\n\n    template <typename F> void query_path_noncommutative(int u, int v,\
    \ const F& f, bool vertex = false) const {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n\
    \        int p = lca(u, v);\n        for (auto& e : ascend(u, p)) f(e.first +\
    \ 1, e.second);\n        if (vertex) f(vertex_id[p], vertex_id[p] + 1);\n    \
    \    for (auto& e : descend(p, v)) f(e.first, e.second + 1);\n    }\n\n    template\
    \ <typename F> void query_subtree(int u, const F& f, bool vertex = false) const\
    \ {\n        assert(0 <= u && u < n);\n        f(vertex_id[u] + !vertex, vertex_id[u]\
    \ + sub[u]);\n    }\n\nprivate:\n    int n, time;\n    std::vector<std::vector<int>>\
    \ G;  // child of vertex v on heavy edge is G[v].front() if it is not parent of\
    \ v\n    std::vector<int> par              // parent of vertex v\n        ,\n\
    \        sub  // size of subtree whose root is v\n        ,\n        dep  // distance\
    \ bitween root and vertex v\n        ,\n        head  // vertex that is the nearest\
    \ to root on heavy path of vertex v\n        ,\n        tree_id  // id of tree\
    \ vertex v belongs to\n        ,\n        vertex_id;  // id of vertex v (consecutive\
    \ on heavy paths)\n\n    void dfs_sz(int v) {\n        sub[v] = 1;\n        if\
    \ (!G[v].empty() && G[v].front() == par[v]) std::swap(G[v].front(), G[v].back());\n\
    \        for (int& u : G[v]) {\n            if (u == par[v]) continue;\n     \
    \       par[u] = v;\n            dep[u] = dep[v] + 1;\n            dfs_sz(u);\n\
    \            sub[v] += sub[u];\n            if (sub[u] > sub[G[v].front()]) std::swap(u,\
    \ G[v].front());\n        }\n    }\n\n    void dfs_hld(int v, int tree_id_cur)\
    \ {\n        vertex_id[v] = time++;\n        tree_id[v] = tree_id_cur;\n     \
    \   for (int& u : G[v]) {\n            if (u == par[v]) continue;\n          \
    \  head[u] = (u == G[v][0] ? head[v] : u);\n            dfs_hld(u, tree_id_cur);\n\
    \        }\n    }\n\n    std::vector<std::pair<int, int>> ascend(int u, int v)\
    \ const {  // [u, v), v is ancestor of u\n        std::vector<std::pair<int, int>>\
    \ res;\n        while (head[u] != head[v]) {\n            res.emplace_back(vertex_id[u],\
    \ vertex_id[head[u]]);\n            u = par[head[u]];\n        }\n        if (u\
    \ != v) res.emplace_back(vertex_id[u], vertex_id[v] + 1);\n        return res;\n\
    \    }\n\n    std::vector<std::pair<int, int>> descend(int u, int v) const { \
    \ // (u, v], u is ancestor of v\n        if (u == v) return {};\n        if (head[u]\
    \ == head[v]) return {{vertex_id[u] + 1, vertex_id[v]}};\n        auto res = descend(u,\
    \ par[head[v]]);\n        res.emplace_back(vertex_id[head[v]], vertex_id[v]);\n\
    \        return res;\n    }\n};\n\n/**\n * @brief Heavy Light Decomposition\n\
    \ * @docs docs/tree/HeavyLightDecomposition.md\n */\n#line 6 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n    for (int i = 0; i < N; i++)\
    \ cin >> a[i];\n\n    HeavyLightDecomposition HLD(N);\n    for (int i = 1; i <\
    \ N; i++) {\n        int p;\n        cin >> p;\n        HLD.add_edge(p, i);\n\
    \    }\n    HLD.build();\n\n    BinaryIndexedTree<long long> BIT(N);\n    for\
    \ (int i = 0; i < N; i++) BIT.add(HLD.idx(i), a[i]);\n\n    for (; Q--;) {\n \
    \       int t, u;\n        cin >> t >> u;\n        if (!t) {\n            int\
    \ x;\n            cin >> x;\n            BIT.add(HLD.idx(u), x);\n        } else\
    \ {\n            long long ans = 0;\n            auto q = [&](int l, int r) {\
    \ ans += BIT.query(l, r); };\n            HLD.query_subtree(u, q, true);\n   \
    \         cout << ans << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/BinaryIndexedTree.hpp\"\
    \n#include \"../../tree/HeavyLightDecomposition.hpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int>\
    \ a(N);\n    for (int i = 0; i < N; i++) cin >> a[i];\n\n    HeavyLightDecomposition\
    \ HLD(N);\n    for (int i = 1; i < N; i++) {\n        int p;\n        cin >> p;\n\
    \        HLD.add_edge(p, i);\n    }\n    HLD.build();\n\n    BinaryIndexedTree<long\
    \ long> BIT(N);\n    for (int i = 0; i < N; i++) BIT.add(HLD.idx(i), a[i]);\n\n\
    \    for (; Q--;) {\n        int t, u;\n        cin >> t >> u;\n        if (!t)\
    \ {\n            int x;\n            cin >> x;\n            BIT.add(HLD.idx(u),\
    \ x);\n        } else {\n            long long ans = 0;\n            auto q =\
    \ [&](int l, int r) { ans += BIT.query(l, r); };\n            HLD.query_subtree(u,\
    \ q, true);\n            cout << ans << '\\n';\n        }\n    }\n    return 0;\n\
    }"
  dependsOn:
  - base.hpp
  - datastructure/BinaryIndexedTree.hpp
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2021-09-21 22:39:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.test.cpp
---