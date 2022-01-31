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
        // if rc <= rm, c wins;     
        // rc=3, rm=2, rqh=(rc-1)*dm+1, rqd=hm/rm + 1(if hm%rm !=0)
        ll hc, dc, hm, dm; cin>>hc>>dc>>hm>>dm;
        ll rc = hm/dc + (hm%dc == 0 ? 0 : 1);
        ll rm = hc/dm + (hc%dm == 0 ? 0 : 1);
        ll coins, wdefence, ahealth; cin>>coins>>wdefence>>ahealth;
        if(rc <= rm){
            cout<<"YES\n";
            continue;
        }
        ll rqh = (rc-1)*dm + 1;
        ll rqd = hm/rm + (hm%rm == 0 ? 0 : 1);
        // case1: increase defence only
        ll coin1 = (wdefence ? ((rqd-dc) / wdefence + ((rqd-dc)%wdefence != 0)) : LLONG_MAX);

        // case2: increase health only
        ll coin2 = (ahealth ? ((rqh-hc) / ahealth + ((rqh-hc)%ahealth != 0)) : LLONG_MAX);
        
        ll ans = min(coin1, coin2);
        if(ans <= coins){
            cout<<"YES\n";
            continue;
        }

        // case3: increase both optimally
        bool flag = false;
        ll k = coins;
        for(ll i=1; i<(k/2 + 1); i++){
            // i defence+, k-i health+
            ll nd = i*wdefence + dc;
            ll nh = (k-i)*ahealth + hc;
            ll nrc = hm/nd + (hm%nd != 0);
            ll nrm = nh/dm + (nh%dm != 0);
            if(nrc <= nrm) {flag = true; break;}

            ll nnd = (k-i)*wdefence + dc;
            ll nnh = i*ahealth + hc;
            ll nnrc = hm/nnd + (hm%nnd != 0);
            ll nnrm = nnh/dm + (nnh%dm != 0);
            if(nnrc <= nnrm) {flag = true; break;}
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}