#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubsetSum(vector<int> arr, int n, int sum){
        int dp[n+1][sum+1];
        for(int i=0; i<sum+1; ++i) dp[0][i] = 0;
        int zct = 0; dp[0][0] = 1;
        for(int i=1; i<n+1; ++i){
            if(arr[i-1]==0) zct++; 
            dp[i][0] = pow(2,zct);
        }

        for(int i=1; i<n+1; ++i)
            for(int j=1; j<sum+1; ++j){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S) return 0;
        if((sum-S)%2 != 0) return 0;
        int s1 = (sum - S)/2;
        return countSubsetSum(nums, n, s1);
    }
};