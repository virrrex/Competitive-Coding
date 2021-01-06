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

int divs(int x)
{
    int t=0; 
    while(x%2==0){
        x/=2;
        t++;
    }
    return t;
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        ll w, h, n; cin>>w>>h>>n;
        if(w%2!=0 && h%2!=0){
            if(n==1)
                cout<<"YES\n";
            else cout<<"NO\n";
        }
        else if(w%2==0 && h%2==0){
            w = divs(w); h = divs(h);
            w = 1<<w; h = 1<<h;
            ll x = w*h;
            if(x>=n) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else if(w%2==0){
            w = divs(w); w = 1<<w;
            if(w>=n) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else if(h%2==0){
            h = divs(h); h = 1<<h;
            if(h>=n) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

    return 0;
}