#! /bin/sh
getallcpp()	
{
	files=$(ls $1) 
	for element in $files 
	do 
		dir_or_file=$1"/"$element 
		if [ -d $dir_or_file ];then 
			getallcpp $dir_or_file $2
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
		result_d="$result_d $outdir$x.$1";
	done
	result_d=$result_d
}
get_o()
{
	getallcpp $rootdir
	for x in $result_c;
	do 
		result_o="$result_o $outdir$x.o"; 
	done
	result_o=$result_o
}
get_action()
{
	echo '		$(gg) $(CFLAG) -o $@ $<' >>$1
}
rootdir=$1
outdir=$2
if [ $3 = "c" ];then
	get_cpp $rootdir
	echo $result_cpp
elif [ $3 = "d" ];then
	get_d $4 $5
	echo $result_d
elif [ $3 = "o" ];then
	get_o
	echo $result_o
elif [ $3 = "action" ];then
	get_action
else
	echo "Input Error! "
	echo '$1 : RootDir'
	echo '$2 : Action'
	echo '$3,$4 : fun args'
fi





