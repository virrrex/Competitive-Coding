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


void solve(int i,vi &v1,int size,int s,int &T)
{

    if(i==size)
    {
        if(s==0)
            T++;
        return;
    }
    solve(i+1,v1,size,s+v1[i],T);
    solve(i+1,v1,size,s,T);
}

int main()
{
    rex;

    int n; cin>>n;
    vi nums(n);
    f(i,n) cin>>nums[i];
    int m=0;

    f(i,n)
    {
        if(nums[i]>m)
        m=nums[i];
    }

    int counterr=0;
    while(m)
    {
        counterr++;
        m=m>>1;
    }

    vi v1(n,0);
    for(int i=0;i<n;i++)
    {
        while(nums[i])
        {
            if(nums[i]&1)
                v1[i]++;
            nums[i]=nums[i]>>1;
        }
    }

    int j=0;
    f(i,n)
    {
        v1[j]=counterr-2*v1[i];

        if(v1[j] != 0)
            j++;
    }
    int T=0;
    solve(0,v1,j,0,T);
    T-=1;
    T=T*(1+n-j)+(1<<(n-j))-1;
    vi bin(counterr,0); 
    int i=0;
    while (T > 0) { 
        bin[i] = T &1; 
        T = T>>1; 
        i++;
    } 
    for (int j=counterr - 1; j >= 0; j--) 
        cout<<bin[j]; 
    return 0;
}