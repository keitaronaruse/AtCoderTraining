#!/bin/sh
rm result.txt
for var in `ls -1 in`
do
  ../build/ahc009-a-7 < "in/${var}" > "out/${var}"
  cargo run --release --bin vis "in/${var}" "out/${var}" >> result.txt
done
