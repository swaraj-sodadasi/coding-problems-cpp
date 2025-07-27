#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max
#include <limits>    // Required for std::numeric_limits

// Function to find the maximum subarray sum using Kadane's Algorithm
int maxSubArraySum(const std::vector<int>& nums) {
    // Edge case: empty array
    if (nums.empty()) {
        return 0; // Or throw an exception, depending on requirements
    }

    // Initialize current_max to the first element
    // This handles cases where all numbers are negative correctly.
    int current_max = nums[0]; 
    
    // Initialize global_max to the first element
    // This is important because the maximum sum could be just a single negative number
    int global_max = nums[0]; 

    // Iterate starting from the second element
    for (size_t i = 1; i < nums.size(); ++i) {
        // Calculate the maximum sum ending at the current position:
        // Either start a new subarray (just nums[i])
        // Or extend the existing subarray (current_max + nums[i])
        current_max = std::max(nums[i], current_max + nums[i]);

        // Update the overall maximum sum found so far
        global_max = std::max(global_max, current_max);
    }

    return global_max;
}

// Helper function to print vectors
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
    // Dynamic input for the array
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array must contain at least one element." << std::endl;
        return 0;
    }

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    printVector("Original Array", nums);

    int max_sum = maxSubArraySum(nums);

    std::cout << "Maximum contiguous subarray sum: " << max_sum << std::endl;

    return 0;
}