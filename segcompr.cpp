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

const int M = 998244353;

void add(int &a, int b)
{
    a += b;
    if (a >= M) a -= M;
}

int fun(int x)
{
    for (int i = 29; i >= 0; i--)
        if ((x >> i) & 1)
            return (1 << i);
    return 0;
}

int cost(vi a)
{
    if (a.size() == 1) return a[0];
    else {
        int ans = (1 << 30);
        f(i, a.size()){
            fx(j, i+1, a.size()){
                auto b = a;
                b[i] = fun(a[i] ^ a[j]);
                b.erase(b.begin() + j);
                ans = min(ans, cost(b));
            }
        }
        return ans;
    }
}

int ret(vi ok, int x) {
    vi ret(2);
    int pref = 0;
    ret[0]++;
    int s = 0;
    for(int &y : ok){
        if ((y >> x) & 1)
            pref ^= 1;
        add(s, ret[pref ^ 1]);
        ret[pref]++;
    }
    f(i, ok.size()){
        int cur = 0;
        for (int j=i; j<i+4 && j<ok.size(); j++) {
            cur ^= ok[j];
            if((cur >> x) & 1)
                add(s, M - 1);
        }
    }
    return (s * (ll) (1 << x)) % M;
}

int main()
{
    rex;

    int n; cin >> n;
    vi a(n);
    f(i,n) cin >> a[i];
    int sum = 0;
    f(i,n) {
        vi b;
        for(int j=i; j<n && j<i+4; j++) {
            b.pb(a[j]);
            add(sum, cost(b));
        }
    }
    for(int x = 29; x >= 0; x--){
        vi ok;
        f(i,n){
            if (a[i] >= (1 << (x + 1))){
                add(sum, ret(ok, x));
                ok.clear();
            }
            else
                ok.pb(a[i]);
        }
        add(sum, ret(ok, x));
    }
    cout<<sum<<endl;

    return 0;
}