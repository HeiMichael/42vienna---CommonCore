#!/bin/bash

make re
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
else
    echo "Compilation successful"
fi

tests=(
    "3 4 +"                                 # basic addition
    "5 2 -"                                 # basic subtraction
    "4 3 *"                                 # basic multiplication
    "8 2 /"                                 # basic division
    "3 4 + 2 *"                             # intermediate I (3 + 4) * 2
    "5 1 2 + 4 * + 3 -"                     # intermediate II 5 + (1 + 2) * 4 - 3
    "2 3 + 4 * 5 -"                         # intermediate III (2 + 3) * 4 - 5
    "3 4 5 + 7 / *"                         # expert I
    "8 23 5 1 / * 3 + 54 23 - - -"          # expert II
    "100 454 - 54 78 65 / / 54 544 - * +"   # expert III
    "-45 54 + 544 56 / -5 4 * * *"          # expert IV

    "42"                                    # edge case: single operand
    "0 5 +"                                 # edge case: zero addition
    "0 5 *"                                 # edge case: zero multiplication
    "5 -3 *"                                # edge case: negative number

    ""                                      # error case: empty input
    "5 0 /"                                 # error case: division by zero
    "5 7 g +"                               # error case: char in input
    "1 +"                                   # error case: insufficient operands
)

expected_outputs=(
    "7"
    "3"
    "12"
    "4"
    "14"
    "14"
    "15"
    "3.86"
    "-79"
    "-22404"
    "-1748.57"

    "42"
    "5"
    "0"
    "-15"

    "Error:"
    "Error:"
    "Error:"
    "Error:"
    "Error:"
)

for i in "${!tests[@]}"; do
    test="${tests[$i]}"
    expected_output="${expected_outputs[$i]}"

    echo "Test: $test"
    ./RPN "$test" > output.txt 2>&1  # Capture both stdout and stderr

    if [[ $expected_output == "Error:"* ]]; then
        if grep -q "^Error:" output.txt; then
            echo -e "\033[1;32mTest passed\033[0;m"
        else
            echo -e "\033[1;31mTest failed\033[0;m"
        fi
    else
        if diff <(echo "$expected_output") output.txt; then
            echo -e "\033[1;32mTest passed\033[0;m"
        else
            echo -e "\033[1;31mTest failed\033[0;m"
        fi
    fi
    echo "------"
done

rm output.txt