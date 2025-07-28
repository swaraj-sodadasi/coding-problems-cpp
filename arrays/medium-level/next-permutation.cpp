#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap and std::reverse

// Function to find the next lexicographically greater permutation
void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) { // A single element or empty array has no next permutation
        return;
    }

    // Step 1: Find the first decreasing element from the right (pivot)
    int i = n - 2; // Start from the second-to-last element
    while (i >= 0 && nums[i] >= nums[i+1]) {
        i--;
    }

    // If 'i' is found (not -1), then we found a pivot
    if (i >= 0) {
        // Step 2: Find the smallest element to the right of pivot that is greater than pivot
        int j = n - 1; // Start from the last element
        while (j > i && nums[j] <= nums[i]) { // j must be to the right of i, and nums[j] must be greater than nums[i]
            j--;
        }
        
        // Step 3: Swap nums[i] and nums[j]
        std::swap(nums[i], nums[j]);
    }
    
    // Step 4: Reverse the suffix starting from i+1 to the end
    // If no pivot was found (i.e., array was in decreasing order), i will be -1.
    // In that case, we reverse the whole array (from 0 to n-1).
    // If a pivot was found, we reverse from i+1 to n-1.
    std::reverse(nums.begin() + i + 1, nums.end());
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
    std::cout << "--- Next Permutation ---" << std::endl;

    // Dynamic input for the array
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array must contain at least one element." << std::endl;
        return 0;
    }

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " integers for the array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    printVector("Original Array", nums);

    nextPermutation(nums);

    printVector("Next Permutation", nums);

    // Example with all negative numbers to test robustness (still follows logic)
    // std::vector<int> test_neg = {-3, -2, -1};
    // printVector("Original Neg", test_neg);
    // nextPermutation(test_neg);
    // printVector("Next Permutation Neg", test_neg); // Expected: [-3, -1, -2]

    // Example with largest permutation
    // std::vector<int> test_largest = {3, 2, 1};
    // printVector("Original Largest", test_largest);
    // nextPermutation(test_largest);
    // printVector("Next Permutation Largest", test_largest); // Expected: [1, 2, 3]

    return 0;
}