#include <iostream>
#include <vector>
#include <algorithm> // For std::sort, std::min, std::max
#include <limits>    // For std::numeric_limits

using namespace std;

int minimizeMaxDifference(vector<int>& arr, int k) {
    int n = arr.size();
    if (n <= 1) {
        return 0; // If 0 or 1 element, difference is 0
    }

    // 1. Sort the array
    std::sort(arr.begin(), arr.end());

    // 2. Initialize the answer with the original difference
    // This covers the case where all elements are modified in a way that
    // the original min (after +K) and original max (after -K) still define the range.
    int min_diff = arr[n - 1] - arr[0];

    // 3. Iterate to find the optimal new min/max pair
    // We consider each arr[i] as a potential point where elements before it
    // are increased by K, and elements from arr[i+1] are decreased by K.
    for (int i = 0; i < n - 1; ++i) {
        // Potential new minimum:
        // Either the original smallest element increased by K (arr[0] + K)
        // Or arr[i+1] (the next element) decreased by K
        int current_min_val = std::min(arr[0] + k, arr[i + 1] - k);

        // Potential new maximum:
        // Either the original largest element decreased by K (arr[n-1] - K)
        // Or arr[i] (the current element) increased by K
        int current_max_val = std::max(arr[n - 1] - k, arr[i] + k);

        // This condition checks if the chosen 'current_min_val' is actually less than
        // or equal to 'current_max_val'. If not, it means this combination of operations
        // results in an invalid range (min > max), which can happen if elements are very close.
        if (current_min_val <= current_max_val) {
            min_diff = std::min(min_diff, current_max_val - current_min_val);
        }
    }

    return min_diff;
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
    cout << "Enter the value of K: ";
    cin >> k;

    cout << "Original Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    int result_diff = minimizeMaxDifference(arr, k);

    cout << "Minimum possible difference: " << result_diff << endl;

    return 0;
}