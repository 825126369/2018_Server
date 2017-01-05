gg:=g++
Head:=-I src -I /usr/local/include/libev
Lib:=-lev
CFLAG:=-g3 -W -std=c++11 $(Head) -c
VPATH:=src
.PHONY: all install uninstall clean
all:server.exe client.exe
clean:
	rm *.d *.o
server.exe:server.o
	$(gg) $^ -o $@ $(Lib)
client.exe:client.o
	$(gg) $^ -o $@ $(Lib)
include server.d client.d
%.d:%.cpp
	$(gg) $(CFLAG) -MM $< >$@;   
%.o:
	$(gg) $(CFLAG) -o $@ $<	
