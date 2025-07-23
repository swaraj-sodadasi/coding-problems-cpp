#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

void reverseArray(std::vector<int>& arr) {
    int n = arr.size();

    // Handle empty or single-element arrays (no reversal needed)
    if (n <= 1) {
        return;
    }

    int left = 0;
    int right = n - 1;

    // Continue swapping until left pointer crosses or meets the right pointer
    while (left < right) {
        // Swap elements at left and right pointers
        std::swap(arr[left], arr[right]);

        // Move pointers towards the center
        left++;
        right--;
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
    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Original Array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    reverseArray(arr);

    std::cout << "Reversed Array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}