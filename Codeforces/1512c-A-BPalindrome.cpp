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
        int a,b; cin>>a>>b;
        string s; cin>>s;
        string s1 = s.substr(0,(a+b)/2);
        string s2 = s.substr((a+b)/2);
        bool odd = false, xd = false;
        if((a+b)%2 == 1){
            s1.pb(s[(a+b)/2]);
            odd = true;
        }
        reverse(all(s2));
        f(i,s.length()){
            if(s[i]=='0') a--; 
            else if(s[i]=='1') b--;
        }
        int n = s1.size(), q = 0;
        f(i,n){
            if(s1[i] != '?' && s2[i] == '?'){
                s2[i] = s1[i];
                s1[i]=='0'? a--: b--;
            }
            else if(s1[i] == '?' && s2[i] != '?'){
                s1[i] = s2[i];
                s2[i]=='0'? a--: b--;
            }
            else if(s1[i] != '?' && s2[i] != '?' && s[i] != s2[i])
                xd = true;
            else if(s1[i] == '?' && s2[i] == '?'){
                q += 2;
                if(i==n-1 && odd)
                    q--;
            }
        }
        if(a<0 || b<0 || (a+b) != q)
            xd = true;
        if(a&1 && b&1)
            xd = true;
        if(xd){
            cout<<"-1\n";
            continue;
        }
        if(a&1){
            if(s1[n-1] != '?')
                xd = true;
            s1[n-1] = '0';
            s2[n-1] = '0';
            a--; q--;
        }
        if(b&1){
            if(s1[n-1] != '?')
                xd = true;
            s1[n-1] = '1';
            s2[n-1] = '1';
            b--; q--;
        }
        if(xd){
            cout<<"-1\n";
            continue;
        }
        f(i,n){
            if(a == 0)
                break;
            if(s1[i] == '?'){
                s1[i] = '0';
                s2[i] = '0';
                a -= 2;
                q -= 2;
            }
        }
        if(a!=0) xd = true;
        if(xd){
            cout<<"-1\n";
            continue;
        }
        f(i,n){
            if(b == 0)
                break;
            if(s1[i] == '?'){
                s1[i] = '1';
                s2[i] = '1';
                b -= 2;
                q -= 2;
            }
        }
        if(b!=0 || q!=0) xd = true;
        if(xd){
            cout<<"-1\n";
            continue;
        }
        reverse(all(s2));
        if(odd)
            s2 = s2.substr(1);
        cout<<s1<<s2<<nl;

    }

    return 0;
}