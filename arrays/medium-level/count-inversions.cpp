#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::max (though not directly used in the core logic here)

// Function to merge two halves and count inversions
long long mergeAndCount(std::vector<int>& arr, std::vector<int>& temp_arr, int left, int mid, int right) {
    int i = left;      // Starting index for left subarray
    int j = mid + 1;   // Starting index for right subarray
    int k = left;      // Starting index for merged array (in arr)
    long long inv_count = 0; // Counter for inversions

    // Copy elements to temp_arr for merging
    for (int idx = left; idx <= right; ++idx) {
        temp_arr[idx] = arr[idx];
    }

    while (i <= mid && j <= right) {
        if (temp_arr[i] <= temp_arr[j]) {
            // No inversion: current element from left half is smaller or equal
            arr[k++] = temp_arr[i++];
        } else {
            // Inversion found: current element from right half is smaller
            // This means temp_arr[j] forms an inversion with temp_arr[i]
            // and all remaining elements in the left subarray (temp_arr[i+1...mid])
            arr[k++] = temp_arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    // Copy remaining elements of left subarray (if any)
    while (i <= mid) {
        arr[k++] = temp_arr[i++];
    }

    // Copy remaining elements of right subarray (if any)
    while (j <= right) {
        arr[k++] = temp_arr[j++];
    }

    return inv_count;
}

// Recursive function to perform merge sort and count inversions
long long mergeSortAndCount(std::vector<int>& arr, std::vector<int>& temp_arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in left half
        inv_count += mergeSortAndCount(arr, temp_arr, left, mid);

        // Count inversions in right half
        inv_count += mergeSortAndCount(arr, temp_arr, mid + 1, right);

        // Count inversions during merge of two halves
        inv_count += mergeAndCount(arr, temp_arr, left, mid, right);
    }
    return inv_count;
}

// Main function to initiate inversion counting
long long countInversions(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return 0;
    }
    // Create a temporary array of the same size for merging
    std::vector<int> temp_arr(n);
    return mergeSortAndCount(arr, temp_arr, 0, n - 1);
}

int main() {
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

    std::cout << "Original Array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Create a copy to show the original array, as the array gets sorted by the function
    std::vector<int> arr_copy = arr; 
    long long inversions = countInversions(arr_copy);

    std::cout << "Number of inversions: " << inversions << std::endl;
    std::cout << "Array after sorting (from the process): ";
    for (int x : arr_copy) {
        std::cout << x << " ";
    }
    std::cout << std::endl;


    return 0;
}