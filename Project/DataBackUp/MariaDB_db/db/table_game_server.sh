#! /bin/sh
source ./mariadb.sh

database="game"
dbname="game_server"

dbstr="
account varchar(255) primary key not null comment'account name',
loginallserverinfo varbinary(2048) null comment'record server role infomation',
lastloginserverid int(10) unsigned not null comment'last login server id' 
"
HandleTable $1
