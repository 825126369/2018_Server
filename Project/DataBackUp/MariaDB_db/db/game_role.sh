#! /bin/sh
host="127.0.0.1"   
user="root"
passwd="123456"
database="game"
dbname="game_role"

mysql -s -h ${host} -u ${user} -p${passwd} <<EOF
create database if not exists ${database};
use ${database};
create table ${dbname}(
userId int(255) primary key not null comment'数据库ID',
level  int(255) not null comment'密码'
);
show tables;


EOF
