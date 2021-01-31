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

int main()
{
    rex;

    int n; cin>>n;
    vi a(9); f(i,9) cin>>a[i];
    int sz = INT_MAX, num = 9;
    for(int i=8; i>=0; i--){
        if(a[i] < sz){
            sz = a[i];
            num = i+1;
        }
    }
    int len = n/sz;
    int rem = n%sz;
    string ans = "";
    bool flag = true;
    while(flag)
    {
        flag=false;
        for(int i=8;i>=num;i--)
        {
            if(sz+rem>=a[i])
            {
                ans += to_string(i+1);
                rem -= (a[i]-sz);
                flag = true;
                len--;
                break;
            }
        }
    }
    f(i,len)
        ans += to_string(num);
    if(ans.size() == 0)
        ans += "-1";
    cout<<ans<<endl;

    return 0;
}