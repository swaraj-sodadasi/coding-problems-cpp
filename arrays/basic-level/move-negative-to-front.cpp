#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

void moveNegativesToFront(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return; // No rearrangement needed for 0 or 1 element
    }

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        // If element at left is negative, it's already in place
        if (arr[left] < 0) {
            left++;
        }
        // If element at right is non-negative, it's already in place
        else if (arr[right] >= 0) {
            right--;
        }
        // If element at left is non-negative AND element at right is negative,
        // they are in the wrong positions, so swap them.
        else {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
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
    std::cout << "Enter " << n << " integers (can be positive, negative, or zero):" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Original Array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    moveNegativesToFront(arr);

    std::cout << "Array after moving negatives to front: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}