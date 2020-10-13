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

/* "aabaaa" is compressed to "a2b1a3"
   if the string created by compressing S is strictly shorter than S then return "YES" else "NO"
   "bbbbbbbbbbaa" is "b10a2"
   "c" is "c1"
    "aaaaaaaaaabcdefgh" is "a10b1c1d1e1f1g1h1" */

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        string msg; cin>>msg;
        int c=1; char tmp[3];
        vector<char> enc; enc.pb(msg[0]);
        for(int i=1; i<msg.length(); i++)
        {
            if(msg[i] == msg[i-1])
                c++;
            else
            {
                sprintf(tmp, "%d", c);
                for(int j=0; tmp[j] != '\0'; j++)
                    enc.pb(tmp[j]);
                c=1;
                enc.pb(msg[i]);
            }
        }
        sprintf(tmp, "%d", c);
        for(int j=0; tmp[j] != '\0'; j++)
                    enc.pb(tmp[j]);
        if(enc.size() < msg.length())
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
        for(auto i: enc) cout<<i; cout<<endl;
    }
    
    return 0;
}