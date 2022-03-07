#!/bin/sh
for var in `ls -1 tools/in`
do
    basename=`echo $var | cut -c 6-13` 
    build/sample < "tools/in/input${basename}" > "tools/out/output${basename}"
done
