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
#define all(x)          x.begin(), x.end()
#define sortall(x)      sort(all(x))
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

bool isPrime(int n)
{
    if (n == 1)
        return false;

    int d = 2;
    while (d * d <= n){
        if (n % d == 0)
            return false;
        d++;
    }
    return true;
}

int main()
{
    rex;

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
         103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
         211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
         307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
         401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
         503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
         601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
         701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
         809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
         907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
        auto it = lower_bound(all(primes), n);
        int x = *it; 
        auto fi = find(all(primes), x);
        int index = distance(primes.begin(), fi);
        bool isP = binary_search(all(primes), n);
        if(isP){
            f(i,n){
                f(j,n)
                    cout<<1<<" ";
                cout<<endl;
            }
            continue;
        }
        int pp = 0;
        for(int i=index; i<primes.size(); i++){
            if(!isPrime(primes[i] - n + 1)){
                pp = primes[i];
                break;
            }
        }
        pp = pp - n + 1;
        int c = 0;
        f(i,n){
            f(j,n){
                if(j == c)
                    cout<<pp<<" ";
                else 
                    cout<<"1 ";
            }
            cout<<endl;
            c++;
        }
    }

    return 0;
}