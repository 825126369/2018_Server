gg:=g++
CFLAG:=-g3 -W -std=c++11 -I /usr/include/libxml2 -c
outDir:=out/
VPATH:=src
.PHONY: all install uninstall clean
all:$(outDir)ConfigTableToCpp.exe
clean:
	rm out/*

$(outDir)ConfigTableToCpp.exe:$(outDir)ConfigTableToCpp.o
	$(gg) $^ -lxml2 -o $@
$(outDir)ConfigTableToCpp.o:ConfigTableToCpp.cpp
	$(gg) $(CFLAG) -o $@ $<

