#include <bits/stdc++.h>
using namespace std;

#define pb              push_back
#define ff              first
#define ss              second
#define ll              long long
#define f(i,n)          for(int i = 0; i < n; i++)
#define F(i,n)          for(ll i = 0; i < n; i++)
#define fx(i,x,n)       for(int i = x; i < n; i++)
#define endl            '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int a[n+1];
        map<int, int> mm;
        f(i,n)
            cin>>a[i];
        int dp[101][1001] = {0};
        int tab[n+1][n+1] ;//= {0};
        f(i,n)
            f(j,n)
                tab[i][j] = 0;
        
        f(i,n)
        {
            fx(j,i,n)
            {
                switch(j) 
                {
                    case 0:
                        tab[i][j] = 0;
                        break;
                    default:
                        tab[i][j] = tab[i][j-1];
                }
                if(mm.count(a[j]))
                {
                    if(mm[a[j]] == 1)
                        tab[i][j]++;
                    tab[i][j]++;
                }
                mm[a[j]]++;
            }
            mm.clear();
        }

        if(n>100)
            f(i,n+1)
            {
                dp[1][i] = tab[0][i-1];
                if(i>1 && i<101)
                    dp[i][1] = 0;
            }
        else
            fx(i,2,101)
            {
                dp[i][1] = 0;
                if(i<n+1)
                    dp[1][i] = tab[0][i-1];
            }

        fx(i,2,101)
        {
            fx(j,2,n+1)
            {
                int cost = mod;
                fx(p,1,j)
                    cost = min(cost, dp[i-1][p] + tab[p][j-1]);
                dp[i][j] = cost;
            }
        }

        int res = mod;
        fx(i,1,101)
            res = min(i*k + dp[i][n], res);
        cout<<res<<endl;
    }
    
    return 0;
}