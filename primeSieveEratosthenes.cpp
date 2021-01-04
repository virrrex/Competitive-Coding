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

#define MAXN 1000001 
long long sieve[MAXN]; 
void makesieve()
{
    sieve[1] = 0; 
    for (int i = 2; i < MAXN; i++) 
        sieve[i] = i; 
    for (int i = 4; i < MAXN; i += 2) 
        sieve[i] = 2; 
    for (int i = 3; i * i < MAXN; i++) { 
        if (sieve[i] == i) { 
            for (int j = i * i; j < MAXN; j += i) 
                if (sieve[j] == j) 
                    sieve[j] = i; 
        } 
    } 
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
    makesieve();
    cout<<"\nMake sieve:\n"; for(int i=0; i<n; i++) cout<<sieve[i]<<" ";

    return 0;
}