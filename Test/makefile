gg:=g++
Head:=-I src -I /usr/local/include/google/protobuf 
Lib:=-lprotobuf
CFLAG:=-g3 -W -std=c++11 $(Head) -c
VPATH:=src
.PHONY: all install uninstall clean
all:main.exe
clean:
	rm *.d *.o
main.exe:main.o db_protobuf.pb.o db_protobuf_struct.pb.o
	$(gg) $^ -o $@ $(Lib)
include main.d db_protobuf.pb.d db_protobuf_struct.pb.d
%.d:%.cpp
	$(gg) $(CFLAG) -MM $< >$@; 
%.d:%.cc
	$(gg) $(CFLAG) -MM $< >$@;	
%.o:
	$(gg) $(CFLAG) -o $@ $<	
