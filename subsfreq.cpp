#include <bits/stdc++.h>
using namespace std;

#define pb              push_back
#define ff              first
#define ss              second
#define ll              long long
#define f(i,n)          for(int i = 0; i < n; i++)
#define F(i,n)          for(ll i = 0; i < n; i++)
#define fx(i,x,n)       for(int i = x; i < n; i++)
#define endl            '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

/*Chef has a sequence of integers A1,A2,…,AN. He takes a sheet of paper and for each non-empty
subsequence B of this sequence, he does the following:

-For each integer which appears in B, count its number of occurrences in the sequence B.
-Choose the integer with the largest number of occurrences. If there are several options, choose
the smallest one.
-Finally, write down the chosen integer (an element of B) on the sheet of paper.
For each integer between 1 and N inclusive, find out how many times it appears on Chef's sheet
of paper. Since these numbers may be very large, compute them modulo 1,000,000,007 (109+7).
*/

ll pproduct[500005];

ll powerr(ll n,ll p ,ll m=mod)
{
    ll ans=1;
    while(p)
    {
        if(p&1)
            ans=(ans*n)%m;
        n=(n*n)%m;
        p>>=1;
    }
    
    return ans%m;

}

ll subSequences(ll n, ll r, ll m=mod) 
{ 
    if(r==0)
        return 1;
    return (((pproduct[n]*powerr(pproduct[n-r],mod-2,mod))%m)*powerr(pproduct[r],mod-2,mod))%m;
    
} 

int main()
{
    rex;
    
    int t; cin>>t;
    pproduct[0] = 1;
    pproduct[1] = 1;
    fx(i,2,500005)
        pproduct[i]=(1ll*pproduct[i-1]*i)%mod;
    while(t--)
    {
        int n; cin>>n;
        int a[n+1];
        ll ps[n+3], diff[n+1];
        ll prod = 1;
        map<int, int> ct;
        f(i,n)
        {
            cin>>a[i];
            ct[a[i]]++;
        }
        f(i,n+2){
            ps[i] = 1;
            diff[i] = ps[i];
        }
        for(auto c: ct)
        {
            ll tot = 1;
            for(int j=1; j<=c.ss; j++)
            {
                tot += subSequences(c.ss, j);
                tot %= mod;
                ps[j] *= tot;
                ps[j] %= mod;
            }
            diff[c.ss+1] *= tot;
            diff[c.ss+1] %= mod;
        }
        fx(i,1,n+1)
        {
            prod *= diff[i];
            prod %= mod;
            ps[i] *= prod;
            ps[i] %= mod;
        }

        fx(i,1,n+1)
        {
            ll sum=0, ans, tot=1;
            for(int j=1; j<=ct[i];j++)
            {
                ll temp;
                ans = subSequences(ct[i], j);
                temp = ans;
                tot += ans;
                tot %= mod;
                ps[j] = (ps[j]*powerr(tot,mod-2,mod))%mod;
                ans *= ps[j];
                ans %= mod;
                ps[j] = (ps[j]*(tot-temp+mod)%mod)%mod;
                sum += ans;
                sum %= mod;
            }
            cout<<sum%mod<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}