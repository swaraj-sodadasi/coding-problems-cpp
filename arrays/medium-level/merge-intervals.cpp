#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort and std::max

// Custom comparator for sorting intervals by their start times
// If start times are equal, sort by end times (optional, but good practice)
bool compareIntervals(const std::vector<int>& a, const std::vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0]; // Sort by start time
    }
    return a[1] < b[1]; // If start times are equal, sort by end time
}

// Function to merge overlapping intervals
std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>>& intervals) {
    // Handle empty input
    if (intervals.empty()) {
        return {}; // Return an empty vector of vectors
    }

    // 1. Sort the intervals by their start times
    // std::sort uses operator< by default for pairs/vectors, which works correctly
    // by comparing first elements, then second.
    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    std::vector<std::vector<int>> merged_intervals;
    
    // 2. Add the first interval to the result as the initial merged interval
    merged_intervals.push_back(intervals[0]);

    // 3. Iterate through the rest of the sorted intervals
    for (size_t i = 1; i < intervals.size(); ++i) {
        // Get the last interval in our merged list
        std::vector<int>& current_merged_interval = merged_intervals.back();
        
        // Get the current interval from the sorted input list
        const std::vector<int>& next_interval = intervals[i];

        // Check for overlap: If the end of current_merged_interval is >= start of next_interval
        if (current_merged_interval[1] >= next_interval[0]) {
            // Overlap: Merge by updating the end time of current_merged_interval
            // The new end time is the maximum of the two original end times
            current_merged_interval[1] = std::max(current_merged_interval[1], next_interval[1]);
        } else {
            // No overlap: Add the next_interval as a new, separate interval
            merged_intervals.push_back(next_interval);
        }
    }

    return merged_intervals;
}

// Helper function to print a vector of intervals
void printIntervals(const std::string& label, const std::vector<std::vector<int>>& intervals) {
    std::cout << label << ": [";
    for (size_t i = 0; i < intervals.size(); ++i) {
        std::cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i < intervals.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "--- Merge Overlapping Intervals ---" << std::endl;

    // Dynamic input for intervals
    int num_intervals;
    std::cout << "Enter the number of intervals: ";
    std::cin >> num_intervals;

    if (num_intervals < 0) {
        std::cout << "Number of intervals cannot be negative." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> intervals(num_intervals, std::vector<int>(2));
    if (num_intervals > 0) {
        std::cout << "Enter " << num_intervals << " intervals (start and end for each):" << std::endl;
        for (int i = 0; i < num_intervals; ++i) {
            std::cout << "Interval " << i + 1 << " (start end): ";
            std::cin >> intervals[i][0] >> intervals[i][1];
            // Basic validation: ensure start <= end for a valid interval
            if (intervals[i][0] > intervals[i][1]) {
                std::cout << "Warning: Start time " << intervals[i][0] 
                          << " is greater than end time " << intervals[i][1] 
                          << ". Swapping them." << std::endl;
                std::swap(intervals[i][0], intervals[i][1]);
            }
        }
    }

    printIntervals("Original Intervals", intervals);

    std::vector<std::vector<int>> merged_result = mergeIntervals(intervals);

    printIntervals("Merged Intervals", merged_result);

    return 0;
}