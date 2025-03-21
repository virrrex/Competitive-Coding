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


// // x=abbabbabbabb,          s=babba
// void checkSubstring(string x, string s)
// {
//     int i = 0, j = 0;
//     while(i < x.length() && j < s.length()){
//         deb2(i,j);
//         if(x[i] == s[j]){
//             deb2(x[i], s[j]);
//             j++;
//         }
//         else
//             j = 0;  // wrong logic: i should go back to i = i-j+1 before j=0
//         i++;
//         if(j == s.length()){
//             cout<<"Substring found\n";
//             break;
//         }
//     }
//     bool xx = (j == s.length());
//     cout<<xx;
// }

bool checkSubstring(string txt, string pat){
    int n = txt.length();
    int m = pat.length();

    // Iterate through txt
    for (int i = 0; i <= n - m; i++) {

        // Check for substring match
        int j;
        for (j = 0; j < m; j++) {

            // Mismatch found
            if (txt[i + j] != pat[j]) {
                break;
            }
        }

        // If we completed the inner loop, we found a match
        if (j == m) {

            // Return starting index
            return 1;
        }
    }
    
    // No match found
    return 0;
}

// int main(){
//     checkSubstring("abbabbabbabb", "babba");
//     return 0;
// }

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
       int n,m; cin>>n>>m;
       string x, s; cin>>x>>s;

       int operations = -1;

       f(i,6){
            // deb2(x,s);
            if(checkSubstring(x,s)){
                operations = i;
                break;
            }
            x += x;
       }

       cout<<operations<<nl;
    }

    return 0;
}







// abc
// abcabc
// abcabcabcabc
// abcabcabcabcabcabcabcabc

// cabca

// m 
// mm 
// mmmm 
// mmmmmmmm
// mmmmmmmmmmmmmmmm
// mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm