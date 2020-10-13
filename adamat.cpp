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

/*
Chef Ada has a matrix with N rows (numbered 1 through N from top to bottom) and N columns (numbered 1
through N from left to right) containing all integers between 1 and N2 inclusive. For each valid i and j,
let's denote the cell in the i-th row and j-th column by (i,j).

Ada wants to sort the matrix in row-major order ― for each valid i and j, she wants the cell (i,j) to
contain the value (i−1)⋅N+j.

In one operation, Ada should choose an integer L and transpose the submatrix between rows 1 and L and
columns 1 and L (inclusive). Formally, for each i and j (1≤i,j≤L), the value in the cell (i,j) after this
operation is equal to the value in (j,i) before it.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int mat[64][64];
        f(i,n)
            f(j,n)
                cin>>mat[i][j];
        int ct=0, flag=0;
        for(int i=n-1; i>=1; i--)
        {
            if(flag==0 && mat[0][i] != i+1)
            {
                ct++;
                flag = 1;
            }
            if(flag==1 && mat[i][0] != i+1)
            {
                ct++;
                flag = 0;
            }
        }
        cout<<ct<<endl;
    }
    
    return 0;
}