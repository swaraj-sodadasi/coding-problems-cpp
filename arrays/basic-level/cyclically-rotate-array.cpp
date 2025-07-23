#include <iostream>
#include <vector>
#include <numeric> // For std::iota (optional, for easy array initialization)

void cyclicallyRotateArray(std::vector<int>& arr) {
    if (arr.empty()) {
        return; // No rotation needed for an empty array
    }

    int n = arr.size();
    int lastElement = arr[n - 1]; // Store the last element

    // Shift all elements from right to left by one position
    for (int i = n - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }

    arr[0] = lastElement; // Place the stored last element at the beginning
}

int main() {
    // Dynamic input for array size
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array size must be positive." << std::endl;
        return 0;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Original Array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    cyclicallyRotateArray(arr);

    std::cout << "Array after cyclic rotation: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}