//NAVYA GUPTA 25/DA/047
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout<<"NAVYA GUPTA ROLL NO 25/DA/047\n";
    cout<<"Matrix Chain Multiplication problem using DP\n";
    cout << "Enter number of dimensions: ";
    cin >> n;

    vector<int> p(n);
    cout << "Enter dimensions: ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // DP table to store minimum multiplication costs
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Consider chains of increasing length
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            //split point
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum number of multiplications: "
         << dp[1][n - 1] << endl;

    return 0;
}