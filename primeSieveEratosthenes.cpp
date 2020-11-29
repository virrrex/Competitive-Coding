#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
{
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

void primeSieve(int n)
{
    int prime[n+1] = {0};
    for(int i=2; i<=n; i++){
        if(prime[i] == 0){
            for(int j=i*i; j<=n; j+=i)
                prime[j] = 1;
        }
    }
    for(int i=2; i<=n; i++)
        if(prime[i] == 0)
            cout<<i<<" ";
}

int main()
{
    int n = 37;
    cout<<"Is "<<n<<" a Prime number? "<<(checkPrime(n)? "Yes": "No")<<endl;
    cout<<"List of prime numbers till "<<n<<" is: "; primeSieve(n);

    return 0;
}