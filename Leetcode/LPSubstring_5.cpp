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

// LONGEST PALINDROMIC SUBSTRING

int expandFromMiddle(string s, int l, int r){
    while(l >=0 && r < s.length() && s[l]==s[r]){
        l--; r++;
    }
    return r-l-1;
}
int LPSubstring(string s)
{
    int start=0, end=0;
    for(int i=0; i<s.length(); i++){
        int len1 = expandFromMiddle(s,i,i);
        int len2 = expandFromMiddle(s,i,i+1);
        int len = max(len1, len2);
        if(len > end-start){
            start = i - (len-1)/2;
            end = i + len/2;
        }
    }
    cout<<s.substr(start,end-start+1)<<endl;
    return end-start+1;
}

int main()
{
    rex;

    string x="aacabdkacaa";//"babad"; 
    cout<<"Size of longest common substring is: "<<LPSubstring(x);

    return 0;
}