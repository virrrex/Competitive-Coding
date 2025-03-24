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


string trim(string s, string t)
{
    string trim = "";
    map<char,int> tmap;
    for(char c: t)
        tmap[c]++;
    f(i,s.length()){
        if(tmap[s[i]]>0){
            trim += s[i];
        }
    } 
    return trim;
}

pair<string, string> removeCommonFromEnd(string s, string t){
    int i = s.length()-1, j = t.length()-1;
    while(i>=0 && j>=0 && s[i] == t[j]){
        i--; j--;
    }
    return {s.substr(0,i+1), t.substr(0,j+1)};
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        string s, t; cin>>s>>t;
        string ans = "YES";
        while(true){
            if(s.length() < t.length()){
                ans = "NO";
                break;
            }
            // deb2(s,t);
            s = trim(s,t);
            // cout<<"TRIMMED value: "; deb(s);
            if(s == t){
                ans = "YES";
                break;
            }
            pair<string, string> st = removeCommonFromEnd(s,t);
            string preRemove = s;
            s = st.ff;
            t = st.ss;
            // cout<<"REMOVED COMMON value: "; deb(s); deb(t);

            if(s == t){
                ans = "YES";
                break;
            }
            
            // when t becomes empty, break
            if(t.length() == 0){
                ans = "YES";
                break;
            }

            if(s == preRemove){
                ans = "NO"; 
                break;
            }
        }

        cout<<ans<<nl;
    }

    return 0;
}

// DETERMINED TRME => trim, ETERME => removeCommon, ETE T => trim, T

// DETERMINED TRME
// eterme
// etermeeterm -> no

// DETERMINED TERM
// eterme -> terme -> trme

// PSEUDOPSEUDOHYPOPARATHYROIDISM PEPA
// PEPEPPAA / PEPA => PEPEPPA PEP -> TRIM= PEPEPP / PEP => PEPEP PE
// -> TRIM = PEPEP PE (last char not matching, break) => ans no

// DEINSTITUTIONALIZATION DONATION
// DIN TITTI ONAI ATION 
// DIN TITTI ONAI / DON -> trim(DNON) -> DN / D -> D ->yes


// PEPEP P (when t becomes empty, break) => ans yes
// if (s size < t size) break, ans no

// CONTEST CODE
// COE
// CO COD

//  DINTITTIONAIATION DONATION

