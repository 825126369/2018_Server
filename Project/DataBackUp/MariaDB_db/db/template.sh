#! /bin/sh

database="game"
dbname="game_template"

dbstr="
intId int(10) unsigned primary key not null comment'account',
stringId varchar(255) null comment'password',
binaryId varbinary(2048) null comment'binary'
"

host="127.0.0.1"   
user="root"
passwd="123456"

mysql -s -h $host -u $user -p${passwd} <<EOF
use $database;
create table $dbname
(
${dbstr}
);
EOF
