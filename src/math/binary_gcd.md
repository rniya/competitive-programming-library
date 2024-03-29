---
title: binary gcd
documentation_of: ./binary_gcd.hpp
---

## 概要
2 数の最大公約数を求める．
一般的な Euclid の互除法による実装と異なり，非再帰かつ除算が 2 で割るものしか登場しないので bit shift で済み，約 3 から 4 倍程度高速である．

### 補題
- $\gcd(0, x) = \gcd(x, x) = x$
- $\gcd(2x, 2y) = 2\gcd(x, y)$
- $\gcd(2x, y) = \gcd(x, y)$ if $y$ is odd
- $\gcd(x, y) = \gcd(x - y, y)$ if $x > y$

どれも理解及び証明は容易で，原理は実際にソースコードを見るのがわかりやすい．
特に $x, y$ が共に奇数ならば $x - y$ は偶数であるから効率的に計算することが可能である．
