#include <iostream>
#include <vector>
#include <algorithm> // For std::max

int minJumps(const std::vector<int>& nums) {
    int n = nums.size();

    // Edge case: If array has 0 or 1 element, no jumps needed.
    if (n <= 1) {
        return 0;
    }

    // current_jump_end: The farthest index reachable with the current number of jumps.
    // farthest_reach: The maximum index that can be reached from any point visited so far.
    // jumps: Total jumps taken.
    int current_jump_end = 0;
    int farthest_reach = 0;
    int jumps = 0;

    // Iterate through the array. We stop at n-2 because if we reach n-1, we are at the end.
    // The last element doesn't need to initiate a jump.
    for (int i = 0; i < n - 1; ++i) {
        // Update the farthest index we can reach from the current position 'i'.
        farthest_reach = std::max(farthest_reach, i + nums[i]);

        // If we have reached the end of the current jump's coverage,
        // it means we must take a new jump.
        if (i == current_jump_end) {
            jumps++; // Take a jump
            current_jump_end = farthest_reach; // Set the new boundary for the next jump

            // Optimization: If the new jump's boundary reaches or surpasses the end,
            // we can stop early and return the jumps.
            if (current_jump_end >= n - 1) {
                return jumps;
            }
        }
    }

    // This line should theoretically not be reached if the problem guarantees reachability.
    // If not guaranteed, consider returning -1 here.
    return jumps;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array must contain at least one element for jumps." << std::endl;
        return 0;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " non-negative integers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Original Array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    int min_jumps = minJumps(arr);

    std::cout << "Minimum jumps to reach the end: " << min_jumps << std::endl;

    return 0;
}