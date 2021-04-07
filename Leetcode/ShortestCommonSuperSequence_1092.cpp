#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string x, string y) {
        int dp[1003][1003];
        int n = x.length(), m = y.length();
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(x[i-1] == y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int i=n, j=m;
        string ans = "";
        while(i>0 && j>0){
            if(x[i-1] == y[j-1]){
                ans = x[i-1] + ans;
                i--; j--;
            }
            else if(dp[i][j-1] > dp[i-1][j]){
                ans = y[j-1] + ans;
                j--;
            }
            else{
                ans = x[i-1] + ans;
                i--;
            }
        }
        while(i>0){
            ans = x[i-1] + ans;
            i--;
        }
        while(j>0){
            ans = y[j-1] + ans;
            j--;
        }
        return ans;
    }
};