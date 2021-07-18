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

    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int l = 1, r = 1;
        int st = -1, n = s.size();
        f(i,n) if(s[i] == 'a'){ st = i; break;}
        if(st == -1){cout<<"NO\n"; continue;}
        int s2 = 1;
        while((s2+1) <= n){
            char c = 'a' + s2;
            int left = 0, right = 0;
            if((st + r) <= (n-1) )
                right = 1;
            if((st-l) >= 0)
                left = 1;
            if(right && s[st+r] == c)
                r++;
            else if(left && s[st-l] == c)
                l++;
            else 
                break;
            
            s2++;
        }
        if(s2 == n) cout<<"YES\n";
        else cout<<"NO\n";

    }

    return 0;
}