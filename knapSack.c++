#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(const vector<int>& values, const vector<int>& weights, int W) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;

    int maxValue = knapsack(values, weights, W);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
