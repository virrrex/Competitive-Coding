#include <bits/stdc++.h>
using namespace std;
#define MAX 500
int multiply(int,int[],int);
int main()
{
    int t,n,res_size;
    int res[MAX];
    cin>>t;
    while(t--)
    {
        res[0]=1;
        res_size=1;
        cin>>n;
        for(int i=2; i<=n; i++)
            res_size = multiply(i,res,res_size);

        for(int i=res_size-1;i>=0;i--)
            cout<<res[i];
        cout<<endl;
    }
    return 0;
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod%10;
        carry = prod/10;
    }
    while(carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}
