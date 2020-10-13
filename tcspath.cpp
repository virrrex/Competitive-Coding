#include <bits/stdc++.h>
using namespace std;

#define pb              push_back
#define ff              first
#define ss              second
#define ll              long long
#define f(i,n)          for(int i = 0; i < n; i++)
#define F(i,n)          for(ll i = 0; i < n; i++)
#define fn1(i,n1,n)       for(int i = n1; i < n; i++)
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

int findit(int n1)
{
     for(int i=2;i*i<=n1;i++)
     {
         if(n1%i==0)return n1/i;
     }
     return 1;
}

void justdoit()
{
     int n1,n2;
     cin>>n1>>n2;
     if(n1<n2)
        swap(n1,n2);
     if(n1==n2)
        {
            cout<<0;
            return;
        }
     map<int,int> m;

     int ct=0;
     while(n1!=1)
     {
         ct++;
         n1=findit(n1);
         m[n1]=ct;
     }

     ct=0;
     while(m.count(n2) == 0)
     {
         ct++;
         n2=findit(n2);
     }
     cout<<ct+m[n2];
}

int main()
{
    rex;
    
    justdoit();
    
    return 0;
}
