cc:=g++
Head:=-I src 
cc_FLAG:=-g3 -W -std=c++11 $(Head) -c
VPATH:=src
.PHONY: all install uninstall clean
all:main.exe
clean:
	rm *.d *.o
main.exe:main.o
	$(cc) $^ -o $@
main.o:main.cpp
main.o:
	$(cc) $(cc_FLAG) $<  -o $@
