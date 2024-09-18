#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge
{
    public:
    ll u, v, c;
    Edge(ll u, ll v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const ll N = 1e18;
const ll n=1005;
ll dis[n];
vector<Edge> EdgeList;
int main()
{
    ll n, e;
    cin >> n >> e;
    
    while(e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u,v,c));
    }
    for(int i = 1; i <= n; i++)
    {
        dis[i] = N;
    }
    ll src;
    cin >> src;
    dis[src] = 0;
   for(int i = 1; i <= n-1; i++)
   {
     for(Edge ed: EdgeList)
    {
        ll u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if(dis[u] != N && dis[u] + c < dis[v])
        {
            dis[v] = dis[u] + c;
        }
    }
   }
   bool cycle = false;
    for(Edge ed: EdgeList)
    {
        ll u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if(dis[u] < N && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if(cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    
     ll t;
    cin >> t;
   
    while(t--)
    {
         ll des;
        cin >> des;
        if(cycle==false)
        {
            if(dis[des] < N)
        {
            cout << dis[des] << endl;
        }
        else
        {
            cout << "Not Possible" << endl;
        }
        }

    }
   
    return 0;
}