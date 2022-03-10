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

//  SCRAMBLED STRING -  RECURSIVE

//  Given a string s1, we may represent it as a binary tree by partitioning
//  it to two non-empty substrings recursively

//  DONT MISTAKE THIS QUES AS JUMBLED STRING

bool scrambledString(string a, string b){
    if(a == b)
        return true;
    if(a.length() <= 1)
        return false;
    int n = a.length();
    bool flag = false;
    for(int i=1; i<=n-1; i++){
        string a1 = a.substr(0,i);
        string a2 = a.substr(i,n-i);
        string b1swap = b.substr(n-i,i);
        string b2swap = b.substr(0,n-i);
        string b1no = b.substr(0,i);
        string b2no = b.substr(i,n-i);
        if((scrambledString(a1, b1swap)==true && scrambledString(a2, b2swap)==true)
         || (scrambledString(a1, b1no)==true && scrambledString(a2, b2no)==true)){
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    rex;
    // string a = "torfpuw", b = "prwouft";   //non scrambled string
    // string a = "abcde", b = "caebd";   //non scrambled string
    string a = "great", b = "rgeat";
    cout<<"Is scrambled string? ";
    if(a.length() != b.length())
        cout<<"No";
    else if(a == b)
        cout<<"Yes";
    else
        cout<<(scrambledString(a, b)?"Yes":"No");

    return 0;
}