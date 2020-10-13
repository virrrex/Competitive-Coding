#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define ll long long
#define pp pair<ll,ll>
#define vl vector<ll>
#define vpp vector<pp>
#define fin for(ll i = 0; i < n; i++)
#define endl '\n'
const double PI = 3.141592653589793238460;

using namespace std;

ll nCr(int n, int r) 
{ 
    ll p = 1, k = 1; 
  
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r;
            ll m = __gcd(p, k); 
            p /= m; 
            k /= m; 
            n--; 
            r--; 
        }
    } 
  
    else
        p = 1; 
  
    return p;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k, x, t, ans;
    cin>>t;
    while (t--) 
    {
        cin>>n>>k, ans=1;
        map<ll,ll> mp;
        fin cin>>x, mp[x]++;
        for(auto a: mp)
            if(a.ss > k)
            {
                ans = nCr(a.ss, k);
                break;
            }
            else
                k-=a.ss;
        cout<<ans<<endl;
    }
    return 0;
}