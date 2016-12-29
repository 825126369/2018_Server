#! /bin/sh
host="127.0.0.1"   
user="root"
passwd="123456"
dbname="test"

cmd="create table aaa(id int(10))"  
mysql -s -h $host -u $user -p${passwd} <<EOF
show databases;
use nimabi;
show tables;
select * from Sheet2DBs;

EOF
