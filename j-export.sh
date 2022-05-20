#!/bin/bash

# V 1.1
# file to group files into a folder
# to make exporting easier

# ./j-export.sh j-groups/jg_strings.h

if [[ $1 == "" ]];
then
    echo "Nenhum arquivo selecionado"
    exit 1
fi

if ! [ -f $1 ];
then
    echo "Grupo alvo inexistente"
    exit 1
fi

# cria a pasta
mkdir jg-groups
mkdir jg-tools

# copia o header
cp $1 ./jg-groups/

# identifica os headers usados
headers=$(cat $1 | grep include | cut -d"/" -f3 | sed 's/.$//')

# inclui os headers do arquivo
for file in $headers; do
    cp ./j-tools/$file ./jg-tools/
done

if [[ $2 == "" ]];
then
    echo "Nenhum local especificado"
    echo "Produzindo grupo neste diretório com nome jg-tools"
    echo "Por favor exporte manualmente os arquivos"
else
    echo "Criando arquivo jg-group e jg-tools no local especificado"
    mv jg-groups $2
    mv jg-tools  $2
fi
