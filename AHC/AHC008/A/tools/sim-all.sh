#!/bin/sh
for var in `ls -1 in`
do
  cargo run --release --bin tester ../build/ahc008-a-1 < "in/${var}" > "out/${var}"
done