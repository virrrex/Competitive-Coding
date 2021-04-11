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
    vi a(n); f(i,n) cin>>a[i];
    int t2 = 0, t5 = 0;
    bool ok = true;
    f(i,n){
        if(a[i] == 25)
            t2++;
        else if(a[i] == 50){
            t5++;
            if(t2 >= 1)
                t2--;
            else{
                ok = false;
                break;
            }
        }
        else{
            if(t5 >= 1 && t2 >= 1){
                t5--; t2--;
            }
            else if(t2 >= 3)
                t2 -= 3;
            else{
                ok = false;
                break;
            }
        }
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}