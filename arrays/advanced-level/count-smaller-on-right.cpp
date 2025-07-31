#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort, std::pair, std::min, std::max (though not directly used in this exact implementation, good to include)

// Helper function to merge two sorted halves and count smaller elements
// This function modifies the 'pairs' vector and updates 'counts' array
void mergeAndCount(std::vector<std::pair<int, int>>& pairs, 
                   int low, int mid, int high, 
                   std::vector<int>& counts) {
    
    // Temporary vector to hold merged results
    std::vector<std::pair<int, int>> temp;
    temp.reserve(high - low + 1); // Pre-allocate memory

    int i = low;      // Pointer for the left sorted half [low...mid]
    int j = mid + 1;  // Pointer for the right sorted half [mid+1...high]

    // Iterate through both halves
    while (i <= mid && j <= high) {
        // If element from left half is less than or equal to element from right half
        if (pairs[i].first <= pairs[j].first) {
            // All elements from pairs[j] onwards in the right half are greater than or equal to pairs[i].
            // The number of elements from the right half already processed (which were smaller than pairs[i])
            // is (j - (mid + 1)). Add this to the count for the original index of pairs[i].
            counts[pairs[i].second] += (j - (mid + 1));
            temp.push_back(pairs[i]);
            i++;
        } else { // Element from right half is smaller
            temp.push_back(pairs[j]);
            j++;
        }
    }

    // Copy remaining elements from the left half (if any)
    while (i <= mid) {
        // All elements from the right half have been processed and were smaller than or equal to current elements in left half.
        // So, all (high - (mid + 1) + 1) elements from the right sub-array are effectively smaller or were passed by.
        // A more precise way (and what j - (mid + 1) captures if j reaches high + 1)
        // is that all elements initially in the right half have been considered.
        // So, we add the total count of elements in the right half to the current element's count.
        counts[pairs[i].second] += (high - (mid + 1) + 1); 
        temp.push_back(pairs[i]);
        i++;
    }

    // Copy remaining elements from the right half (if any)
    // No counts are updated here because any remaining elements in the right half are larger
    // than anything that could be left in the left half.
    while (j <= high) {
        temp.push_back(pairs[j]);
        j++;
    }

    // Copy the merged and sorted elements back to the original 'pairs' vector
    for (int k = low; k <= high; ++k) {
        pairs[k] = temp[k - low];
    }
}

// Main merge sort function for counting smaller elements
void mergeSort(std::vector<std::pair<int, int>>& pairs, 
               int low, int high, 
               std::vector<int>& counts) {
    if (low >= high) {
        return; // Base case: single element or empty range
    }

    int mid = low + (high - low) / 2;
    
    // Recursively sort and count for left and right halves
    mergeSort(pairs, low, mid, counts);
    mergeSort(pairs, mid + 1, high, counts);

    // Merge the two sorted halves and update counts
    mergeAndCount(pairs, low, mid, high, counts);
}

// Main function to count smaller elements on the right
std::vector<int> countSmaller(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return {};
    }

    // Initialize counts array with zeros
    std::vector<int> counts(n, 0);

    // Create pairs of {value, original_index}
    std::vector<std::pair<int, int>> pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {nums[i], i};
    }

    // Perform merge sort with counting
    mergeSort(pairs, 0, n - 1, counts);

    return counts;
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
    std::cout << "--- Count Smaller Elements on Right ---" << std::endl;

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

    std::vector<int> counts = countSmaller(nums);

    printVector("Counts of Smaller Elements on Right", counts);

    // Example Test Cases (uncomment to try):
    /*
    std::vector<int> test1 = {5, 2, 6, 1};
    printVector("\nTest Case 1 Original", test1);
    printVector("Test Case 1 Counts", countSmaller(test1)); // Expected: [2, 1, 1, 0]

    std::vector<int> test2 = {-1};
    printVector("\nTest Case 2 Original", test2);
    printVector("Test Case 2 Counts", countSmaller(test2)); // Expected: [0]

    std::vector<int> test3 = {-1, -1};
    printVector("\nTest Case 3 Original", test3);
    printVector("Test Case 3 Counts", countSmaller(test3)); // Expected: [0, 0]

    std::vector<int> test4 = {1, 0, -1, 0, 1};
    printVector("\nTest Case 4 Original", test4);
    printVector("Test Case 4 Counts", countSmaller(test4)); // Expected: [3, 2, 0, 1, 0]

    std::vector<int> test5 = {26, 7, 25, 20, 11, 15, 23, 1, 13, 14, 27};
    printVector("\nTest Case 5 Original", test5);
    printVector("Test Case 5 Counts", countSmaller(test5)); // Expected: [10, 0, 8, 6, 3, 3, 4, 0, 0, 0, 0]
    */

    return 0;
}