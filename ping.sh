#!/bin/bash

ping -c 1 192.168.0.1 1> /dev/null
if [ $? == 0 ]
then echo "success"
else echo "fail"	
fi
