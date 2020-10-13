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

/*Chef has a string S. He also has another string P, called pattern. He wants to find the pattern
in S, but that might be impossible. Therefore, he is willing to reorder the characters of S in such
a way that P occurs in the resulting string (an anagram of S) as a substring.

Since this problem was too hard for Chef, he decided to ask you, his genius friend, for help.
Can you find the lexicographically smallest anagram of S that contains P as substring?
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        string s,p;
        cin>>s>>p;
        map<char,int> scnt;
        vector<char> op;
        for (char c: s)
            scnt[c]++;
        for (char c: p)
            scnt[c]--;
        for(auto itr: scnt)
        {
            if(itr.ff == p[0])
            {
                int flag = 0;
                for(int k=0; k<p.length(); k++)
                {
                    if(p[0] != p[k])
                    {
                        if(p[0] > p[k])
                            flag = 1;
                        break;
                    }
                }
                
                if(flag)
                {
                    for(int j=0; j<p.length(); j++)
                        op.pb(p[j]);
                    for(int j=0; j<itr.ss; j++)
                        op.pb(itr.ff);
                }
                else 
                {
                    for(int j=0; j<itr.ss; j++)
                        op.pb(itr.ff);
                    for(int j=0; j<p.length(); j++)
                        op.pb(p[j]);
                }
            }
            else 
                for(int j=0; j<itr.ss; j++)
                    op.pb(itr.ff);
               
        }
        for(char c: op)
            cout<<c;
        cout<<endl;
    }
    
    return 0;
}