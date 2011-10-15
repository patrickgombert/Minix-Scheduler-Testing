#!/usr/pkg/bin/bash

mkdir csv_output/$1
touch csv_output/$1/cpu_bound.csv
echo real,system,user >> csv_output/$1/cpu_bound.csv
touch csv_output/$1/io_bound.csv
echo real,system,user >> csv_output/$1/io_bound.csv
touch csv_output/$1/mixed_bound.csv
echo real,system,user >> csv_output/$1/mixed_bound.csv

# warm up run
./cpu_bound&
./io_bound&
./mixed_bound&
wait

for i in 1 2 3 4 5 6 7 8 9 10
do
  ./cpu_bound >> csv_output/$1/cpu_bound.csv&
  ./io_bound >> csv_output/$1/io_bound.csv&
  ./mixed_bound >> csv_output/$1/mixed_bound.csv&
  wait
done

echo Execution finished!
