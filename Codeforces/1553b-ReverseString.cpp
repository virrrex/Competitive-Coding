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

int left(string &s, string &t, int i, int x){
    while(x < t.length() && i >= 0){
        if(t[x] == s[i]){
            x++;
            i--;
        }
        else
            break;
    }
    if(x == t.length())
        return 1;
    return 0;
}
int right(string &s, string &t, int i, int x){
    if(x == t.length())
        return 1;
    if(x+1 == t.length()){
        if(i+1 < s.length() && s[i+1] == t[x])
            return 1;
        else if(i-1 >= 0 && s[i-1] == t[x])
            return 1;
        else 
            return 0;
    }
    int r1 = 0, r2 = 0;
    if(i-1 >= 0 && s[i-1] == t[x])
        r1 = left(s,t,i-1, x);
    if(r1)
        return 1;
    if(i+1 < s.length() && s[i+1] == t[x])
        r2 = right(s,t,i+1,x+1);
    return (r1 || r2);
}

int main()
{
    rex;

    int tt; cin>>tt;
    while(tt--)
    {
        string s, t; cin>>s>>t;
        int ok = 0;
        f(i, s.length()){
            if(s[i] == t[0]){
                ok = right(s,t,i,1);
                if(ok)
                    break;
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}