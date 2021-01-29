#!/bin/bash

if [ $1 -eq $2 ]
then echo "this is equal"
fi

if [ $1 -ne $2 ]
then echo " this is nequal"
fi

if [ $1 -lt $2 ]
then echo " 1 is less then 2"
fi

if [ $1 -le $2 ] 
then echo " 1 is less or equal 2"
fi

if [ $1 -gt $2 ]
then echo " 1 is greater then 2"
fi

if [ $1 -ge $2 ]
then echo " 1 is greater of equal 2"
fi


