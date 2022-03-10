#!/bin/sh
rm result/result.txt
for var in `ls -1 test2000/in`
do
    basename=`echo $var | cut -c 6-13` 
    ./output_checker "test2000/in/input${basename}" "test2000/out/output${basename}" >> test2000/result/result.txt
done
