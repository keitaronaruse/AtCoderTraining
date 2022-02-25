#!/bin/sh
cargo run --release --bin tester ../build/ahc008-a-7 < "in/$1" > "out/$1" 2> "pets/$1"
