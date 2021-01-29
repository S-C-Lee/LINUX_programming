#!/bin/bash

array=("hello",'world','sc')

echo ${array[1]}
echo ${array[@]}
echo ${array[*]}
echo ${#array[@]}

filelist=($(ls))
echo ${filelist[@]}

