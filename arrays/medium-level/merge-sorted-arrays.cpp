#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min, std::max (though not directly used in the final version's core logic)

// Function to merge two sorted arrays
void mergeSortedArrays(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n) {
    // Pointers for nums1's effective elements, nums2, and the merged position
    int p1 = m - 1;        // Points to the last valid element in nums1
    int p2 = n - 1;        // Points to the last element in nums2
    int p_merged = m + n - 1; // Points to the last position in nums1 where elements will be placed

    // Iterate while there are elements to compare in both arrays
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            // Place the larger element from nums1 at the merged position
            nums1[p_merged] = nums1[p1];
            p1--; // Move to the previous element in nums1
        } else {
            // Place the larger or equal element from nums2 at the merged position
            nums1[p_merged] = nums2[p2];
            p2--; // Move to the previous element in nums2
        }
        p_merged--; // Move to the next available position for merging
    }

    // If there are remaining elements in nums2, copy them to nums1's beginning
    // (This handles cases where nums2 elements are smaller than all remaining nums1 elements)
    while (p2 >= 0) {
        nums1[p_merged] = nums2[p2];
        p2--;
        p_merged--;
    }
    // No need to handle remaining elements in nums1 (p1 >= 0) because
    // they are already in their correct sorted positions at the beginning of nums1.
}

// Helper function to print vectors
void printVector(const std::string& label, const std::vector<int>& vec) {
    std::cout << label << ": [";
    for (size_t l = 0; l < vec.size(); ++l) {
        std::cout << vec[l];
        if (l < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "--- Merge Two Sorted Arrays ---" << std::endl;

    // Get dynamic input for nums1
    int m;
    std::cout << "Enter the number of initial elements in nums1 (m): ";
    std::cin >> m;

    if (m < 0) {
        std::cerr << "Error: m cannot be negative." << std::endl;
        return 1;
    }

    std::vector<int> nums1_initial(m);
    if (m > 0) {
        std::cout << "Enter " << m << " sorted integers for nums1 (initial part):" << std::endl;
        for (int i = 0; i < m; ++i) {
            std::cin >> nums1_initial[i];
        }
    }

    // Get dynamic input for nums2
    int n;
    std::cout << "Enter the number of elements in nums2 (n): ";
    std::cin >> n;

    if (n < 0) {
        std::cerr << "Error: n cannot be negative." << std::endl;
        return 1;
    }

    std::vector<int> nums2(n);
    if (n > 0) {
        std::cout << "Enter " << n << " sorted integers for nums2:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cin >> nums2[i];
        }
    }
    
    // Create nums1 with enough capacity (m + n) and copy initial elements
    std::vector<int> nums1(m + n);
    for(int i = 0; i < m; ++i) {
        nums1[i] = nums1_initial[i];
    }
    // The remaining n elements are implicitly 0s, which is fine as they'll be overwritten

    printVector("Nums1 (initial, first " + std::to_string(m) + " elements are relevant)", nums1);
    printVector("Nums2", nums2);

    mergeSortedArrays(nums1, m, nums2, n);

    printVector("Merged Nums1", nums1);

    return 0;
}