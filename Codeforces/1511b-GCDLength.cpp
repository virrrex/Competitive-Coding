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

int power(int x, unsigned int y)
{
    int res = 1; 
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1; 
        x = x * x; 
    }
    return res;
}

int getDigits(int &x)  
{  
    x = abs(x);  
    return (x < 10 ? 1 :   
        (x < 100 ? 2 :   
        (x < 1000 ? 3 :   
        (x < 10000 ? 4 :   
        (x < 100000 ? 5 :   
        (x < 1000000 ? 6 :   
        (x < 10000000 ? 7 :  
        (x < 100000000 ? 8 :  
        (x < 1000000000 ? 9 :  
        10)))))))));  
} 
void solve1(){
    int a,b,c; cin>>a>>b>>c;
    int x = power(10,a-1);
    int xmx = power(10,a) - 1;
    int y = power(10,b-1);
    int ymx = power(10, b) - 1;
    bool xd = false;
    fx(i,x,xmx+1){
        fx(j,y,ymx+1){
            int gg = __gcd(i,j);
            if(getDigits(gg) == c){
                cout<<i<<" "<<j<<nl;
                xd = true;
                break;
            }
        }
        if(xd) break;
    }
}

ll pows[11];
void solve2(){
    ll a,b,c; cin>>a>>b>>c;
    ll x = pows[c-1], y = pows[c-1];
    while(x < pows[a-1]) x *= 2;
    while(y < pows[b-1]) y *= 3;
    cout<<x<<" "<<y<<nl;
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        // solve1();
        pows[0] = 1;
        f(i,10) pows[i+1] = 10*pows[i];
        solve2();
    }

    return 0;
}