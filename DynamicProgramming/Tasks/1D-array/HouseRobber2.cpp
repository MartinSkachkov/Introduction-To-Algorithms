class Solution {
public:
    int house_robber_1(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        if(n == 1){
            return nums[0];
        }else if(n == 2){
            return max(nums[0], nums[1]);
        }else{
            dp[0] = nums[0];
            dp[1] = max(nums[0],nums[1]);

            for(int i = 2; i < n; i++){
                dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            }
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        //split into two arrays
        vector<int> arr1;
        for(int i = 0; i < nums.size() - 1; i++){ //skip the last element
            arr1.push_back(nums[i]);
        }

        if(nums.size() > 1){
            vector<int> arr2;
            for(int i = 1; i < nums.size(); i++){ //skip the first element
                arr2.push_back(nums[i]);
            }

            return max(house_robber_1(arr1), house_robber_1(arr2));
        }

        return nums[0];
    }
};