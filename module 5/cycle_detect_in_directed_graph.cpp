#include<bits/stdc++.h>
using namespace std;
const int N = 1e+5;
bool vis[N];
bool pathvisit[N];
bool ans;
vector<int> adj[N];

void dfs(int parent)
{
    vis[parent] = true;
    pathvisit[parent] = true;
    for(int child: adj[parent])
    {
        if(pathvisit[child])
        {
            ans = true;
        }
        if(!vis[child])
        {
            dfs(child);
        }
    }
    //kaj ses
    pathvisit[parent] = false;
}
int main()
{
     int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(vis,false,sizeof(vis));
    memset(pathvisit,false,sizeof(pathvisit));
    ans = false;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    
    if(ans == true) cout << "Cycle detected" << endl;
    else cout << "Not detected" << endl;
    return 0;
}