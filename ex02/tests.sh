#!/bin/bash

# Path to the compiled program
PROGRAM="./PmergeMe"

# Ensure the program exists
if [ ! -f "$PROGRAM" ]; then
    echo "Error: Program '$PROGRAM' not found. Please compile it first."
    exit 1
fi

# Test descriptions and inputs
DESCRIPTIONS=(
    "Valid input, small set"
    "Valid input, already sorted"
    "Valid input, reverse order"
    "Valid input, large set"
    "Invalid input, contains non-numeric"
    "Invalid input, contains negative"
    "Invalid input, empty input"
    "Edge case, single number"
    "Edge case, two numbers"
    "Large input, performance test"
)

INPUTS=(
    "1 4 3 2"
    "1 2 3 4"
    "4 3 2 1"
    "10 20 5 7 15 1 3 50"
    "1 2 x 4"
    "1 -2 3 4"
    ""
    "42"
    "2 1"
	"$(seq 1 10000 | awk 'BEGIN {srand()} {print $0, rand()}' | sort -k2 -n | cut -d' ' -f1 | tr '\n' ' ')"
)

# Function to run a single test case
run_test() {
    local description="$1"
    local input="$2"

    echo "Running test: $description"
    echo "Input: $input"
    if [ -z "$input" ]; then
        echo "No input provided. Running program without arguments..."
        $PROGRAM
    else
        $PROGRAM $input
    fi
    echo
}

# Iterate over all test cases
for i in "${!DESCRIPTIONS[@]}"; do
    run_test "${DESCRIPTIONS[i]}" "${INPUTS[i]}"
done

echo "All tests completed."
