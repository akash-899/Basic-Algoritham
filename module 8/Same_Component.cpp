#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char a[N][N];
bool vis[N][N];
vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
 int si,sj;
int di,dj;

bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m) return false;
    else return true;
}
void dfs(int si, int sj)
{
    vis[si][sj]=true;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(valid(ci,cj)==true && vis[ci][cj]==false && a[ci][cj] == '.')
        {
            dfs(ci,cj);
        }
    }
}
int main()
{
    
    cin>>n>>m;
    for(int i=0; i<n; i++) // O(V)/ O(N*M)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    
    cin>> si>>sj;

    cin>>di>>dj;
    
    memset(vis,false,sizeof(vis));
    
    dfs(si,sj);
    
    if(vis[di][dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" <<endl;
    }
    return 0;
}