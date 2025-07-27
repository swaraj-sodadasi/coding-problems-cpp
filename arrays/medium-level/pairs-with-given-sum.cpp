#include <iostream>
#include <vector>
#include <unordered_set> // For std::unordered_set
#include <set>           // For std::set to store unique pairs in sorted order
#include <utility>       // For std::pair
#include <algorithm>     // For std::min and std::max

// Function to find pairs with a given sum using a hash set
std::vector<std::pair<int, int>> findPairsWithSum(const std::vector<int>& arr, int target_sum) {
    // Use an unordered_set to quickly check for seen elements
    std::unordered_set<int> seen_elements;
    
    // Use a set of pairs to store unique pairs and automatically keep them sorted
    // std::pair defaultly sorts by first element, then second.
    std::set<std::pair<int, int>> result_pairs_set;

    for (int num : arr) {
        int complement = target_sum - num;

        // Check if the complement has been seen before
        if (seen_elements.count(complement)) {
            // Found a pair! Insert it into the result set, ensuring the order for uniqueness
            result_pairs_set.insert({std::min(num, complement), std::max(num, complement)});
        }
        
        // Add the current number to the seen_elements set
        seen_elements.insert(num);
    }

    // Convert the set of pairs to a vector for returning
    std::vector<std::pair<int, int>> result_vector(result_pairs_set.begin(), result_pairs_set.end());
    
    return result_vector;
}

// Helper function to print vectors of pairs
void printPairs(const std::string& label, const std::vector<std::pair<int, int>>& pairs) {
    std::cout << label << ": [";
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
        if (i < pairs.size() - 1) {
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

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers for the array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int target_sum;
    std::cout << "Enter the target sum: ";
    std::cin >> target_sum;

    std::cout << "Original Array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Target Sum: " << target_sum << std::endl;

    std::vector<std::pair<int, int>> pairs = findPairsWithSum(arr, target_sum);

    printPairs("Pairs with sum " + std::to_string(target_sum), pairs);

    return 0;
}