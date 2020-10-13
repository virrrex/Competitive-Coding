#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    long long m,n;
    cin>>m>>n;
    vector <long long> prime;
    for(int i=m; i<=n; i++)
    {
        int flag=0;
        if(i==1)
            continue;
            if(i==2)
            {
                prime.push_back(i);
                continue;
            }
        for(int j=2; j<=sqrt(i); j++)
        {
            if(i%j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
            prime.push_back(i);
    }

    long long count = 0;
    for(int x=0; x<prime.size(); x++)
    {
        for(int y=x+1; y<prime.size(); y++)
        {
            if(prime[y] - prime[x] == 6)
            {
                count++;
                cout<<"{"<<prime[x]<<", "<<prime[y]<<"}"<<endl;
                break;
            }
        }
    }

    cout<<count<<endl;
    return 0;
}