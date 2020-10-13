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
    
    int n; cin>>n; char val;
    vector<vector<char>> bricks;
    f(i,n){
        vector<char> temp;
        f(j,n){
            cin>>val;
            temp.pb(val);
        }
        bricks.pb(temp);
        temp.clear();
    }
    
    f(i,n)
        sort(bricks[i].begin(), bricks[i].end());
    char tt;
    for(int x = 0; x<n; x++){
        f(i,n){
            for(int j=i+1; j<n; j++){
                if(bricks[i][x] > bricks[j][x])
                {
                    tt = bricks[i][x];
                    bricks[i][x] = bricks[j][x];
                    bricks[j][x] = tt;
                }
            }
        }
    }
    cout<<endl;
    f(i,n){
        f(j,n)
            cout<<bricks[i][j]<<" ";
        cout<<endl;
    }

    int rows = 0, cols = 0, diags = 0, ans;
    for(int i=n-1; i>=0; i--)
    {
        if(bricks[n-1][i] == 'D')
            cols++;
        else
            break;    
            
    }
    for(int i=n-1; i>=0; i--)
    {
        if(bricks[i][n-1] == 'D')
            rows++;
        else
            break;    
            
    }
    for(int i=n-1; i>=0; i--)
    {
        if(bricks[i][i] == 'D')
            diags++;
        else
            break;    
            
    }
    ans = min(rows, cols);
    ans = min(ans, diags);
    cout<<ans<<endl;
    return 0;
}