#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1005;
vector<pair<ll, ll>> v[N];
ll dis[N];
class cmp
{
    public:
      bool operator()(pair<ll, ll> a, pair<ll, ll> b)
      {
        return a.second > b.second;
      }
};
void dijkstra(int src)
{
    priority_queue<pair<ll, int>,vector<pair<ll, ll>>, cmp> pq;
    pq.push({src,0});
    dis[src] = 0;
    while(!pq.empty())
    {
        pair<ll, ll> parent = pq.top();
        pq.pop();
        ll node = parent.first;
        ll cost = parent.second;
        for(pair<int, int> child: v[node])
        {
            ll childNode = child.first;
            ll childCost = child.second;
            if(cost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }

    for(int i=1; i <=n; i++)
    {
        dis[i] = INT_MAX;
    }

    int src;
    cin >> src;
    dijkstra(src);

    int t;
    cin >> t;
    while(t--)
    {
        ll d;
        ll dw;
        cin >> d >> dw;
        if(dis[d] <= dw)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
     
    return 0;
}