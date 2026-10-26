//NAVYA GUPTA 25/DA/047
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "NAVYA GUPTA ROLL NO 25/DA/047" << endl;
    cout << "0/1 Knapsack Problem using DP" << endl;

    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value: " << dp[n][W] << endl;

    return 0;
}