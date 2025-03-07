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

bool isSquare(ll n){
    ll root = sqrt(n);
    return (root*root == n);
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n; 
        vll ans; 
        ll sum = 0;

        Fx(i,1,n+1){
            sum += i;

            if(n == 1) break;

            ans.pb(i);
            if(i>1 && isSquare(sum) && i==n){
                n = 1;
                break;
            }

            if(i>1 && isSquare(sum-i))
                swap(ans[i-1], ans[i-2]);

        }

        if(n == 1) cout<<-1<<nl;
        else {
            F(i,n) cout<<ans[i]<<" ";
            cout<<nl;
        }

    }
    return 0;
}

//
// 1 no
// 2: 2 1; yes 
// 3: 2 1 3: yes
// 4: 2 1 3 4: yes
// 5: 2 1 3 4 5 (sum=15)
// 6: 2 1 3 4 5 6 (sum=21)
// 7: 2 1 3 4 5 6 7 (sum=28)
// 8: 2 1 3 4 5 6 7 8 (sum=36) -1
// 9: 2 1 3 4 5 6 7 9 8 (sum=45)