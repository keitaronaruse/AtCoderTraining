#!/bin/sh
for var in `ls -1 test2000/in`
do
    basename=`echo $var | cut -c 6-13` 
    ../build/asp008-a-5 < "test2000/in/input${basename}" > "test2000/out/output${basename}"
done
