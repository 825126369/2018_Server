#! /bin/sh
source ./mariadb.sh

database="game"
dbname="game_login"

dbstr="
account varchar(255) primary key not null comment'account',
password varchar(255)  not null comment'password'
"
HandleTable $1
