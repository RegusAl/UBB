#!/bin/bash

for el in `cat who.fake | awk '{print $1}'`
do
	#echo $el
	for name in `cat ps.fake | awk '{print $1}' | sort -k2 | uniq -c | sort -nr`
	do
		if [ $el = $name ] 
		then
			echo $name
			
		fi
	done
done

#cat who.fake | awk '{print $1}'
#cat ps.fake | awk '{print $1}' | sort -k2 | uniq -c | sort -n 

exit 0
