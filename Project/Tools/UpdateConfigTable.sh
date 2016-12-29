#! /bin/sh
ConfigTableToCpp/out/ConfigTableToCpp.exe
rm -f ../Server/src/auto/ConfigTable/*
mv ConfigTable.h ../Server/src/auto/ConfigTable/
mv ConfigTable.cpp ../Server/src/auto/ConfigTable/
