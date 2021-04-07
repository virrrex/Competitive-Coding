#include<bits/stdc++.h>
using namespace std;
int dp[2007][2007];
int palin[2007][2007];
class Solution {
public:

    bool isPalindrome(string &s, int i, int j){
        if(i >= j)
            return true;
        if(palin[i][j] != -1)
            return palin[i][j];
        if(s[i] == s[j])
            return palin[i][j] = isPalindrome(s, i+1, j-1);
        return palin[i][j] = false;
    }
    int PP(string &s, int i, int j){
        if(i >= j)
            return dp[i][j] = 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(isPalindrome(s,i,j))
            return dp[i][j] = 0;
        int mn = INT_MAX;
        for(int k=i; k<=j-1; k++){
            if(isPalindrome(s,i,k)){
                int tmp = PP(s,k+1,j) + 1;
                mn = min(mn, tmp);
            }
        }
        return dp[i][j] = mn;
    }
    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        memset(palin, -1, sizeof(palin));
        int ans = PP(s, 0, s.length()-1);
        return ans;
    }
};