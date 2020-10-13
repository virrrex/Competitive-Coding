#include <bits/stdc++.h>
using namespace std;

#define pb      push_back
#define ff      first
#define ss      second
#define ll      long long
#define f(i,n)  for(int i = 0; i < n; i++)
#define F(i,n)  for(ll i = 0; i < n; i++)
#define endl    '\n'
#define mod     1000000007
#define rex     ios_base::sync_with_stdio(0);cin.tie(0)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

/*There are 10 types of weapons (numbered 1 through 10). You are given N strings S1,S2,…,SN;
 During each battle, for each type j such that both contestants in this battle currently have weapons
 of type j, these weapons of both contestants are destroyed; after the battle, the winner collects
 all remaining (not destroyed) weapons of the loser.
 INPUT:                     OUTPUT:
1                           4
3
1110001101
1010101011
0000000011*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n, ct = 0; cin>>n;
        string s, res;
        f(i,n)
        {
            cin>>s;
            if(res.length() == 0)
                res = s;
            else 
                f(j,10)
                    res[j] = ((int(s[j]) - 48) ^ (int(res[j]) - 48)) + 48;
        }
        f(i,10)
            if(res[i] == '1')
                ct++;
        cout<<ct<<endl;

    }
    
    return 0;
}