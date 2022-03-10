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

//  PALINDROME PARTITIONING - RECURSIVE

bool isPalindrome(string s, int a, int b){
    for(int i=a, j=b; i<j; i++, j--){
        if(s[i] != s[j])
            return false;
    }
    return true;
}

int PP(string s, int i, int j){
    if(i >= j)
        return 0;
    if(isPalindrome(s,i,j))
        return 0;
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int tmp = 1 + PP(s,i,k) + PP(s,k+1,j);
        mn = min(mn, tmp);
    }
    return mn;
}

int main()
{
    rex;

    string s = "nitinxyxt";
    int i=0, j=s.length()-1;
    cout<<"Minimum partitions to be made in string to make all partitions a palindrome is: "<<PP(s, i, j);

    return 0;
}