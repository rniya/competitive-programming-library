---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: datastructure/SlidingWindowAggregation.hpp
    title: Sliding Window Aggregation (SWAG)
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/SlidingWindowAggregation.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../datastructure/SlidingWindowAggregation.hpp\"\n\nusing mint=modint<998244353>;\n\
    \nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    struct node{\n\
    \        mint a,b;\n        node(mint a,mint b):a(a),b(b){}\n    };\n    auto\
    \ f=[](node a,node b){return node(a.a*b.a,a.b*b.a+b.b);};\n    SlidingWindowAggregation<node>\
    \ SWAG(f,node(1,0));\n\n    int Q; cin >> Q;\n    for (;Q--;){\n        int t;\
    \ cin >> t;\n        if (t==0){\n            int a,b; cin >> a >> b;\n       \
    \     SWAG.push(node(a,b));\n        } else if (t==1){\n            SWAG.pop();\n\
    \        } else {\n            int x; cin >> x;\n            node ans=SWAG.fold();\n\
    \            cout << ans.a*x+ans.b << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - datastructure/SlidingWindowAggregation.hpp
  isVerificationFile: true
  path: test/yosupo/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_operate_all_composite.test.cpp
- /verify/test/yosupo/queue_operate_all_composite.test.cpp.html
title: test/yosupo/queue_operate_all_composite.test.cpp
---