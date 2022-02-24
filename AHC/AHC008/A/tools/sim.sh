#!/bin/sh
cargo run --release --bin tester ../build/ahc008-a-3 < "in/$1" > "out/$1" 2> "pets/$1"
