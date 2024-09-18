#include<bits/stdc++.h>
using namespace std;
const int N=1005;

int n, m;
int maze[N][N];
bool vis[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x,int y)
{
    return !vis[x][y] && maze[x][y] != -1 && x>=0 && x<n && y>=0 && y<m;
}
void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    vis[src.first][src.second] = true;
    while(!q.empty())
    {
        auto parent = q.front();
        q.pop();
        int x = parent.first;
        int y = parent.second;

        for(int i = 0; i < 4; i++)
        {
            int new_X = x + dx[i];
            int new_Y = y + dy[i];
            if(valid(new_X,new_Y))
            {
                q.push({new_X,new_Y});
                vis[new_X][new_Y] = true;
            }
        }
    }
}
int main()
{
    pair<int, int> src,des;
    cin >> n >> m;
    for( int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            if(s[j] =='#')
            {
                maze[i][j] = -1;
            }
            if(s[j] == 'A')
            {
                src = {i, j};
            }
            if(s[j] == 'B')
            {
                des = {i, j};
            }
        }
    }

    bfs(src);

        if(vis[des.first][des.second])
        {
            cout << "YES" <<endl;
        }
        else
        {
            cout << "NO" <<endl;
        }
    return 0;
}