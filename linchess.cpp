#include <bits/stdc++.h>
using namespace std;

#define pb              push_back
#define ff              first
#define ss              second
#define ll              long long
#define f(i,n)          for(int i = 0; i < n; i++)
#define F(i,n)          for(ll i = 0; i < n; i++)
#define fx(i,x,n)       for(int i = x; i < n; i++)
#define endl            '\n'
#define mod             1000000007
#define rex             ios_base::sync_with_stdio(0);cin.tie(0)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<string>  vs;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
const double PI = 3.141592653589793238460;

/*Chef wants to play a game of linear chess on a one-dimensional board ― an infinite row of squares
numbered by positive integers. In this game, he has a pawn, which is initially at a square K. There
are also N other people (numbered 1 through N); Chef can choose one of them to play against. For
each valid i, the i-th player would play in the following way:

* Take a pawn and place it on a square Pi.
* Repeat the following move any number of times: move the pawn from its current square Pi squares
  forward, i.e. from a square s, this player's pawn is moved to the square s+Pi.
* If this player moves their pawn to the square with Chef's pawn, then Chef's pawn is captured and
  he loses the game.
Unfortunately, Chef cannot move his pawn during the game, making him an easy target for other
players. Given the starting positions of all N+1 players, find a player who can capture Chef's
pawn in the smallest number of moves or determine that no player can capture his pawn.
*/

int main()
{
    rex;
    
    int t; cin>>t;
    while(t--)
    {
        int n,k,p, min = -1;
        cin>>n>>k;
        f(i,n)
        {
            cin>>p;
            if(k/p != 0 && k%p == 0)
                min = p < min ? min : p;
        }
        cout<<min<<endl;
    }
    
    return 0;
}