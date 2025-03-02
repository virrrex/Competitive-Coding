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
#define nl              '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x)          x.begin(), x.end()
#define sortall(x)      sort(all(x))
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define mem1(a)         memset(a,-1,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
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
        int n, m; cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m));
        f(i,n) f(j,m) cin>>a[i][j];

        f(i,n)  
            sortall(a[i]);

        vi ans;
        bool flag = false;
        f(i,n){
            flag = false;
            f(j,n){
                if(a[j][0] == i){
                    ans.pb(j);
                    flag = true;
                    break;
                }
            }
            if(flag == false)
                break;
        }

        if(flag == false){
            cout<<"-1\n";
        }
        else {
            f(i,n){
                flag = true;
                f(j,m-1){
                    if(a[i][j+1] - a[i][j] != n){
                        flag = false;
                        break;
                    }
                }
                if(flag == false)
                    break;
            }

            if(flag == false){
                cout<<"-1\n";
            }
            else {
                f(i,n) cout<<ans[i]+1<<" ";
                cout<<nl;
            }
        }
    }

    return 0;
}

// 3, 3

// ans: 3 2 1


// 5 4 7 => 2 5 7
// 8 1 3 => 1 3 8
// 2 0 9 => 0 4 9

// starting cow can be found by iterating over 0th index to check 0


// n*m numbers 


// 0 4 2 => 0 2 4
// 1 5 3 => 1 3 5



// 1 4 5 3 2...9 0

