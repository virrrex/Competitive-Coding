#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int i, j, n, k, m = INT_MIN, sum = 0, ksum = 0;
    cin>>n>>k;
    int ar[n];
    for(i=0; i<n; i++)
    {
        cin>>ar[i];
        sum += ar[i];
    }

    for(i=0; i<k; i++)
    {
        ksum += ar[i];
    }

    for(j = 0; i<n; i++, j++)
    {
        m = max(m, (sum - ksum));
        ksum -= ar[j];
        ksum += ar[i];
    }
    m = max(m, (sum - ksum));
    cout<<m;
    return 0;
}