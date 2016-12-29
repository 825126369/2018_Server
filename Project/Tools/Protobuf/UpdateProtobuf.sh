#! /bin/sh
echo "Start Generate cpp file by .proto,directory is out"
for file in ./out/*
do
	rm -rf $file
done

cd Proto
for file in ./*.proto
do
	if test -f $file; then		
		protoc --cpp_out=. $file
		echo "$file"
	fi
done
for file in ./*.h
do
	mv $file ../out/
done
for file in ./*.cc
do
	mv $file ../out/
done
cd ../


rm -f ../../Server/src/auto/Protobuf/*
mv -f out/* ../../Server/src/auto/Protobuf/

echo "Finsh" 
