#!/bin/sh
cargo run --release --bin tester ../build/ahc008-a-1 < in/0000.txt > out/0000.txt  2> pets/0000.txt
