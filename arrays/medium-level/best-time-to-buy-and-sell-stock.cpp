#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min and std::max
#include <limits>    // Required for std::numeric_limits

int maxProfit(const std::vector<int>& prices) {
    int n = prices.size();

    // If there are less than 2 days, no transaction can be made.
    if (n <= 1) {
        return 0;
    }

    // Initialize min_price to a very large value (or prices[0])
    int min_price = prices[0]; // Start with the first day's price as initial min
    int max_profit = 0;        // Initialize max_profit to 0

    // Iterate from the second day onwards (day 1)
    for (int i = 1; i < n; ++i) {
        // Update the minimum price found so far
        min_price = std::min(min_price, prices[i]);

        // Calculate the profit if we sell today (prices[i]) and bought at min_price
        int current_profit = prices[i] - min_price;

        // Update the maximum profit found overall
        max_profit = std::max(max_profit, current_profit);
    }

    return max_profit;
}

int main() {
    int n;
    std::cout << "Enter the number of days: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Number of days must be positive." << std::endl;
        return 0;
    }

    std::vector<int> prices(n);
    std::cout << "Enter " << n << " stock prices for each day:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    std::cout << "Stock Prices: ";
    for (int p : prices) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    int profit = maxProfit(prices);

    std::cout << "Maximum profit: " << profit << std::endl;

    return 0;
}