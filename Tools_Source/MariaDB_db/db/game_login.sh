#! /bin/sh
host="127.0.0.1"   
user="root"
passwd="123"
database=game
dbname="game_login"
dbfile=game_login.table

mysql -s -h $host -u $user -p${passwd} <<EOF
create database if not exists ${database};
use ${database};
create table ${dbname}(
account varchar(255) primary key not null comment'账户',
password varchar(255)  not null comment'密码'
#account varchar(255)  not null comment'账户',
);
show tables;


EOF
