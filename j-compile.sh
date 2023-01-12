#!/bin/bash

compile_program()
{
    flags=""
    if $DEBUG; then
      flags+="-g"
    fi
    if $LINKING; then
      flags+=" -lm"
    fi
    echo $1 $INPUT $2 $flags -o $MYBIN/$OUTPUT 
    $1 $INPUT $2 $flags -o $MYBIN/$OUTPUT
}

DEBUG=false
LINKING=false
ORDER=0

for flag in $@
do
  if [[  $flag == "-g" ]];
  then
    DEBUG=true
    shift 1

  elif [[ $flag == "-lm" ]];
  then
    LINKING=true
    shift 
  fi
done

INPUT=$1
OUTPUT=$2

if [ -f $2 ]; 
then
  OUTPUT="a.out"
fi

if ! [ -f "$INPUT" ];
then
	echo "Arquivo Inexistente"
	exit 1
fi

if [[ $INPUT == *.c ]];
then
	echo "Compilando arquivo .c"	
	file=$(<$INPUT)

  if ! [[ $file == *"#include"*"<allegro"* ]]; then
  	compile_program "gcc"
  else
   var="$(cat $INPUT | grep "#include" | grep "allegro_")" #Acha as bibliotecas Allegro (linha)
   libs='allegro-5 ' # Inicializa variável libs

    for len in $var; do # para cada palavra na linha
      gate=false
    
      if [[ $len == "<"* ]]; then # se começar com <
		    for (( i=0; i<${#len}; i++ )); do # para cada letra
			    if [ ${len:$i:1} == '/' ] || [ "$gate" = true ]; then 
			  	# se a letra for '/' ou se já estiver contando
			  	  if [ ${len:$i:1} == '.' ]; then # condição de parada
				  		libs+="-5 " # coloca o -5 para o pkg config achar
				  		break # e termina a contagem da palavra.
				  	fi # termina condição de parada
				  	if [ "$gate" = true ]; then # se estiver contando
				  		libs+=${len:$i:1} # adiciona a letra normalmente em libs
				  	fi #termina if sobre "se *já estava* contando"
				  	gate=true  #começa a contar pq achou '\'
				  fi 
			  done 
		  fi 
	  done 
	  echo Bibliotecas ALLEGRO Adicionais: $libs
    compile_program "gcc" "$(pkg-config --libs $libs)"
  fi
elif [[ $INPUT == *.rs ]]
then
  compile_program "rustc"
fi

