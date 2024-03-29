## 概要
最大流を計算する.

| メンバ関数                          | 効果                                                                                                                                                      | 時間計算量 |
| ----------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| `Dinic(n)`                          | $n$ 頂点 0 辺のグラフとして初期化する.                                                                                                                    | $O(n)$     |
| `add_edge(from, to, cap)`           | $from$ から $to$ へ容量 $cap$ の辺を追加する.                                                                                                             | $O(1)$     |
| `add_vertex()`                      | 頂点を 1 つ追加する.                                                                                                                                      | $O(1)$     |
| `get_edge(i)`                       | $i$ 番目に追加された辺の始点, 終点, 容量, 実際に流れている量をまとめて返す.                                                                               | $O(1)$     |
| `edges()`                           | `get_edge` で返されるデータをすべての辺について配列にして返す.                                                                                            | $O(m)$     |
| `change_edge(i, new_cap, new_flow)` | $i$ 番目に追加された辺の容量を $new cap$ に, 流れている量を $new flow$ に変更する.                                                                        | $O(1)$     |
| `max_flow(s, t)`                    | 頂点 $s$ から 頂点 $t$ へ流れる最大流を求める.                                                                                                            | $O(n^2m)$  |
| `min_cut(s)`                        | 頂点 $s$ から到達できる頂点群を返す. 頂点の全体集合を $V$ , この関数が返す頂点集合を $S$ とすると, $S$ と $V \setminus S$ を結ぶ辺が最小カットに相等する. | $O(n + m)$ |
| `dump_graphviz()`                   | グラフを `.dot` 形式で出力する. 容量丁度の流量が流れる辺は赤色, そうでなく正の流量が流れる辺は青, 全く流れない辺は黒で出力される.                         | $O(m)$     |

`max_flow` の計算量はケースごとにかなり異なり, 一般的には上記の計算量より高速に動作することが多い. 詳しくは Links にもある[Dinic 法とその時間計算量 - みさわめも](https://misawa.github.io/others/flow/dinic_time_complexity.html)を参照.

## 問題例
- [AOJ 2313 ハコの魔女](https://onlinejudge.u-aizu.ac.jp/problems/2313)
  - 流し戻しが必要．

## Links
- [Dinic 法の速さ - れんしゅうちょう.  - TopCoder部](https://topcoder-g-hatena-ne-jp.jag-icpc.org/Mi_Sawa/20140311/1394730337.html)
- [Dinic 法とその時間計算量 - みさわめも](https://misawa.github.io/others/flow/dinic_time_complexity.html)
