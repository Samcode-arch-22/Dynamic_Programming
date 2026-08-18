#include <iostream>
#include <vector>
#include <climits>
#include "SubsetSumHeaderFile.h"

using namespace std;

class Solution {
public:

    int MinSubsetSumDiff(vector<int> nums) {

        int n = nums.size();

        int range = 0;

        for(int i = 0; i < n; i++) {
            range += nums[i];
        }

        vector<int> v = subsetSum(nums, range);

        int mn = INT_MAX;

        for(int i = 0; i < v.size(); i++) {
            mn = min(mn, range - 2 * v[i]);
        }

        return mn;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 6, 11, 5};

    cout << "Minimum Subset Sum Difference: "
         << obj.MinSubsetSumDiff(nums);

    return 0;
}