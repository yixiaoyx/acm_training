#!/usr/bin/env bash

echo 100
for i in {1..100}
do
    echo $(( $RANDOM % 2 ))
done
