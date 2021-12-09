#!/bin/bash

# file to group files into a folder
# to make exporting easier

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
if ! [ -d "jg-tools" ]; 
then
    mkdir jg-tools

    # se ela existe então sobrescreva
    # (só se não for especificado o diretório!)
else
    rm -r ./jg-tools/* 
fi

# copia o header
cp $1 ./jg-tools/

# identifica os headers usados
headers=$(cat ./j-groups/jg_strings.h | grep include | cut -d"/" -f3 | sed 's/.$//')

# inclui os headers do arquivo
for file in $headers; do
    cp ./j-tools/$file ./jg-tools/
done

if [[ $2 == "" ]];
then
    echo "Nenhum local especificado"
    echo "Produzindo grupo neste diretório"
else
    mv ./jg-tools $2
fi