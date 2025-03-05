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
        ll n; string s; cin>>n>>s;
        ll ans = 0;

        ll countUnderscore = 0, countDash = 0;
        F(i, s.size()){
            if(s[i] == '_')
                countUnderscore++;
            else if(s[i] == '-')
                countDash++;
        }
        ll a = countDash/2;
        ll b = countDash - a;

        ans = a*b*countUnderscore;
        cout<<ans<<nl;

    }
    return 0;
}

//
// 9
// // --__-_---

// - _ - - _ - - _ - (3 faces: 27)

// - - - _ _ _ - - -
// a b c d e f g h i




// 4
// // _--_ 
// - _ _ - (2 subsequences to form 1 face) 

// abcd=> abc, acd

// 10
// // _-_-_-_-_-

// - - _ _ _ _ _ - - -
// a b c d e f g h i j
// ans: 30



// - - _ _ - -
// a b c d e f
// abef = - 
// cd = _

// ace, acf
// ade, adf
// bce, bcf
// bde, bdf

// - _ _ - -
// a b c d e 

// abd, abe
// acd, ace

// - - _ _ -
// a b c d e 

// ace, bde
// ade, bce


// 7
// _------

// ---_---