#!/bin/bash

./philo
RETURN=$(echo $?)

if [ $RETURN == "1" ]
then
    echo "Invalid input"
fi

# Number of philos | tt_die | tt_eat || tt_sleep || [num_of_tt_eat]
./philo 4 310 200 100
RETURN=$(echo $?)

if [ $RETURN == "0" ]
then
    echo "Valid input"
else
    echo "Error on valid input"
fi
