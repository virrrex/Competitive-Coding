#include <bits/stdc++.h>
using namespace std;
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        int n, s; cin>>n>>s;
        cout<<s/((n+1) - (n+1)/2)<<"\n";
    }

    return 0;
}