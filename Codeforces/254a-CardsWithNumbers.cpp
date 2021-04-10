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
#define rex             ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(x)          (x).begin(), (x).end()
#define sortall(x)      sort(all(x))
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<< "=" <<x<<","<<#y<<"="<<y<<endl
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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n; cin>>n;
    vpii a;
    f(i,2*n){
        int x; cin>>x;
        a.pb({x,i+1});
    }
    bool no = false;
    sortall(a);
    for(int i=0; i<2*n; i+=2){
        if(a[i].ff != a[i+1].ff){
            no = true;
            break;
        }
    }

    if(no)
        cout<<"-1\n";
    else
        for(int i=0; i<2*n; i+=2)
            cout<<a[i].ss<<" "<<a[i+1].ss<<nl;
    
    return 0;
}