#include <iostream>
#include <vector>
#include <unordered_set> // For std::unordered_set
#include <algorithm>     // For std::sort if you want sorted output from unordered_set

// Function to find duplicate elements in an array using a hash set
std::vector<int> findDuplicates(const std::vector<int>& arr) {
    std::unordered_set<int> seen_elements;
    std::unordered_set<int> duplicate_elements_set; // Use a set to ensure unique duplicates

    for (int element : arr) {
        // If the element is already in 'seen_elements', it's a duplicate
        if (seen_elements.count(element)) {
            duplicate_elements_set.insert(element);
        } else {
            // Otherwise, add it to 'seen_elements'
            seen_elements.insert(element);
        }
    }

    // Convert the set of duplicate elements to a vector for returning
    std::vector<int> result(duplicate_elements_set.begin(), duplicate_elements_set.end());
    
    // Optional: If you want the output to be sorted
    std::sort(result.begin(), result.end());

    return result;
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

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    printVector("Original Array", arr);

    std::vector<int> duplicates = findDuplicates(arr);

    printVector("Duplicate Elements", duplicates);

    return 0;
}