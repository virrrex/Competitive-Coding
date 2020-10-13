#include <iostream>
using namespace std;
int main()
{
    long long n;
    int g, t, i, q;
    cin>>t;
    while(t--)
    {
        cin>>g;
        while(g--)
        {
            cin>>i>>n>>q;
            if(n%2 == 0)
            {
                cout<<n/2<<endl;
            }
            else
            {
                if(i==q)
                    cout<<n/2<<endl;
                else
                    cout<<n/2+1<<endl;
            }
            
        }
    }
    return 0;
}