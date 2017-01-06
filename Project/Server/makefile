gg:=g++
Libs:=-lprotobuf -lprotoc -lcrypto -lxml2 -lpthread -lssl -L /usr/local/lib/mariadb -lmariadb -lev
HeadPath:=-I src -I src/auto/ConfigTable -I src/auto/DbTable -I src/auto/Protobuf -I src/ConfigTableManager -I src/DebugManager -I src/EncryptionManager -I src/EventManager -I src/MariaDBManager -I src/NetManager -I /usr/include/libxml2 -I /usr/local/include/mariadb -I /usr/local/include/google/protobuf -I /usr/local/include/google/protobuf/compiler -I /usr/local/include/google/protobuf/io -I /usr/local/include/google/protobuf/stubs -I /usr/local/include/libev
CFLAG:=-g3 -Wall -std=c++11 $(HeadPath)
outDir:=out/
RootDir:=src
VPATH:=src src/ThreadPoolManager src/CommonBase src/auto/ConfigTable src/auto/DbTable src/auto/Protobuf src/ConfigTableManager src/DebugManager src/EncryptionManager src/EventManager src/MariaDBManager src/NetManager
objs:=$(shell sh mf.sh $(RootDir) $(outDir) o)

.PHONY: all install uninstall clean test
all:$(outDir)Server.exe
clean:
	rm out/*
$(outDir)Server.exe:$(objs)
	$(gg) $^ -o $@ $(Libs)
-include $(shell sh mf.sh $(RootDir) $(outDir) d d1 cpp)
$(outDir)%.d1:%.cpp 
	$(gg) $(CFLAG) -MM $< >$@.$$$$;   \
	sed '1s,^,$(outDir),'<$@.$$$$ >$@; \
	rm -rf $@.$$$$;      
-include $(shell sh mf.sh $(RootDir) $(outDir) d d2 cc)
$(outDir)%.d2:%.cc
	$(gg) $(CFLAG) -MM $< >$@.$$$$;   \
	sed '1s,^,$(outDir),'<$@.$$$$ >$@; \
	rm -rf $@.$$$$;      
$(objs):
	$(gg) $(CFLAG) -c -o $@ $<      
	
