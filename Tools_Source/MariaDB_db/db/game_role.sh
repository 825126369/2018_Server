#! /bin/sh
host="127.0.0.1"   
user="root"
passwd="123"
database=game
dbname="game_role"
dbfile=game_login.table

mysql -s -h $host -u $user -p${passwd} <<EOF
create database if not exists ${database};
use ${database};
create table ${dbname}(
id int(255) comment'序号',
userId int(255) comment'数据库ID',
level  int(255) comment'密码'
);
show tables;


EOF
