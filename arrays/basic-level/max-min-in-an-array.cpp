#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::max
#include <limits>    // For std::numeric_limits

// Function to find the maximum and minimum elements in an array
// Returns a std::pair where first is min and second is max
std::pair<int, int> findMinMax(const std::vector<int>& arr) {
    if (arr.empty()) {
        // Return a sentinel value or throw an exception for an empty array.
        // Here, we'll return a pair of max/min possible values to indicate invalidity.
        // Or, if problem guarantees non-empty, this check can be removed.
        std::cerr << "Error: Array is empty. Cannot find min/max." << std::endl;
        return {std::numeric_limits<int>::max(), std::numeric_limits<int>::min()};
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
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array size must be positive to find min/max." << std::endl;
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

    std::pair<int, int> result = findMinMax(arr);

    // Check if the returned values indicate an error (e.g., empty array)
    if (result.first == std::numeric_limits<int>::max() && result.second == std::numeric_limits<int>::min()) {
        // This means the function encountered an empty array and returned the sentinel values.
        std::cout << "Could not determine min/max due to empty array." << std::endl;
    } else {
        std::cout << "Minimum element: " << result.first << std::endl;
        std::cout << "Maximum element: " << result.second << std::endl;
    }

    return 0;
}