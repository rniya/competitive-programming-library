## 概要
Project Selection Problem, いわゆる燃やす埋める問題を解く際の補助ライブラリ.
- `x_false_loss(x, z)`：$x$が$0$のときに$z$失う
- `x_false_profit(x, z)`：$x$が$0$のときに$z$得る
- `x_true_loss(x, z)`：$x$が$1$のときに$z$失う
- `x_true_profit(x, z)`：$x$が$1$のときに$z$得る
- `x_false_y_true_loss(x, y, z)`：$x$が$0$かつ$y$が$1$のときに$z$失う
- `x_true_y_false_loss(x, y, z)`：$x$が$1$かつ$y$が$0$のときに$z$失う
- `x_true_y_true_profit(x, y, z)`：$x$が$1$かつ$y$が$1$のときに$z$得る
- `x_false_y_false_profit(x, y, z)`：$x$が$0$かつ$y$が$0$のときに$z$得る

といった条件に対応している. 一般にこれ以外の条件に対応する際には$2$部グラフなどの制約が必要になる.

## 計算量
$O(EV^2)$だが, 概ねこれより高速に動作する.

## 問題例
[ARC107 F Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
絶対値については, 各頂点に対して$0$(削除), $+1$(連結成分内での$B_i$の合計が正), $-1$(連結成分内での$B_i$の合計が正負)として, 各連結成分内に$+1$と$-1$が割り当てられた頂点が混在することがないようにすれば問題ない. これは$3$つのうちどれかに割り当てる問題になるが, 各頂点に対して$+1$か$+1$以外, $-1$以外か$-1$という2つの選択肢の直積として表現することで解くことができる. ([参照](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607))

## 参照
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)