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

long long multiplyNumbers(int n) {
    if (n>=1)
        return (n*multiplyNumbers(n-1)) % mod;
    else
        return 1;
}

int main()
{
    rex;

    int n, x, pos;
    cin>>n>>x>>pos;
    int greater = n-x, smaller = x-1, left = 0, right = n, ans = 1;
    while (left<right)
    {
        int mid = (left + right) / 2;
        if(mid < pos){
            ans = 1LL * ans * smaller % mod;
            smaller--;
            left = mid+1;
        }
        else if(mid == pos)
            left = mid + 1;
        else {
            ans = 1LL * ans * greater % mod;
            greater--;
            right = mid;
        }
    }
    smaller += greater;
    while (smaller)
    {
        ans = 1LL * ans * smaller % mod;
        smaller--;
    }
    cout<<ans<<endl;

    return 0;
}