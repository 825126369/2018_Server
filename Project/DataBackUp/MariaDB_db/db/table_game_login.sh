#! /bin/sh
source ./mariadb.sh

database="game"
dbname="game_login"

dbstr="
account varchar(255) not null comment'account',
password varchar(255) not null comment'password',
index index_account(account asc),
primary key(account)
"
HandleTable $1
