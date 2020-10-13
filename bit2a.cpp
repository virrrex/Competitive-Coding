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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while (t--)
    {
        ll n, x, ct = 1, c=0; cin>>n;
        vl a, b(n);
        fin cin>>x, a.pb(x);

        for(ll i=n-2; i>=0; i--)
        {
            if(a[i] == a[i+1])
            {   
                ct++;
                b[i] = c;
            }
            else
            {
                c += ct;
                ct = 1;
                b[i] = c;
            }
            
        }
        b[n-1] = 0;
        fin cout<<b[i]<<" ";
        cout<<endl;
    }
    
    
    return 0;
}