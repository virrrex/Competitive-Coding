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
#define int ll

int32_t main()
{
    rex;

    int n; cin>>n;
    vi arr(n);
    int sum = 0; f(i,n) cin>>arr[i], sum += arr[i];
    int ans = 0;
    if(sum%3 == 0){
        int num1 = sum/3;
        int num2 = 2*num1;
        sum = 0;
        int c1 = 0;
        f(i,n-1){
            sum += arr[i];
            if(sum == num2)
                ans += c1;
            if(sum == num1)
                c1++;
        }
    }
    cout<<ans<<endl;

    return 0;
}