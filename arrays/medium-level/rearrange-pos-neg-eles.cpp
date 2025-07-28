#include <iostream>
#include <vector>
#include <string> // For std::to_string

// Function to rearrange array alternating positive and negative numbers
// Modifies the input array 'nums' in-place
void rearrangeAlternating(std::vector<int>& nums) {
    std::vector<int> positives;
    std::vector<int> negatives;

    // Step 1: Separate numbers into positive and negative lists
    for (int x : nums) {
        if (x >= 0) { // Treating 0 as non-negative/positive for this problem
            positives.push_back(x);
        } else {
            negatives.push_back(x);
        }
    }

    // Step 2: Merge them back into the original nums array alternatingly
    nums.clear(); // Clear the original array to fill it with the rearranged elements

    int p_idx = 0; // Pointer for positives list
    int n_idx = 0; // Pointer for negatives list

    // Alternate as long as both lists have elements
    while (p_idx < positives.size() && n_idx < negatives.size()) {
        nums.push_back(positives[p_idx++]); // Add a positive
        nums.push_back(negatives[n_idx++]); // Add a negative
    }

    // Step 3: Append any remaining elements
    // Append remaining positives
    while (p_idx < positives.size()) {
        nums.push_back(positives[p_idx++]);
    }
    // Append remaining negatives
    while (n_idx < negatives.size()) {
        nums.push_back(negatives[n_idx++]);
    }
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
    std::cout << "--- Rearrange Array Alternating Positive and Negative ---" << std::endl;

    // Dynamic input for the array
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array must contain at least one element." << std::endl;
        return 0;
    }

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " integers (can be positive, negative, or zero):" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    printVector("Original Array", nums);

    rearrangeAlternating(nums);

    printVector("Rearranged Array", nums);

    // Test cases (uncomment to try):
    /*
    std::vector<int> test1 = {1, 2, 3, -4, -1, 4};
    printVector("\nTest Case 1 Original", test1);
    rearrangeAlternating(test1);
    printVector("Test Case 1 Rearranged", test1); // Expected: [1, -4, 2, -1, 3, 4]

    std::vector<int> test2 = {-5, -2, 5, -4, -1, 4};
    printVector("\nTest Case 2 Original", test2);
    rearrangeAlternating(test2);
    printVector("Test Case 2 Rearranged", test2); // Expected: [5, -5, 4, -2, -1, -4]

    std::vector<int> test3 = {1, 2, 3};
    printVector("\nTest Case 3 Original (All Positives)", test3);
    rearrangeAlternating(test3);
    printVector("Test Case 3 Rearranged", test3); // Expected: [1, 2, 3]

    std::vector<int> test4 = {-1, -2, -3};
    printVector("\nTest Case 4 Original (All Negatives)", test4);
    rearrangeAlternating(test4);
    printVector("Test Case 4 Rearranged", test4); // Expected: [-1, -2, -3]

    std::vector<int> test5 = {1, -1, 2, -2, 3, -3};
    printVector("\nTest Case 5 Original (Perfectly Alternating)", test5);
    rearrangeAlternating(test5);
    printVector("Test Case 5 Rearranged", test5); // Expected: [1, -1, 2, -2, 3, -3]

    std::vector<int> test6 = {1, 0, -1, -2};
    printVector("\nTest Case 6 Original (with zero)", test6);
    rearrangeAlternating(test6);
    printVector("Test Case 6 Rearranged", test6); // Expected: [1, -1, 0, -2] (if 0 is positive)
    */

    return 0;
}