#! /bin/sh
source ./mariadb.sh
database="game"
dbname="game_role"

dbstr="
roleId int(10) unsigned primary key comment'role ID',
name varchar(255) not null comment'role Name',
gender int(10) unsigned not null default 0 comment'role gender',
profession int(10) unsigned not null default 0 comment'role profession',
level int(10) unsigned not null default 0 comment'role level'
"
HandleTable $1
