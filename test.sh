#!/usr/bin/env bash

for test in tests/*; do
  clang $test;
  ./a.out;
done
