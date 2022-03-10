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
#define nl              '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x)          (x).begin(), (x).end()
#define sortall(x)      sort(all(x))
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define deb(x)          cout<<#x<<"="<<x<<endl
#define deb2(x, y)      cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define mem1(a)         memset(a,-1,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

/*
                CATALAN NUMBERS
    Can solve these problems:
    1. Find no. of BSTs formed with given n nodes.
    2. Find no. of unlabelled trees with given n nodes.
    3. Find no. of ways to put paranthesis (with or without letters)
        with given n pairs of paranthesis.
    4. Dyck words, given set of two letters, find no. of ways of
        arrangement so that at any place 1st letter count is greater
        or equal to 2nd one.
    5. Mountain Ranges, given n upstokes and downstokes, find no. of 
        different mountain valley sets u can form without going below
        sea level.
    6. 
*/

// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n, unsigned int k){
    unsigned long int res = 1;
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
    // Calculate value of [n*(n-1)*---*(n-k+1)] /
    // [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
 
// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long int catalan(unsigned int n){
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2 * n, n);
    // return 2nCn/(n+1)
    return c / (n + 1);
}

int main()
{
    rex;

    f(i,10)
        cout<<catalan(i)<<" ";

    return 0;
}