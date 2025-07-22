#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> array(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    // Sort the array
    sort(array.begin(), array.end());

    // Find Kth minimum and Kth maximum elements
    int kthMin = array[k - 1];     // k-th smallest
    int kthMax = array[n - k];     // k-th largest

    cout << "Kth minimum element in the array: " << kthMin << endl;
    cout << "Kth maximum element in the array: " << kthMax << endl;

    return 0;
}
