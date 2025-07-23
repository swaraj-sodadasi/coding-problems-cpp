#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

// Function to find Kth smallest element
int findKthSmallest(std::vector<int>& arr, int k) {
    if (k <= 0 || k > arr.size()) {
        std::cerr << "Error: K is out of bounds for Kth smallest." << std::endl;
        return -1; // Indicate an error
    }
    std::sort(arr.begin(), arr.end()); // Sort the array
    return arr[k - 1]; // Kth smallest is at index k-1
}

// Function to find Kth largest element
int findKthLargest(std::vector<int>& arr, int k) {
    if (k <= 0 || k > arr.size()) {
        std::cerr << "Error: K is out of bounds for Kth largest." << std::endl;
        return -1; // Indicate an error
    }
    std::sort(arr.begin(), arr.end()); // Sort the array
    // Kth largest is at index (n - k)
    return arr[arr.size() - k];
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

    int k;
    std::cout << "Enter the value of K (for Kth smallest/largest): ";
    std::cin >> k;

    // Make a copy for Kth largest because std::sort modifies the original array
    // If you need to preserve the original array, always pass a copy or sort a copy.
    // Here, findKthSmallest modifies it first, then findKthLargest would re-sort
    // an already sorted array, which is fine, but if you want to apply to original state,
    // you'd need two copies or call a single function returning both.
    std::vector<int> arr_copy_for_largest = arr;


    int kthSmallest = findKthSmallest(arr, k); // arr is now sorted
    int kthLargest = findKthLargest(arr_copy_for_largest, k); // arr_copy_for_largest is now sorted


    if (kthSmallest != -1) { // Check for error from function
        std::cout << "The " << k << "th smallest element is: " << kthSmallest << std::endl;
    }
    if (kthLargest != -1) { // Check for error from function
        std::cout << "The " << k << "th largest element is: " << kthLargest << std::endl;
    }

    return 0;
}