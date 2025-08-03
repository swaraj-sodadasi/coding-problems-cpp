#include <iostream>
#include <vector>
#include <numeric> // For std::iota (optional, for easy array initialization)

using namespace std;

void cyclicallyRotateArray(vector<int>& arr) {
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
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    cyclicallyRotateArray(arr);

    cout << "Array after cyclic rotation: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}