#!/bin/sh
rm result/result.txt
for var in `ls -1 in`
do
    basename=`echo $var | cut -c 6-13` 
    ./output_checker "in/input${basename}" "out/output${basename}" >> result/result.txt
done
