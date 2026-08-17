#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int countsubsetsum(vector<int> arr, int sum) {

        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

        // Initialization
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {

                if(i == 0) {
                    dp[i][j] = 0;
                }
                else if(j == 0) {
                    dp[i][j] = 1;
                }
            }
        }

        // DP
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= sum; j++) {

                if(arr[i-1] <= j) {

                    dp[i][j] = dp[i-1][j-arr[i-1]]
                             + dp[i-1][j];
                }
                else {

                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }
};

int main() {

    Solution obj;

    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int sum = 10;

    int result = obj.countsubsetsum(arr, sum);

    cout << "Number of subsets with sum " << sum
         << " = " << result << endl;

    return 0;
}