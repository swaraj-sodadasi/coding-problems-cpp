#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::max
#include <limits>    // For std::numeric_limits

using namespace std;

// Function to find the maximum and minimum elements in an array
// Returns a std::pair where first is min and second is max
pair<int, int> findMinMax(const vector<int>& arr) {
    if (arr.empty()) {
        // Return a sentinel value or throw an exception for an empty array.
        // Here, we'll return a pair of max/min possible values to indicate invalidity.
        // Or, if problem guarantees non-empty, this check can be removed.
        cerr << "Error: Array is empty. Cannot find min/max." << endl;
        return {numeric_limits<int>::max(), std::numeric_limits<int>::min()};
    }

    int minVal = arr[0]; // Initialize min with the first element
    int maxVal = arr[0]; // Initialize max with the first element

    // Iterate from the second element
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        // Alternatively, using std::min and std::max:
        // minVal = std::min(minVal, arr[i]);
        // maxVal = std::max(maxVal, arr[i]);
    }

    return {minVal, maxVal};
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive to find min/max." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    std::pair<int, int> result = findMinMax(arr);

    // Check if the returned values indicate an error (e.g., empty array)
    if (result.first == std::numeric_limits<int>::max() && result.second == std::numeric_limits<int>::min()) {
        // This means the function encountered an empty array and returned the sentinel values.
        cout << "Could not determine min/max due to empty array." << endl;
    } else {
        cout << "Minimum element: " << result.first << endl;
        cout << "Maximum element: " << result.second << endl;
    }

    return 0;
}