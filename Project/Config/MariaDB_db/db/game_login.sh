#! /bin/sh
host="127.0.0.1"
user="root"
passwd="123456"
database="game"
dbname="game_login"




mysql -s -h $host -u $user -p${passwd} <<EOF
create database if not exists ${database};
use ${database};
create table ${dbname}(
account varchar(255) primary key not null comment'account',
password varchar(255)  not null comment'password'
);
show tables;
EOF
