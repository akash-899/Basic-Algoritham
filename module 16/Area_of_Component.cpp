#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char a[N][N];
bool vis[N][N];
int n,m;
int cnt;
vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int ci,int cj)
{
    if(ci >= 0 && ci < n && cj >= 0 && cj < m) return true;
    else return false;
}
void dfs(int si,int sj)
{ 
    
     vis[si][sj]=true;
     cnt++;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(valid(ci,cj)==true && vis[ci][cj]==false && a[ci][cj] != '-')
        {
            dfs(ci,cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int minArea = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && a[i][j] == '.')
            {
                 cnt = 0;
                dfs(i,j);
                minArea = min(minArea,cnt);
            }
        }
    }
     if (minArea == INT_MAX) 
     {
        cout << -1 << endl;
     } 
    else 
    {
        cout << minArea << endl;
    }
    
    return 0;
}