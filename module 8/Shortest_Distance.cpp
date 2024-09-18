#include<bits/stdc++.h>
#define ll long long int
const ll INF = 1e18;
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll adj[n+1][n+1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            adj[i][j] = INF;
            if(i == j) adj[i][j] = 0;
        }
    }
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < adj[a][b]) 
        { 
            adj[a][b] = c; 
        } 
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    ll t;
    cin >> t;
    while(t--)
    {
        ll s,d;
        cin >> s >> d;
        if (adj [s][d] == INF)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << adj[s][d] << endl;
        }
    }

    return 0;
}