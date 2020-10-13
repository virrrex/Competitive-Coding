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

/*You are given a binary string S with length N and an integer K, which is a divisor of N. A string
is said to be K-foldable if it can be changed to a string with length K by repeating the following
process without any collisions (defined below):

-Select the prefix of the current string S with length 2K. (Note that as long as the length of S
is greater than K, this prefix always exists.)
-For each i (1≤i≤K), check if the 2K−i+1-th character of S is equal to the i-th character of S ―
if they are not equal, there is a collision and the process is invalid.
-Erase the prefix of S with length K.

Your goal is to reorder the characters of S (possibly leaving this string unchanged) in such a
way that the resulting string S is a K-foldable string. Find a way to do that or determine that it
is impossible. If there are multiple solutions, find the lexicographically smallest rearranged
string which is K-foldable.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n, k, ct0 = 0, ct1 = 0;
        cin>>n>>k;
        string s, subs="", res;
        cin>>s;
        f(i,n){
            if(s[i] == '0')
                ct0++;
            else 
                ct1++;
        }
        if(ct0 % (n/k))
            cout<<"IMPOSSIBLE"<<endl;
        else{
            ct1 /= (n/k);
            ct0 = k-ct1;
            f(i,k)
            {
                if(ct0){
                    subs += "0";
                    ct0--;
                }
                else
                    subs += "1";
            }
            res = subs;
            f(i,(n/k -1))
            {
                reverse(subs.begin(), subs.end());
                res += subs;
            }
            cout<<res<<endl;
        }
    }
    
    return 0;
}