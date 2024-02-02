#!/bin/bash

for i in {1..10}
do
  if [ $i -eq 3 ]
  then
    break
  fi

  for j in {1..3}
  do
    echo "i = $i, j = $j"
  done 
done