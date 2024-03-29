---
title: Union Find (Disjoint Set Union)
documentation_of: ./UnionFind.hpp
---

## 概要
各集合をその集合内の代表元によって特徴づけることで素集合を扱うデータ構造．
主に頂点 $x, y$ の属する集合のマージやそれらが同一の集合に属しているかの判定を均し $O(\alpha(n))$ で行うことができる．
ここで，$\alpha(n)$ は Ackermann 関数 $A(n, n)$ の逆関数である．

| メンバ関数     | 効果                                         | 時間計算量          |
| -------------- | -------------------------------------------- | ------------------- |
| `UnionFind(n)` | 要素数 $n$ で初期化する．                    | $O(n)$              |
| `find(x)`      | 頂点 $x$ の属する集合の代表元を返す．        | 均し $O(\alpha(n))$ |
| `merge(x, y)`  | 頂点 $x, y$ が属する集合を併合する．         | 均し $O(\alpha(n))$ |
| `same(x, y)`   | 頂点 $x, y$ が同一の集合に属するか判定する． | 均し $O(\alpha(n))$ |
| `size(x)`      | 頂点 $x$ が属する集合の要素数を返す．        | 均し $O(\alpha(n))$ |
| `count()`      | 素集合の数を返す．                           | $O(1)$              |
| `groups()`     | 頂点を連結性で分割した同値類の情報を返す．   | $O(n)$              |
| `operator[x]`  | 頂点 $x$ の属する集合の代表元を返す．        | 均し $O(\alpha(n))$ |
