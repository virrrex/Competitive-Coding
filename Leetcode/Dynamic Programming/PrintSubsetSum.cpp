#include <bits/stdc++.h>
using namespace std;

#define pb              push_back
#define ff              first
#define ss              second
#define ll              long long
#define f(i,n)          for(int i = 0; i < n; i++)
#define F(i,n)          for(ll i = 0; i < n; i++)
#define fx(i,x,n)       for(int i = x; i < n; i++)
#define Fx(i,x,n)       for(ll i = x; i < n; i++)
#define endl            '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x)          x.begin(), x.end()
#define sortall(x)      sort(all(x))
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

bool** dp;

void display(const vector<int>& v) 
{ 
    f(i, v.size()) 
        cout<<v[i]<<" ";
    cout<<endl;
} 

void printSubsetsRec(vi arr, int i, int sum, vector<int>& p) 
{ 
    // If we reached end and sum is non-zero. We print 
    // p[] only if arr[0] is equal to sun OR dp[0][sum] 
    // is true. 
    if (i == 1 && sum != 0 && dp[1][sum]) 
    { 
        p.push_back(arr[i]); 
        display(p); 
        return; 
    } 
  
    // If sum becomes 0 
    if (i == 1 && sum == 0) 
    { 
        display(p); 
        return; 
    } 
  
    // If given sum can be achieved after ignoring 
    // current element. 
    if (dp[i][sum]) 
    { 
        // Create a new vector to store path 
        vector<int> b = p; 
        printSubsetsRec(arr, i, sum, b); 
    } 
  
    // If given sum can be achieved after considering 
    // current element. 
    if (sum >= arr[i+1] && dp[i][sum-arr[i+1]]) 
    { 
        p.push_back(arr[i+1]); 
        printSubsetsRec(arr, i, sum-arr[i+1], p); 
    } 
} 

void subsetSum(vi arr, int n, int sum)
{
    bool dp[n+1][sum+1];
    f(i, sum+1)
        dp[0][i] = false;
    f(i, n+1)
        dp[i][0] = true;
    
    fx(i,1,n+1)
        fx(j,1,sum+1){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];
        }
    
    // f(i,n+1){f(j,sum+1)cout<<(dp[i][j]?"T ":"F "); cout<<endl;}
    if(dp[n][sum] == false) 
    { 
        cout<<"There are no subsets with sum "<<sum<<endl; 
        return; 
    } 
    vector<int> p; 
    printSubsetsRec(arr, n, sum, p); 
    
}

int main()
{
    rex;

    int n; n=9;
    vi arr = {5, 12, 3, 17, 1, 18, 15, 3, 17};
    // vi arr = {2, 3, 7, 8, 10};
    int sum; sum=6;
    subsetSum(arr, arr.size(), sum);

    return 0;
}