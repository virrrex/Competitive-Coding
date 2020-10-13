#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int> >

void left_rotation_by_one(vvi &adjacent, int l)
{
        int n=adjacent[l].size();
        int temp = adjacent[l][0], i;
        for (i = 0; i < n - 1; i++)
        adjacent[l][i] = adjacent[l][i + 1];
        adjacent[l][i] = temp;
}

void array_left_rotation(vvi &adjacent, int no_of_rotations, int l)
{
        for (int i = 0; i < no_of_rotations; i++)
        left_rotation_by_one(adjacent, l);   
}

void right_rotation_by_one(vvi &adjacent, int l)
{
        int n=adjacent[l].size();
        int temp = adjacent[l][n - 1], i;
        for (i = n - 1; i > 0; i--)
        adjacent[l][i] = adjacent[l][i - 1];
        adjacent[l][0] = temp;
}

void array_right_rotation(vvi &adjacent, int no_of_rotations,int l)
{
    for (int i = 0; i < no_of_rotations; i++)
    right_rotation_by_one(adjacent,l);     
}

void rotation(vvi &adjacent,vector<int> l,int u,int v){
    int t=adjacent.size();
    for(int i=0;i<t;i++){
        int temp=adjacent[i].size();
        if(i%2==1)
            array_right_rotation(adjacent,l[i]%temp,i);
        
        else
            array_left_rotation(adjacent,l[i]%temp,i);
    }
    int rows = 0, cols = 0; 
    int level=0;
    int m=u,n=v;
    int a[u][v];
    memset(a,0,sizeof(a));
    while (rows < m && cols < n) 
    { 
        int j=0;
        if (rows + 1 == m || cols + 1 == n) 
            break;   
        for (int i = cols; i < n; i++) 
            a[rows][i]=adjacent[level][j++];
        
        rows++; 
        for (int i = rows; i < m; i++) 
            a[i][n-1]=adjacent[level][j++];
        
        n--; 
        if (rows < m) 
        { 
            for (int i = n-1; i >= cols; i--) 
                a[m-1][i]=adjacent[level][j++]; 
        } 
        m--; 
        if (cols < n) 
        { 
            for (int i = m-1; i >= rows; i--) 
                a[i][cols]=adjacent[level][j++];
        } 
        cols++; 
        level++;
    }
    for(int i=0;i<u;i++){
        for(int j=0;j<v;j++){
            cout<<a[i][j]<<" ";
    }
    cout<<endl;
    } 
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> adjacent;
    vvi a;
    int u=m,v=n;
    for(int i=0;i<m;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        a.push_back(temp);
        temp.clear();
    }
    vector<int> l;
    for(int i=0;i<min(m,n)/2;i++){
        int x;
        cin>>x;
        l.push_back(x);
    }
    int rows = 0, cols = 0; 
    while (rows < m && cols < n) 
    { 
        vector<int> e;
        if (rows + 1 == m || cols + 1 == n) 
            break;   
        for (int i = cols; i < n; i++) 
            e.push_back(a[rows][i]);
        
        rows++; 
        for (int i = rows; i < m; i++) 
            e.push_back(a[i][n-1]);

        n--; 
        if (rows < m) 
        { 
            for (int i = n-1; i >= cols; i--) 
                e.push_back(a[m-1][i]);
        } 
        m--; 
        if (cols < n) 
        {
            for (int i = m-1; i >= rows; i--) 
                e.push_back(a[i][cols]);
        } 
        cols++; 
        adjacent.push_back(e);
        e.clear();
    }

    rotation(adjacent,l,u,v);
 
}