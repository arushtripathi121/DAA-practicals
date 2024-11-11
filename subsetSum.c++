#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(const vector<int>& S, int T) {
    int n = S.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(T + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= T; j++) {
            if (S[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - S[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][T];
}

int main() {
    vector<int> S = {3, 34, 4, 12, 5, 2};
    int T = 9;

    if (subsetSum(S, T)) {
        cout << "Subset with sum " << T << " exists." << endl;
    } else {
        cout << "Subset with sum " << T << " does not exist." << endl;
    }

    return 0;
}
