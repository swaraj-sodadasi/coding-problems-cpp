#include <iostream>
#include <vector>
#include <algorithm> // For std::sort (if arrays were unsorted, but here they are assumed sorted)

// Function to find the Intersection of two sorted arrays
std::vector<int> findIntersection(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> intersection_result;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        // Skip duplicates in arr1
        if (i > 0 && arr1[i] == arr1[i - 1]) {
            i++;
            continue;
        }
        // Skip duplicates in arr2
        if (j > 0 && arr2[j] == arr2[j - 1]) {
            j++;
            continue;
        }

        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else { // arr1[i] == arr2[j]
            intersection_result.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return intersection_result;
}

// Function to find the Union of two sorted arrays
std::vector<int> findUnion(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> union_result;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        // Skip duplicates in arr1, ensuring not to go out of bounds or compare with non-existent previous
        if (i > 0 && arr1[i] == arr1[i - 1]) {
            i++;
            continue;
        }
        // Skip duplicates in arr2
        if (j > 0 && arr2[j] == arr2[j - 1]) {
            j++;
            continue;
        }

        if (arr1[i] < arr2[j]) {
            union_result.push_back(arr1[i]);
            i++;
        } else if (arr1[i] > arr2[j]) {
            union_result.push_back(arr2[j]);
            j++;
        } else { // arr1[i] == arr2[j]
            union_result.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements from arr1 (with duplicate handling)
    while (i < n1) {
        if (i > 0 && arr1[i] == arr1[i - 1]) { // Check for duplicates against previous element
            i++;
            continue;
        }
        union_result.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements from arr2 (with duplicate handling)
    while (j < n2) {
        if (j > 0 && arr2[j] == arr2[j - 1]) { // Check for duplicates against previous element
            j++;
            continue;
        }
        union_result.push_back(arr2[j]);
        j++;
    }

    return union_result;
}

// Helper function to print vectors
void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": [";
    for (size_t k = 0; k < vec.size(); ++k) {
        std::cout << vec[k];
        if (k < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    int n1, n2;

    std::cout << "Enter size of array 1: ";
    std::cin >> n1;
    std::vector<int> arr1(n1);
    std::cout << "Enter " << n1 << " sorted integers for array 1:" << std::endl;
    for (int i = 0; i < n1; ++i) {
        std::cin >> arr1[i];
    }

    std::cout << "Enter size of array 2: ";
    std::cin >> n2;
    std::vector<int> arr2(n2);
    std::cout << "Enter " << n2 << " sorted integers for array 2:" << std::endl;
    for (int i = 0; i < n2; ++i) {
        std::cin >> arr2[i];
    }

    printVector("Array 1", arr1);
    printVector("Array 2", arr2);

    std::vector<int> union_result = findUnion(arr1, arr2);
    std::vector<int> intersection_result = findIntersection(arr1, arr2);

    printVector("Union", union_result);
    printVector("Intersection", intersection_result);

    return 0;
}