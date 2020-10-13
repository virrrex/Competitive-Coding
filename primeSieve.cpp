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

void simpleSieve(int limit, vector<int> &prime) 
{ 
    // Create a boolean array "mark[0..n-1]" and initialize 
    // all entries of it as true. A value in mark[p] will 
    // finally be false if 'p' is Not a prime, else true. 
    bool mark[limit+1]; 
    memset(mark, true, sizeof(mark)); 
  
    for (int p=2; p*p<limit; p++) 
    { 
        // If p is not changed, then it is a prime 
        if (mark[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<limit; i+=p) 
                mark[i] = false; 
        } 
    } 
  
    // Print all prime numbers and store them in prime 
    for (int p=2; p<limit; p++) 
    { 
        if (mark[p] == true) 
        { 
            prime.push_back(p); 
            cout << p << " "; 
        } 
    } 
} 
  
// Prints all prime numbers smaller than 'n' 
void segmentedSieve(int n) 
{ 
    // Compute all primes smaller than or equal 
    // to square root of n using simple sieve 
    int limit = floor(sqrt(n))+1; 
    vector<int> prime;  
    simpleSieve(limit, prime);  
  
    // Divide the range [0..n-1] in different segments 
    // We have chosen segment size as sqrt(n). 
    int low = limit; 
    int high = 2*limit; 
  
    // While all segments of range [0..n-1] are not processed, 
    // process one segment at a time 
    while (low < n) 
    { 
        if (high >= n)  
           high = n; 
          
        // To mark primes in current range. A value in mark[i] 
        // will finally be false if 'i-low' is Not a prime, 
        // else true. 
        bool mark[limit+1]; 
        memset(mark, true, sizeof(mark)); 
  
        // Use the found primes by simpleSieve() to find 
        // primes in current range 
        for (int i = 0; i < prime.size(); i++) 
        { 
            // Find the minimum number in [low..high] that is 
            // a multiple of prime[i] (divisible by prime[i]) 
            // For example, if low is 31 and prime[i] is 3, 
            // we start with 33. 
            int loLim = floor(low/prime[i]) * prime[i]; 
            if (loLim < low) 
                loLim += prime[i]; 
  
            /* Mark multiples of prime[i] in [low..high]: 
                We are marking j - low for j, i.e. each number 
                in range [low, high] is mapped to [0, high-low] 
                so if range is [50, 100] marking 50 corresponds 
                to marking 0, marking 51 corresponds to 1 and 
                so on. In this way we need to allocate space only 
                for range */
            for (int j=loLim; j<high; j+=prime[i]) 
                mark[j-low] = false; 
        } 
  
        // Numbers which are not marked as false are prime 
        for (int i = low; i<high; i++) 
            if (mark[i - low] == true) 
                cout << i << " "; 
  
        // Update low and high for next segment 
        low = low + limit; 
        high = high + limit; 
    } 
}

int main()
{
    ll kMaxValue = 10000;
    vll primes;
    primes.pb(2);


    //optimized prime sieve
    for(ll i = 3; i < kMaxValue; i += 2)
    {
        bool isPrime = true;
        for(auto p : primes)
        {
            if(p*p > i)
                break;
            if(i % p == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            primes.pb(i);
    }


    // for(auto i : primes)
    //     cout<<i<<" ";   
    cout<<primes.size(); 
    return 0;
}
/*// C++ program to generate all prime numbers 
// less than N in O(N) 
#include<bits/stdc++.h> 
using namespace std; 
const long long MAX_SIZE = 1000001; 

// isPrime[] : isPrime[i] is true if number is prime 
// prime[] : stores all prime number less than N 
// SPF[] that store smallest prime factor of number 
// [for Exp : smallest prime factor of '8' and '16' 
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ] 
vector<long long >isprime(MAX_SIZE , true); 
vector<long long >prime; 
vector<long long >SPF(MAX_SIZE); 

// function generate all prime number less then N in O(n) 
void manipulated_seive(int N) 
{ 
	// 0 and 1 are not prime 
	isprime[0] = isprime[1] = false ; 

	// Fill rest of the entries 
	for (long long int i=2; i<N ; i++) 
	{ 
		// If isPrime[i] == True then i is 
		// prime number 
		if (isprime[i]) 
		{ 
			// put i into prime[] vector 
			prime.push_back(i); 

			// A prime number is its own smallest 
			// prime factor 
			SPF[i] = i; 
		} 

		// Remove all multiples of i*prime[j] which are 
		// not prime by making isPrime[i*prime[j]] = false 
		// and put smallest prime factor of i*Prime[j] as prime[j] 
		// [ for exp :let i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ] 
		// so smallest prime factor of '10' is '2' that is prime[j] ] 
		// this loop run only one time for number which are not prime 
		for (long long int j=0; 
			j < (int)prime.size() && 
			i*prime[j] < N && prime[j] <= SPF[i]; 
			j++) 
		{ 
			isprime[i*prime[j]]=false; 

			// put smallest prime factor of i*prime[j] 
			SPF[i*prime[j]] = prime[j] ; 
		} 
	} 
} 

// driver program to test above function 
int main() 
{ 
	int N = 13 ; // Must be less than MAX_SIZE 

	manipulated_seive(N); 

	// pint all prime number less then N 
	for (int i=0; i<prime.size() && prime[i] <= N ; i++) 
		cout << prime[i] << " "; 

	return 0; 
} 
*/