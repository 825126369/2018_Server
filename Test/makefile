gg:=g++
cc:=gcc
Head:=-I src 
gg_FLAG:=-g3 -W -std=c++11 $(Head) -c
cc_FLAG:=-g3 -W -std=c11 $(Head) -c
VPATH:=src
.PHONY: all install uninstall clean
all:main.exe
clean:
	rm *.d *.o
main.exe:main_c.o sort_algorithm.o
	$(cc) $^ -o $@
main_c.o:main.c
	$(cc) $(cc_FLAG) $<  -o $@
sort_algorithm.o:sort_algorithm.c
	$(cc) $(cc_FLAG) $<  -o $@
