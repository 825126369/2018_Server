#! /bin/sh
cd Proto/
echo "Start Generate cpp file by .proto,directory is out"
rm out/*
for file in ./*.proto
do
	if test -f $file; then		
		protoc --cpp_out=. $file
		echo "$file"
	fi
done
cd ../

for file in Proto/*.h
do
	mv $file out/
done
for file in Proto/*.cc
do
	mv $file out/
done


rm -f ../../Server/src/auto/Protobuf/*
mv -f out/* ../../Server/src/auto/Protobuf/

echo "Finsh" 
