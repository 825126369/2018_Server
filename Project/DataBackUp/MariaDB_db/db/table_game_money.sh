#! /bin/sh
source ./mariadb.sh

database="game"
dbname="game_money"

dbstr="
account varchar(255) primary key not null comment'account',
money int(10) unsigned default 0 not null comment'wallet'
"
HandleTable $1
