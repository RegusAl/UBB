#!/bin/bash

var1=noua
var2=9
var3=890
var4=ddf6sd23s

for A in $var1 $var2 $var3 $var4
do
	if [ "$A" -eq "$A" ] 2>/dev/null
	then
		echo $A is a number
	else
		echo $A is not a number
	fi
done
