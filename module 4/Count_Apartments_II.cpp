#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char a[N][N];
bool vis[N][N];
int cnt=0;
vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;

bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m || a[i][j] !='.') return false;
    else return true;
}
void dfs(int si, int sj)
{
    cnt++;
    vis[si][sj]=true;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(valid(ci,cj)==true && vis[ci][cj]==false)
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

    memset(vis,false,sizeof(vis));
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if( !vis[i][j] && a[i][j] == '.')
            {
               cnt=0;
                dfs(i,j);
                v.push_back(cnt);
                 
            }
        }
    }
     sort(v.begin(),v.end());
    if(v.empty())
    {
        cout<<"0"<<endl;
    }
    else
    {
        for(int val: v)
        {
            cout<<val<< " ";
        }
    }
    return 0;
}