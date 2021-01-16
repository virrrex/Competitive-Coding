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
#define endl            '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x)          x.begin(), x.end()
#define sortall(x)      sort(all(x))
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
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
        string s1, s2; cin>>s1>>s2;
        if(s1.length() <= s2.length() && s1 != s2.substr(0, s1.length()))
            cout<<-1<<endl;
        else if(s2.length() <= s1.length() && s2 != s1.substr(0, s2.length()))
            cout<<-1<<endl;
        else {
            string ans1 = s1, ans2 = s2;
            int ct = 0;
            while(1){
                if(ans1 == ans2){
                    cout<<ans1<<endl;
                    break;
                }
                ct = (ans1.length() > ans2.length() ? ans1.length(): ans2.length());
                if(ct > 400){
                    cout<<-1<<endl;
                    break;
                }
                if(ans1.length() < ans2.length()) ans1 += s1;
                else ans2 += s2;
            }
        }
    }

    return 0;
}