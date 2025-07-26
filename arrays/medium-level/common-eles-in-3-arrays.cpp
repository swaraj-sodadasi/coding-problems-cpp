#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort if input is unsorted

// Function to find common elements in three sorted arrays
std::vector<int> findCommonElements(const std::vector<int>& arr1,
                                     const std::vector<int>& arr2,
                                     const std::vector<int>& arr3) {
    std::vector<int> common_elements;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();

    int i = 0, j = 0, k = 0; // Pointers for arr1, arr2, arr3

    while (i < n1 && j < n2 && k < n3) {
        // --- Handle Duplicates ---
        // Skip duplicate elements in arr1
        while (i > 0 && i < n1 && arr1[i] == arr1[i - 1]) {
            i++;
        }
        // Skip duplicate elements in arr2
        while (j > 0 && j < n2 && arr2[j] == arr2[j - 1]) {
            j++;
        }
        // Skip duplicate elements in arr3
        while (k > 0 && k < n3 && arr3[k] == arr3[k - 1]) {
            k++;
        }

        // After skipping duplicates, recheck bounds as pointers might have moved past end
        if (i >= n1 || j >= n2 || k >= n3) {
            break;
        }
        // --- End Handle Duplicates ---

        // If all three elements are equal, it's a common element
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            common_elements.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
        // If arr1[i] is the smallest, increment its pointer
        else if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
            i++;
        }
        // If arr2[j] is the smallest, increment its pointer
        else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) {
            j++;
        }
        // If arr3[k] is the smallest, increment its pointer
        else {
            k++;
        }
    }
    return common_elements;
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

// Function to get dynamic array input from user
std::vector<int> getDynamicArrayInput(int array_num) {
    int size;
    std::cout << "Enter the size of Array " << array_num << ": ";
    std::cin >> size;

    if (size < 0) {
        std::cerr << "Error: Array size cannot be negative. Setting to 0." << std::endl;
        size = 0;
    }

    std::vector<int> arr(size);
    if (size > 0) {
        std::cout << "Enter " << size << " integers for Array " << array_num << " (please ensure they are sorted):" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cin >> arr[i];
        }
    }
    return arr;
}

int main() {
    std::cout << "--- Find Common Elements in 3 Arrays (Dynamic Input) ---" << std::endl;

    // Get dynamic input for Array 1
    std::vector<int> arr1 = getDynamicArrayInput(1);

    // Get dynamic input for Array 2
    std::vector<int> arr2 = getDynamicArrayInput(2);

    // Get dynamic input for Array 3
    std::vector<int> arr3 = getDynamicArrayInput(3);

    // Optional: If you cannot guarantee sorted input, uncomment these lines to sort
    // std::sort(arr1.begin(), arr1.end());
    // std::sort(arr2.begin(), arr2.end());
    // std::sort(arr3.begin(), arr3.end());
    // If you uncomment sorting, you might want to print the sorted arrays before finding common elements.

    printVector("Array 1", arr1);
    printVector("Array 2", arr2);
    printVector("Array 3", arr3);

    std::vector<int> commonElements = findCommonElements(arr1, arr2, arr3);

    printVector("Common Elements", commonElements);

    return 0;
}