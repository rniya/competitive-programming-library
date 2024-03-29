---
title: Partially Persistent Union Find
documentation_of: ./PartiallyPersistentUnionFind.hpp
---

## 概要
経路圧縮を行わずにマージテクを利用して集合を管理する際に，変更される値が少ないことを利用してタイムスタンプを用いて過去の頂点の連結成分やその頂点数といったデータを取得できるようにしたデータ構造．

以下に記す内容について，時刻 $t$ は 0 からスタートし `merge` が呼び出されるごとに操作直前にインクリメントされる．
すなわち $i$ 回目 (1-indexed) のマージ後の関係を調べるためには引数 $t$ はそのまま $i$ でよく，1-indexed であることに注意が必要である．

| メンバ関数                        | 効果                                                              | 時間計算量  |
| --------------------------------- | ----------------------------------------------------------------- | ----------- |
| `PartiallyPersistentUnionFind(n)` | 要素数 $n$ で初期化する．                                         | $O(n)$      |
| `find(t, x)`                      | 時刻 $t$ において頂点 $x$ が属していた集合の代表元を返す．        | $O(\log n)$ |
| `merge(x, y)`                     | 頂点 $x, y$ が属する集合を併合する．                              | $O(\log n)$ |
| `same(t, x, y)`                   | 時刻 $t$ において頂点 $x, y$ が同一の集合に属していたか判定する． | $O(\log n)$ |
| `size(t, x)`                      | 時刻 $t$ において頂点 $x$ が属していた集合の要素数を返す．        | $O(\log n)$ |

## 問題例
- [AtCoder Grand Contest 002 D - Stamp Rally](https://atcoder.jp/contests/agc002/tasks/agc002_d)

## Links
- [UnionFindTree に関する知見の諸々 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2018/05/30/191943)
