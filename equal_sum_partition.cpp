#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        bool equalsumpartition(vector<int> nums){

            int n = nums.size();
            int total = 0;

            for(int i = 0; i < n; i++){
                 total += nums[i];
            }

            int target = total/2;
             if(total%2 != 0){
                return false;
                        }

            bool dp[n+1][target+1];
            
            for( int i = 0 ;  i < n+1; i++ ){
                for(int j = 0; j< target+1; j++){
                    if(j==0){
                        dp[i][j]= true;
                    }
                }
            }
            for(int i = 1; i < n+1; i++){
                for(int j = 1; j < target+1; j++){
                    if(nums[i-1] <= j){
                        dp[i][j] = dp[i-1][j-nums[i-1]] 
                                    ||
                                    dp[i-1][j];
                    }
                    else{
                        dp[i][j]= dp[i-1][j];
                    }
                    
                }
            }
            return dp[n][target];
        }
};
int main() {

    Solution obj;

    vector<int> nums = {1, 5, 11, 5};

    bool result = obj.equalsumpartition(nums);

    if(result) {
        cout << "Equal partition is possible" << endl;
    }
    else {
        cout << "Equal partition is not possible" << endl;
    }

    return 0;
}