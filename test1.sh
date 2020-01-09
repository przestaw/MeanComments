#!/bin/bash

rm ./output.csv

for groups in 100 250
do
    for com in 100 250 500 750 1000 2500 5000 7500 10000 25000 50000 100000 250000 500000
    do
        if (($groups <= $com))
        then
        ./AAL-program -c $com --users_count $groups --group_count 0 --iter 100 -p 1  >> ./output.csv
        fi
    done
done

for groups in 500 750
do
    for com in 500 750 1000 2500 5000 7500 10000 25000 50000 100000 250000 500000 1000000
    do
        if (($groups <= $com))
        then
        ./AAL-program -c $com --users_count $groups --group_count 0 --iter 100 -p 1  >> ./output.csv
        fi
    done
done

for groups in 1000 2500
do
    for com in 1000 2500 5000 7500 10000 25000 50000 100000 250000 500000 1000000 2500000   
    do
        if (($groups <= $com))
        then
        ./AAL-program -c $com --users_count $groups --group_count 0 --iter 100 -p 1  >> ./output.csv
        fi
    done
done

for groups in 5000 7500
do
    for com in 5000 7500 10000 25000 50000 100000 250000 500000 1000000 2500000 5000000
    do
        if (($groups <= $com))
        then
        ./AAL-program -c $com --users_count $groups --group_count 0 --iter 100 -p 1  >> ./output.csv
        fi
    done
done

for groups in 10000 25000
do
    for com in 10000 25000 50000 100000 250000 500000 1000000 2500000 5000000 10000000
    do
        if (($groups <= $com))
        then
        ./AAL-program -c $com --users_count $groups --group_count 0 --iter 100 -p 1  >> ./output.csv
        fi
    done
done
