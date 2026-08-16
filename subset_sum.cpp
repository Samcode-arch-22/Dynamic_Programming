#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    bool subsetsum(vector<int> nums, int sum ){
        int n = nums.size();
        int dp [n+1][sum+1];

        /* initialization 
            for(int i = 0; i < n+1; i++){
                for(int j = 0; j< sum+1){
                    if( i == 0 || j == 0){
                        return false;
                    }
                }
            }
           This type of initialization not always correct so think care fully and write the code 
            (one more think that :- make table and check or verify the initialization code always ) */  
        for(int i = 0; i < n+1; i ++ ){
            for(int j = 0; j< sum + 1; j++){
                if( i == 0 ){
                    dp[i][j] = false;
                }
                if(j == 0){
                    dp[i][j] = true;
                }
            }
        }
        for(int i =1; i < n+1; i++ ){
            for(int j = 1; j < sum+1; j++){

            

        

        // code
        if(nums[i-1]<= j){
            dp[i][j] = dp[i][j-nums[i-1]] || dp[i-1][j];
        }
        else{
            dp[i][j] = dp[i-1][j];
        }
    }

    }
    return dp[n][sum];



    }
};
int main() {

    Solution obj;

    vector<int> nums = {2, 3, 7, 8, 10};

    int sum = 11;

    bool result = obj.subsetsum(nums, sum);

    if(result) {
        cout << "Subset with given sum exists";
    }
    else {
        cout << "Subset with given sum does not exist";
    }

    return 0;
} 