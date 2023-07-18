#!/bin/bash

# Check if the program and number of runs are provided as arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 <program> <number of runs>"
    exit 1
fi

# Read the program and number of runs from the command-line arguments
PROGRAM=$1
NUM_RUNS=$2

# Run race repeatedly and count unique outputs
for ((i=1; i<=NUM_RUNS; i++))
do
    ./"$PROGRAM"
done | sort | uniq -c
