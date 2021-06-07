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

bool check(string &x, string &s){
    for(int i=0; i+x.length()-1 < s.length(); i++){
        bool pos = 1;
        f(j, x.length())
            if(s[i+j] != x[j]) pos = 0;
        if(pos)
            return 1;
    }
    return 0;
}

int main()
{
    rex;

    int t; cin>>t;
    vector<string> at[4];
    for(char a='a'; a<='z'; a++){
        string s1 = string(1, a);
        at[1].pb(s1);
        for(char b='a'; b<='z'; b++){
            string s2 = s1 + b;
            at[2].pb(s2);
            for(char c='a'; c<='z'; c++){
                string s3 = s2 + c;
                at[3].pb(s3);
            }
        }
    }
    while(t--)
    {
        int n; string s; cin>>n>>s;
        fx(i,1,4){
            for(string ss: at[i]){
                if(!check(ss, s)){
                    cout<<ss<<nl;
                    goto then;
                }
            }
        }
        then:;
    }

    return 0;
}