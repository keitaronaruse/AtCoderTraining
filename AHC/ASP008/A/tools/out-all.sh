#!/bin/sh
for var in `ls -1 in`
do
    basename=`echo $var | cut -c 6-13` 
    ../build/asp008-a-5 < "in/input${basename}" > "out/output${basename}"
done
