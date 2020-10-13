#include <bits/stdc++.h>
using namespace std;

#define pb      push_back
#define ff      first
#define ss      second
#define ll      long long
#define f(i,n)  for(int i = 0; i < n; i++)
#define F(i,n)  for(ll i = 0; i < n; i++)
#define endl    '\n'
#define mod     1000000007
#define rex     ios_base::sync_with_stdio(0);cin.tie(0)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;


vector<int> solve (int A0, vector<long long> X, int N, int Q)
{
   
    ll maxX = *max_element(X.begin(), X.end());
   
    vector<ll> a;
    a.push_back(A0);
   
    for(int i = 1; i < N; i++)
    {
        ll temp = 0;
        if(i&1)
        {
                temp = 3*a[i-1] + 1;
                if(temp > 1e18)
                    break;
                a.push_back(temp);
        }
        else
        {
                temp = 2*a[i-1] + 3*a[i-2];
                if(temp > 1e18)
                    break;
                a.push_back(temp);
        }
    }
    
    vector<int> ans;
    for(int i = 0; i < Q; i++)
    {
        ll x = X[i];
        for(int j = a.size()-1; j >= 0; j--)
        {
            if(a[j] <= x)
                x -= a[j];
        }
        if(x == 0)
            ans.push_back(1);
        else
            ans.push_back(0);
    }
        
        return ans;
}

int main()
{
    rex;
    vll x = {63};
    vi ans = solve(2, x, 10, 1);    //2 7 20 61 
    f(i,1) cout<<ans[i]<<" ";
    return 0;
}