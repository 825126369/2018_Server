gg:=g++
CFLAG:=-g3 -W -std=c++11 -I /usr/local/include/mariadb -c
outDir:=out/
VPATH:=src
.PHONY: all install uninstall clean
all:$(outDir)main.exe
clean:
	rm out/*

$(outDir)main.exe:$(outDir)main.o
	$(gg) $^ -L /usr/local/lib/mariadb -lmariadb -o $@
$(outDir)main.o:MariaDbToCpp.cpp
	$(gg) $(CFLAG) -o $@ $<

