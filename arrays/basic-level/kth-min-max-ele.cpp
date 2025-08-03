#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

// Function to find Kth smallest element
int findKthSmallest(vector<int>& arr, int k) {
    if (k <= 0 || k > arr.size()) {
        cerr << "Error: K is out of bounds for Kth smallest." << endl;
        return -1; // Indicate an error
    }
    sort(arr.begin(), arr.end()); // Sort the array
    return arr[k - 1]; // Kth smallest is at index k-1
}

// Function to find Kth largest element
int findKthLargest(vector<int>& arr, int k) {
    if (k <= 0 || k > arr.size()) {
        cerr << "Error: K is out of bounds for Kth largest." << endl;
        return -1; // Indicate an error
    }
    sort(arr.begin(), arr.end()); // Sort the array
    // Kth largest is at index (n - k)
    return arr[arr.size() - k];
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array must contain at least one element." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of K (for Kth smallest/largest): ";
    cin >> k;

    // Make a copy for Kth largest because std::sort modifies the original array
    // If you need to preserve the original array, always pass a copy or sort a copy.
    // Here, findKthSmallest modifies it first, then findKthLargest would re-sort
    // an already sorted array, which is fine, but if you want to apply to original state,
    // you'd need two copies or call a single function returning both.
    vector<int> arr_copy_for_largest = arr;


    int kthSmallest = findKthSmallest(arr, k); // arr is now sorted
    int kthLargest = findKthLargest(arr_copy_for_largest, k); // arr_copy_for_largest is now sorted


    if (kthSmallest != -1) { // Check for error from function
        cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
    }
    if (kthLargest != -1) { // Check for error from function
        cout << "The " << k << "th largest element is: " << kthLargest << endl;
    }

    return 0;
}