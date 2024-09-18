#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
pair<int,int> parent[N][N];
int n, m;
char a[N][N];
bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m  && a[ci][cj] != '#') return true;
    else return false;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first;
        int b = par.second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] )
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                parent[ci][cj] = {a,b};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si,sj;
    int di,dj;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {    parent[i][j] = {-1,-1};
            cin >> a[i][j];
            if(a[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if(a[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis,false,sizeof(vis));
    
    bfs(si,sj);
    int ci = di;
    int cj = dj;
    if(vis[di][dj])
    {
        while(ci != si || cj != sj)
        {
            a[ci][cj] = 'X';
            pair<int,int> par = parent[ci][cj];
            ci = par.first;
            cj = par.second;
            
        }
        a[si][sj] = 'R';
        a[di][dj] = 'D';
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}