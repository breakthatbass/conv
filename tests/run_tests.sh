#!/bin/bash

# colors for printing
RED='\033[1;31m'
GREEN='\033[1;32m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

# dependency files
test_files='../src/conv.c ../src/helpers.c'

# make this script have permission to run src files
chmod -R 777 ../src/*.c

counter=0

# start timer
start=$SECONDS
# the emojis and colors are cool but they slow the whole process down
# if there are multiple large files to run, they would have to be removed

for i in *_tests.c
do
	echo "${BLUE}building${NC} ${i}"
	if gcc "$i" $test_files -o "${i%.c}.out"; then
		echo "\n📦 build ${GREEN}succeeded${NC}\n"
		echo "  ${BLUE}->  running${NC} ${i%.c} file"
		if ./"${i%.c}.out"; then
			counter=$((counter + 1))
		fi
	else
		echo "\n🚨 build ${RED}failed${NC}\n"
	fi
done

# clean up
rm *.out

# stop timer
duration=$(( SECONDS - start )) #unfortunately bash can't do floats

if [ $counter -eq 0 ]
then
	echo "$RED$counter$NC test files succeeded"
else
	echo "$GREEN$counter$NC test files succeeded"
	echo "\nAll tests compiled, ran, and cleaned up in ${duration} seconds"
fi

