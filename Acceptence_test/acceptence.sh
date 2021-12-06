#!/bin/bash

./philosophers 
RETURN=$(echo $?)

if [ $RETURN == "1" ]
then
    echo "Invalid input"
fi

# Number of philos | tt_die | tt_eat || tt_sleep || [num_of_tt_eat]
./philosophers 3 5 2 2 
RETURN=$(echo $?)

if [ $RETURN == "0" ]
then
    echo "Valid input"
else
    echo "Error on too long input"
fi
