gg:=g++
Libs:=-L /usr/local/lib -lprotobuf -lprotoc -L /usr/local/lib/mariadb -lcrypto -lxml2 -lpthread -lssl -lmariadb
HeadPath:=-I src -I src/auto/ConfigTable -I src/auto/DbTable -I src/auto/Protobuf -I src/ConfigTableManager -I src/DebugManager -I src/EncryptionManager -I src/EventManager -I src/MariaDBManager -I src/NetManager -I /usr/include/libxml2 -I /usr/local/include/mariadb -I /usr/local/include/google/protobuf -I /usr/local/include/google/protobuf/compiler -I /usr/local/include/google/protobuf/io -I /usr/local/include/google/protobuf/stubs
CFLAG:=-g3 -Wall -std=c++11 $(HeadPath) -c

outDir:=out/
VPATH:=src src/auto/ConfigTable src/auto/DbTable src/auto/Protobuf src/ConfigTableManager src/DebugManager src/EncryptionManager src/EventManager src/MariaDBManager src/NetManager

.PHONY: all install uninstall clean
all:$(outDir)Server.exe
clean:
	rm $(outDir)*

$(outDir)Server.exe:$(outDir)main.o $(outDir)NetThreadManager.o $(outDir)MariaDBSystem.o $(outDir)ConfigTableManager.o $(outDir)DbTable.o $(outDir)NetManager.o $(outDir)ConfigTable.o $(outDir)xkDebug.o $(outDir)EncryptionManager.o $(outDir)NetEventManager.o $(outDir)NetProtoEvent.o $(outDir)MariaDBManagerThread.o $(outDir)NetDefine.o $(outDir)proto_command.pb.o $(outDir)proto_message_one.pb.o $(outDir)proto_message_two.pb.o $(outDir)proto_struct.pb.o
	$(gg) $^ -o $@ $(Libs)
$(outDir)main.o:main.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)ConfigTable.o:ConfigTable.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)ConfigTableManager.o:ConfigTableManager.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)xkDebug.o:xkDebug.cpp	
	$(gg) $(CFLAG) -o $@ $^
$(outDir)EncryptionManager.o:EncryptionManager.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)NetEventManager.o:NetEventManager.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)NetProtoEvent.o:NetProtoEvent.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)DbTable.o:DbTable.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)MariaDBManagerThread.o:MariaDBManagerThread.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)MariaDBSystem.o:MariaDBSystem.cpp 
	$(gg) $(CFLAG) -o $@ $^
$(outDir)NetDefine.o:NetDefine.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)NetManager.o:NetManager.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)NetThreadManager.o:NetThreadManager.cpp
	$(gg) $(CFLAG) -o $@ $^
$(outDir)proto_command.pb.o:proto_command.pb.cc
	$(gg) $(CFLAG) -o $@ $^
$(outDir)proto_message_one.pb.o:proto_message_one.pb.cc
	$(gg) $(CFLAG) -o $@ $^
$(outDir)proto_message_two.pb.o:proto_message_two.pb.cc
	$(gg) $(CFLAG) -o $@ $^
$(outDir)proto_struct.pb.o:proto_struct.pb.cc
	$(gg) $(CFLAG) -o $@ $^
