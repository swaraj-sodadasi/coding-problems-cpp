#include <iostream>
#include <vector>
#include <string> // For std::to_string

// Function to multiply res[] (a large number) by a standard integer x
// res[] stores digits of a large number in reverse order (least significant digit first)
void multiply(std::vector<int>& res, int x, int& res_size) {
    long long carry = 0; // Use long long for carry to prevent overflow for intermediate values

    // Iterate through each digit of 'res'
    for (int i = 0; i < res_size; i++) {
        long long prod = static_cast<long long>(res[i]) * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Update carry
        carry = prod / 10;
    }

    // After multiplying all existing digits, handle any remaining carry
    while (carry > 0) {
        // If the vector doesn't have enough capacity, append new digits
        // This is implicitly handled by vector::push_back or accessing an element if capacity exists
        // However, a more explicit check or pre-reserving capacity might be done for performance.
        // For simplicity, directly push_back, vector will handle allocation.
        res.push_back(carry % 10);
        carry = carry / 10;
        res_size++;
    }
}

// Function to calculate and print factorial of a given non-negative integer n
// The result will be printed as a large number (string of digits)
void calculateAndPrintFactorial(int n) {
    if (n < 0) {
        std::cout << "Factorial for " << n << ": Not defined for negative numbers." << std::endl;
        return;
    }
    if (n == 0) {
        std::cout << "Factorial for " << n << ": 1" << std::endl;
        return;
    }

    // Use a vector to store digits of the factorial result.
    // Digits are stored in reverse order (e.g., 120 is stored as {0, 2, 1}).
    std::vector<int> res;
    // Initial guess for capacity. Can be adjusted based on expected max N.
    // For N=100, approx 158 digits. For N=5000, approx 16326 digits.
    res.reserve(20000); 

    res.push_back(1); // Initialize result for 1!
    int res_size = 1; // Current number of digits in 'res'

    // Multiply 'res' by numbers from 2 up to n
    for (int x = 2; x <= n; x++) {
        multiply(res, x, res_size);
    }

    // Print the result (digits are stored in reverse order, so print from end to start)
    std::cout << "Factorial for " << n << ": ";
    for (int i = res_size - 1; i >= 0; i--) {
        std::cout << res[i];
    }
    std::cout << std::endl;
}

// Helper function to print vectors (for input array visualization)
void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": [";
    for (size_t l = 0; l < vec.size(); ++l) {
        std::cout << vec[l];
        if (l < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "--- Factorials of Numbers in an Array ---" << std::endl;

    // Get dynamic input for the array of numbers
    int num_elements;
    std::cout << "Enter the number of integers in the array for which to calculate factorials: ";
    std::cin >> num_elements;

    if (num_elements <= 0) {
        std::cout << "Array must contain at least one element." << std::endl;
        return 0;
    }

    std::vector<int> input_numbers(num_elements);
    std::cout << "Enter " << num_elements << " non-negative integers:" << std::endl;
    for (int i = 0; i < num_elements; ++i) {
        std::cin >> input_numbers[i];
    }

    printVector("Input Array", input_numbers);
    std::cout << "\nCalculating Factorials:\n";

    // Calculate and print factorial for each number in the input array
    for (int num : input_numbers) {
        calculateAndPrintFactorial(num);
    }

    // Example Test Cases (uncomment to try):
    /*
    std::cout << "\n--- Predefined Test Cases ---\n";
    std::vector<int> test_cases1 = {0, 5, 10};
    printVector("Test Case 1 Input", test_cases1);
    std::cout << "Calculating Factorials for Test Case 1:\n";
    for (int num : test_cases1) {
        calculateAndPrintFactorial(num);
    }

    std::vector<int> test_cases2 = {20, 50}; // 50! is very long!
    printVector("\nTest Case 2 Input", test_cases2);
    std::cout << "Calculating Factorials for Test Case 2:\n";
    for (int num : test_cases2) {
        calculateAndPrintFactorial(num);
    }

    std::vector<int> test_cases3 = {-3, 4, 0}; // Includes a negative number
    printVector("\nTest Case 3 Input", test_cases3);
    std::cout << "Calculating Factorials for Test Case 3:\n";
    for (int num : test_cases3) {
        calculateAndPrintFactorial(num);
    }
    */

    return 0;
}