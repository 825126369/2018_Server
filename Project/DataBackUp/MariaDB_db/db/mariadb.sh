#! /bin/sh

host="127.0.0.1"
user="root"
passwd="123456"
database="game"

dbstr="
	account varchar(255) primary key not null comment'account',
	password varchar(255)  not null comment'password'
"

CreateTable1()
{
mysql -s -h $host -u $user -p${passwd} <<EOF
create database if not exists ${database};
use ${database};
create table ${dbname}
(
$(eval echo $1)
);
EOF
}
CreateTable()
{
	CreateTable1 '$dbstr'
}

DropTable()
{
mysql -s -h $host -u $user -p${passwd} <<EOF
create database if not exists ${database};
use ${database};
drop table if exists ${dbname};
EOF
}

HandleTable()
{	
		if [ $# -eq 0 ]; then
			CreateTable;	
		elif [ $# -gt 0 ];then
			if [ $1 -eq 1 ];then
				CreateTable
			elif [ $1 -eq 2 ];then
				DropTable
			fi	
		fi
}	











