#!/bin/bash

# colors for printing
RED='\033[0;31m'
GREEN='\033[1;32m'
NC='\033[0m' # No Color

# dependency files
test_files='../src/conv.c ../src/helpers.c'

# make this script have permission to run src files
chmod -R 777 ../src/*.c

counter=0
for i in *_tests.c
do
	if gcc "$i" $test_files -o "${i%.c}.out"; then
		if ./"${i%.c}.out"; then
			counter=$((counter + 1))
		else
			echo "$REDfailed$NC to run"
		fi
	else
		echo "\n${i%.c}.c $REDfailed$NC to build\n"
	fi
done
# clean up
rm *.out
echo "$GREEN$counter$NC tests succeeded"

