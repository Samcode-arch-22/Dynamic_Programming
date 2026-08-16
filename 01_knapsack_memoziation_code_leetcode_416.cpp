class Solution {
public:

         int dp[202][20002];
        
        
        
    bool canPartition(vector<int>& nums,int n,int target) {
        
        // Base conditio
        
        
        if(target == 0){
            return true ;
        }
        if( n == 0){
            return false;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        

        
        // code from choice diagram
        if( nums[n-1] <= target ){
            return dp[n][target]= canPartition( nums,  n-1,  target-nums[n-1]) 
            || 
            canPartition(nums, n-1, target);
        }
        else {
             return dp[n][target] =  canPartition(nums, n - 1, target);
        }
    }

    // from here copy past from chatgpt
     bool canPartition(vector<int>& nums) {

         memset(dp,-1,sizeof(dp));

        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        // If total sum is odd, equal partition is impossible
        if(sum % 2 != 0){
            return false;
        }

        int target = sum / 2;
    

        return canPartition(nums, nums.size(), target);
    }
};