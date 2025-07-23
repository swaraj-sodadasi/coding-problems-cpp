#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

void sort012(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return; // No sorting needed for 0 or 1 element
    }

    int low = 0;   // Pointer for the 0s section
    int mid = 0;   // Pointer for the current element being examined
    int high = n - 1; // Pointer for the 2s section

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                // If current element is 0, swap it with element at low pointer
                // and move both low and mid pointers forward.
                std::swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                // If current element is 1, it's already in its correct relative position,
                // just move mid pointer forward.
                mid++;
                break;
            case 2:
                // If current element is 2, swap it with element at high pointer
                // and move high pointer backward. Don't increment mid, as the swapped
                // element at mid needs to be re-evaluated.
                std::swap(arr[mid], arr[high]);
                high--;
                break;
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
    std::cout << "Enter " << n << " integers (only 0, 1, or 2):" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 2) {
            std::cerr << "Error: Please enter only 0, 1, or 2." << std::endl;
            return 1; // Exit with error
        }
    }

    std::cout << "Original Array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    sort012(arr);

    std::cout << "Sorted Array (0s, 1s, 2s): ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}