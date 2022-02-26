#!/bin/sh
cargo run --release --bin tester ../build/ahc008-a-8 < "in/$1" > "out/$1" 2> "pets/$1"
