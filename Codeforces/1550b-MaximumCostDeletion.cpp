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
        int n, a, b; cin>>n>>a>>b;
        string s; cin>>s;
        /*
        if b <0, increase length
        if a<0 or a>0, l = 1
        2.3+1 ======== 2.1+1 )3
        if b>=0, l=1
        */
        int ans = 0;
        if(b<0){    // maximize length
            vi ar;
            int x = 1;
            fx(i,1,s.length()){
                if(s[i-1] != s[i]){
                    ar.pb(x);
                    x = 1;
                }
                else 
                    x++;
                if(i == s.length()-1)
                    ar.pb(x);
            }
            if(s.length() == 1) 
                ar.pb(1);
             // 1 5 7 8 9
              // 1 5 7 8 9 2
            vi br;
            if(ar.size() & 1){
                int l,r; l = r = ar.size()/2;
                br.pb(ar[l]); 
                l--; r++;
                while(l>=0){
                    br.pb(ar[l]+ar[r]);
                    l--; r++;
                }
            }
            else{
                int l,r; r = ar.size()/2;
                l = r-1; 
                br.pb(ar[l]);
                l--;
                while(l>=0){
                    br.pb(ar[l]+ar[r]);
                    l--; r++;
                }
                br.pb(ar.back());
            }
            f(i,br.size())
                ans += (a*br[i] + b);
        }
        else
            ans = (a+b)*(s.length());
            
        cout<<ans<<nl;
    }

    return 0;
}