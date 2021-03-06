## 概要
分割数$P\left(n,k\right)$は$n$の個の区別できない玉を$k$個の区別できない箱に入れる組合せ数, すなわち整数$n$をちょうど$k$個の非負整数の和で表す場合の数を与える. これは,
1. 分割が$0$を含むとき, 組合せ数は$P\left(n,k-1\right)$に帰着される.
2. 分割が$0$を含まないとき, $k$個の整数が全て$0$以上なので, それらから$1$ずつ除けば組合せ数は$P\left(n-k,k\right)$に帰着される.

から,
$$P\left(n,k\right)=P\left(n,k-1\right)+P\left(n-k,k\right)$$
によって計算できる.

## 計算量
$O\left(nk\right)$

## 参照
[「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)