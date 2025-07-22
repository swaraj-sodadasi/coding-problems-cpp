#include <iostream>
#include <vector>
#include <algorithm> // For std::max
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

    // Kadane's Algorithm to find largest sum contiguous subarray
    int maxEndingHere = array[0];
    int maxSoFar = array[0];

    for (int i = 1; i < n; i++) {
        maxEndingHere = max(array[i], maxEndingHere + array[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    cout << "Largest sum contiguous subarray: " << maxSoFar << endl;

    return 0;
}
