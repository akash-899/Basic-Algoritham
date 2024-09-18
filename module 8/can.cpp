#include <bits/stdc++.h> 
using namespace std; 
 
bool vis[105][105]; 
int dis[105][105]; 
bool flag=false; 
vector<pair<int, int>> d = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}}; 
 
int n, m; 
 
bool valid(int i, int j) 
{ 
    return i >= 0 && i < n && j >= 0 && j < m; 
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
        int a = par.first, b = par.second; 
        q.pop(); 
 
        for (int k = 0; k < 8; k++) 
        { 
            int ci = a + d[k].first; 
            int cj = b + d[k].second; 
 
            if (valid(ci, cj) && !vis[ci][cj]) 
            { 
                q.push({ci, cj}); 
                vis[ci][cj] = true; 
                dis[ci][cj] = dis[a][b] + 1; 
                flag=true; 
            } 
        } 
    } 
} 
 
int main() 
{ 
    int t; 
    cin >> t; 
 
    while (t--) 
    { 
        cin >> n >> m; 
 
        memset(vis, false, sizeof(vis)); 
        memset(dis, -1, sizeof(dis)); 
 
        int si, sj, qi, qj; 
        cin >> si >> sj >> qi >> qj; 
 
        bfs(si, sj); 
 
        cout << dis[qi][qj] << endl; 
    } 
    if(flag==false) 
    { 
        cout<<-1; 
    } 
 
    return 0; 
}