#!/bin/sh
for var in `ls -1 in`
do
    basename=`echo $var | cut -c 6-13` 
    ../build/sample < "in/input${basename}" > "out/output${basename}"
done
