#!/usr/bin/env bash

for test in tests/*; do
  gcc $test;
  ./a.out;
done
