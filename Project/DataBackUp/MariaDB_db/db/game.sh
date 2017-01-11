#! /bin/sh

for db in ./table_*.sh;
do	
	if [ $# -eq 0 ]; then
		sh $db	
	elif [ $# -gt 0 ];then
		sh $db $1 
	fi
done	












