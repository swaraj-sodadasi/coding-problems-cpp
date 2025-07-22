#include <iostream>
#include <vector>
using namespace std;

// Function to cyclically rotate an array by one position
void cyclicallyRotateByOne(vector<int>& array, int n) {
    // Save the last element
    int last = array[n - 1];
    // Shift all elements one position to the right
    for (int i = n - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    // Place the last element at the first position
    array[0] = last;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> array(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Cyclically rotate the array by one
    cyclicallyRotateByOne(array, n);

    cout << "Array after cyclically rotating by one:" << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
