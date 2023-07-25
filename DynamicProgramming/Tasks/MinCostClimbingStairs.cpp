class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        dp[n]=0;
        dp[n-1]=cost[n-1];
        n-=2;

        while(n!=-1){
            dp[n] = min(cost[n]+dp[n+1],cost[n]+dp[n+2]);
            n--;
        }

        return min(dp[0],dp[1]);
    }
};