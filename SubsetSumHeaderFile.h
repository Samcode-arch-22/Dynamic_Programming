#ifndef SUBSET_SUM_H
#define SUBSET_SUM_H

#include <vector>
using namespace std;

bool subsetSum(vector<int> nums, int sum) {

    int n = nums.size();

    // Your DP code here

    return dp[n][sum];
}

#endif