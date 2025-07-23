#include <iostream>
#include <vector>
#include <algorithm> // For std::max

int kadane(const std::vector<int>& nums) {
    if (nums.empty()) {
        // According to problem statement, contiguous subarray must contain at least one number.
        // If the array is empty, there are no subarrays, so this case should ideally not happen
        // or return a sentinel value, or throw an exception.
        // For this problem, let's assume non-empty array for standard Kadane's.
        // If an empty array is possible and needs to return a specific value, specify it.
        // A common practice for a problem asking for "largest sum" with "at least one number"
        // is that if all numbers are negative, the largest sum is the largest single negative number.
        // If the problem guarantees at least one element, then this 'if' block can be removed.
        return 0; // Or throw an error, depending on problem spec for empty array
    }

    int current_max = nums[0]; // Maximum sum ending at the current position
    int global_max = nums[0];  // Maximum sum found so far

    // Iterate starting from the second element
    for (size_t i = 1; i < nums.size(); ++i) {
        // Option 1: Extend the current subarray by adding nums[i]
        // Option 2: Start a new subarray from nums[i] (if nums[i] is greater than current_max + nums[i])
        current_max = std::max(nums[i], current_max + nums[i]);

        // Update the global maximum if current_max is greater
        global_max = std::max(global_max, current_max);
    }

    return global_max;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array size must be positive to find a contiguous subarray." << std::endl;
        return 0;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Original Array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    int max_subarray_sum = kadane(arr);

    std::cout << "Maximum contiguous subarray sum: " << max_subarray_sum << std::endl;

    return 0;
}