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
  bundledCode: "#line 2 \"util/RandomNumberGenerator.hpp\"\n#include <chrono>\n#include\
    \ <random>\n\nstruct RandomNumberGenerator {\n    std::mt19937 mt;\n    RandomNumberGenerator()\
    \ : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}\n    uint32_t\
    \ operator()(uint32_t a, uint32_t b) {\n        std::uniform_int_distribution<uint32_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    uint32_t operator()(uint32_t\
    \ b) { return (*this)(0, b); }\n};\n\nstruct RandomNumberGenerator64 {\n    std::mt19937_64\
    \ mt;\n    RandomNumberGenerator64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    uint64_t operator()(uint64_t a, uint64_t b) {\n        std::uniform_int_distribution<uint64_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    uint64_t operator()(uint64_t\
    \ b) { return (*this)(0, b); }\n};\n"
  code: "#pragma once\n#include <chrono>\n#include <random>\n\nstruct RandomNumberGenerator\
    \ {\n    std::mt19937 mt;\n    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    uint32_t operator()(uint32_t a, uint32_t b) {\n        std::uniform_int_distribution<uint32_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    uint32_t operator()(uint32_t\
    \ b) { return (*this)(0, b); }\n};\n\nstruct RandomNumberGenerator64 {\n    std::mt19937_64\
    \ mt;\n    RandomNumberGenerator64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    uint64_t operator()(uint64_t a, uint64_t b) {\n        std::uniform_int_distribution<uint64_t>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    uint64_t operator()(uint64_t\
    \ b) { return (*this)(0, b); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: util/RandomNumberGenerator.hpp
  requiredBy: []
  timestamp: '2022-11-11 20:10:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/RandomNumberGenerator.hpp
layout: document
title: "\u4E71\u6570\u751F\u6210"
---

## 概要
一様乱数を生成する.

## 参照
[Don't use rand(): a guide to random number generators in C++ - Codeforces](https://codeforces.com/blog/entry/61587)