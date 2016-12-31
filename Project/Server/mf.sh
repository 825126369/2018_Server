#! /bin/sh
getallcpp()	
{
	files=$(ls $1) 
	for element in $files 
	do 
		dir_or_file=$1"/"$element 
		if [ -d $dir_or_file ];then 
			getallcpp $dir_or_file
		elif [ -e $dir_or_file ]; then 
			extention="${dir_or_file##*.}" 	
			if [ -z $2 ];then
				if [ $extention = "cc" -o $extention = "cpp" ]; then 
					result_c="$result_c ${element%.*}"
				fi
			elif [ $2 = "cc" -a $extention = "cc" ] ;then
					result_c="$result_c ${element%.*}"
			elif [ $2 = "cpp" -a $extention = "cpp" ] ;then
					result_c="$result_c ${element%.*}"
			fi
		fi 
	done 
	result_c=$result_c 
}
get_cpp()
{
	files=$(ls $1)
	for element in $files
	do
		dir_or_file=$1"/"$element
		if [ -d $dir_or_file ];then
			get_cpp $dir_or_file
		else
			extention="${dir_or_file##*.}"
			if [ $extention = "cc" -o $extention = "cpp" ];then
				result_cpp="$result_cpp $dir_or_file";
			fi
		fi		
	done
	result_cpp=$result_cpp
}

get_d()
{
	getallcpp $rootdir $2
	for x in $result_c; 
	do 
		result_d="$result_d $x.$1";
	done
	result_d=$result_d
}
get_o()
{
	getallcpp $rootdir
	for x in $result_c;
	do 
		result_o="$result_o $x.o"; 
	done
	result_o=$result_o
}
get_action()
{
	#echo '		$(gg) $(CFLAG) -o $@ $<' >>$1
	echo $1
}
rootdir=$1
if [ $2 = "c" ];then
	get_cpp $rootdir
	echo $result_cpp
elif [ $2 = "d" ];then
	get_d $3 $4
	echo $result_d
elif [ $2 = "o" ];then
	get_o
	echo $result_o
elif [ $2 = "action" ];then
	echo $3
else
	echo "Input Error! "
	echo '$1 : RootDir'
	echo '$2 : Action'
	echo '$3,$4 : fun args'
fi





