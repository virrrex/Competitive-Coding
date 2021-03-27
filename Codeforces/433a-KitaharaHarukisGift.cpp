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
#define all(x)          (x).begin(), (x).end()
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

    int n; cin>>n;
    vi a(n); int ct2=0;
    f(i,n){
        cin>>a[i];
        if(a[i]==200)
            ct2++;
    }
    int sum = accumulate(all(a), 0);
    int ct1 = n-ct2;
    sum /= 2;
    if(sum % 100 != 0)
        cout<<"NO\n";
    else if(sum == 200*ct2)
        cout<<"YES\n";
    else if(sum < 200*ct2){
        if(sum%200 == 0)
            cout<<"YES\n";
        else if(ct1>=1)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    else{
        sum -= 200*ct2;
        sum /= 100;
        if(ct1 >= sum)
            cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}