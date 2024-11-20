#!/bin/bash

# Function to run a test and display the result
run_test() {
    input="$1"
    expected_output="$2"

    # Display the test case input
    echo "Test case: $input"
    
    # Run the RPN program with the provided input and capture the output
    actual_output=$(./RPN "$input" 2>&1)  # 2>&1 to capture both stdout and stderr

    # Display the result of the test
    if [[ "$actual_output" == "$expected_output" ]]; then
        echo "Result: PASSED"
    else
        echo "Result: FAILED"
        echo "Expected: $expected_output"
        echo "Got: $actual_output"
    fi
    echo ""  # Blank line between tests
}

# Test cases
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "7 7 * 7 -" "42"
run_test "1 2 * 2 / 2 * 2 4 - +" "0"
run_test "(1 + 1)" "Error: Invalid input."
run_test "5 5 * 5 *" "125"
run_test "3 3 3 * +" "12"
run_test "9 3 /" "3"
run_test "1 2 3 + *" "5"
run_test "5 0 /" "Error: Division by 0 is invalid."  # Testing division by zero

# Additional invalid cases
run_test "1 2 + +" "Error: Not enough operands for operation."  # Too many operators
run_test "1 + 1" "Error: Not enough operands for operation."    # Not enough operands
run_test "a b +" "Error: Invalid input."    # Invalid characters
