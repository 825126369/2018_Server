#! /bin/sh
MariaDBToCPP/out/main.exe
rm -f ../Server/src/auto/DbTable/*
mv DbTable.h ../Server/src/auto/DbTable/
mv DbTable.cpp ../Server/src/auto/DbTable/
