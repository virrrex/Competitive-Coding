#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        int dp[n+1][sum+1];
        for(int i=0; i<n+1; ++i) dp[i][0] = 0;
        for(int i=0; i<sum+1; ++i) dp[0][i] = sum+3;
        for(int i=1; i<n+1; ++i)
            for(int j=1; j<sum+1; ++j){
                if(coins[i-1] <= j)
                    dp[i][j] = min(dp[i][j-coins[i-1]] + 1,  dp[i-1][j]);
                else 
                    dp[i][j] = dp[i-1][j];
            }
        return (dp[n][sum]>sum ? -1: dp[n][sum]);
    }
};