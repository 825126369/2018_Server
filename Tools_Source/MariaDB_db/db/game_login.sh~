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
id int(255) comment'字段1',
account varchar(255) comment'账户',
password varchar(255) comment'密码'
);
show tables;


EOF
