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

void solmap(vi arr, int n){
    vi mp(n+1,0);
    f(i,n)
        mp[arr[i]]++;
    fx(i,1,n+1){
        if(mp[i] == 0)
            cout<<"Missing no.: "<<i<<nl;
        if(mp[i] == 2)
            cout<<"Repeating no.:"<<i<<nl;
    }
}

void solxor(vi arr, int n){
    int xor1 = 0;
    f(i,n) xor1 ^= arr[i];
    fx(i,1,n+1) xor1 ^= i;
    // now xor1 has value = (missing ^ repeat)

    // get right-most set bit
    int set_bit = xor1 & ~(xor1 - 1);
    int x = 0, y = 0;

    f(i,n){
        if(set_bit & arr[i])
            x ^= arr[i];
        else 
            y ^= arr[i];
    }
    fx(i,1,n+1){
        if(set_bit & i)
            x ^= i;
        else 
            y ^= i;
    }
    cout<<"[XOR] Missing no.: "<<x<<nl<<"Repeating no.:"<<y<<nl;
}

int main()
{
    rex;

    vi arr = {4,3,6,2,1,1};
    int n = 6;
    solmap(arr, n);
    solxor(arr, n);

    return 0;
}