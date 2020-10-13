#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
int maxProduct(int n, int m) {
    int max=0;
    max = std::max(n,m);        //can find max among two elements
    return max;
}

int isPrimeFact(long long n)
{
    set <long> prime;
    while(n%2 == 0)
    {    
        prime.insert(2);
        n /= 2;
    }
    for(long i=3; i<sqrt(n); i+=2)
    {
        while(n%i == 0)
        {
            prime.insert(i);
            n /= i;
        }
    }
    if(n>2)
        prime.insert(n);
    auto it = prime.begin();
    for(; it!=prime.end(); it++);
    it--;
    return *it;
}

int main() {
    int res=0;
    res = maxProduct(10,35);
    cout<<"Max number is: "<<res<<endl;
    long long max = isPrimeFact(600851475143);
    cout<<max;
    return 0;
}