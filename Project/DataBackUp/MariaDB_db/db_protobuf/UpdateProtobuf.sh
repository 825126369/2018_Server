#! /bin/sh
cd Proto/
echo "Start Generate cpp file by .proto"
rm -f out/*
for file in ./*.proto
do
	if test -f $file; then		
		protoc --cpp_out=. $file
		echo "$file"
	fi
done
cd ../

rm -f ../../../Server/src/auto/db_Protobuf/*
mv -f Proto/*.cc ../../../Server/src/auto/db_Protobuf/
mv -f Proto/*.h ../../../Server/src/auto/db_Protobuf/

echo "Finsh" 
