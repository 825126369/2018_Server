gg:=g++
Libs:=-L /usr/local/lib -lprotobuf -lprotoc -L /usr/local/lib/mariadb -lcrypto -lxml2 -lpthread -lssl -lmariadb
HeadPath:=-I src -I src/auto/ConfigTable -I src/auto/DbTable -I src/auto/Protobuf -I src/ConfigTableManager -I src/DebugManager -I src/EncryptionManager -I src/EventManager -I src/MariaDBManager -I src/NetManager -I /usr/include/libxml2 -I /usr/local/include/mariadb -I /usr/local/include/google/protobuf -I /usr/local/include/google/protobuf/compiler -I /usr/local/include/google/protobuf/io -I /usr/local/include/google/protobuf/stubs
CFLAG:=-g3 -Wall -std=c++11 $(HeadPath)
outDir:=out/
RootDir:=src
VPATH:=src src/auto/ConfigTable src/auto/DbTable src/auto/Protobuf src/ConfigTableManager src/DebugManager src/EncryptionManager src/EventManager src/MariaDBManager src/NetManager
objs=$(shell sh mf.sh $(RootDir) o)



.PHONY: all install uninstall clean test
all:Server.exe
clean:
	rm *.d1 *.d2 *.o Server.exe
Server.exe:$(objs)
	$(gg) $^ -o $@ $(Libs)
-include $(shell sh mf.sh $(RootDir) d d1 cpp)
%.d1:%.cpp
	$(gg) $(CFLAG) -MM $< >$@       
-include $(shell sh mf.sh $(RootDir) d d2 cc)
%.d2:%.cc
	$(gg) $(CFLAG) -MM $< >$@      
$(objs):
	$(gg) $(CFLAG) -c -o $@ $<      
	
