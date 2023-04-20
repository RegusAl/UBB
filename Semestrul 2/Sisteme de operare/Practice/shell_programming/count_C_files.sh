#!/bin/bash

S=0
for F in $1/*.c
do
	N=`grep "[^ \t]" $F | wc -l`
	S=`expr $S + $N`
done
echo $S
