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
        int n; cin>>n;
        string a, b; cin>>a>>b;
        int a1=0, b1=0, a0=0;
        vi ok(n,0);
        f(i,n){
            if(a[i]=='1') a1++;
            else a0++;
            if(b[i]=='1') b1++;
            if(a1==a0) ok[i]=1;
        }
        if(a1!=b1){
            cout<<"NO\n";
            continue;
        }
        bool swap = false;
        bool yes = true;
        for(int i=n-1; i>=0; i--){
            char bi = (swap? (b[i]=='0'? '1': '0'): b[i]);
            if(a[i] != bi && ok[i])
                swap = !swap;
            else if(a[i] != bi && ok[i]==0){
                yes = false;
                break;
            }
        }
        cout<<(yes?"YES":"NO");
        cout<<nl;
    }

    return 0;
}