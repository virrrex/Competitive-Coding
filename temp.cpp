#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int findIndex(int a[], int n, int x, int p) {
    int min = 100000000, minp=-1;
    for(int i=0;i<n;i++)
        if(a[i] == x) {
            if(abs(p-i) < min) {
                min = abs(p-i);
                minp = i;
            }
        }
    return minp;
}
void subMain() {
    int N, X, p, k;
    cin >> N >> X >> p >> k;
    int a[N];
    for(int i=0;i<N;i++)
    cin >> a[i];
    sort(a, a+N);
    int index = findIndex(a, N, X, p);
    int count = 0;
    if(a[index] != X) {
        a[k-1] = X;
        sort(a, a+N);
        count++;
    }
    if(a[p-1] == X) {
        cout << 0+count;
        return;
    }
    if(p < k && a[p-1] < X) {
        cout << -1;
        return;
    }
    if(p > k && a[p-1] > X) {
        cout << -1;
        return;
    }
    index = findIndex(a, N, X, p)+1;
    cout << abs(p-index)+count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        subMain();
        cout << "\n";
    }
    return 0;
}
// int main()
// {
//     ios::sync_with_stdio(0);cin.tie(0);
//     #ifndef ONLINE_JUDGE
//         clock_t tStart = clock();
//         freopen("input.txt","r",stdin);
//         freopen("output.txt","w",stdout);
//     #endif
//     solution();
//     #ifndef ONLINE_JUDGE
//         fprintf(stderr, "Runtime: %.10fs\n",(double)(clock()- tStart)/CLOCKS_PER_SEC);
//     #endif
//     return 0;
// }

