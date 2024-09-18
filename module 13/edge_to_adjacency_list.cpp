#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> v[n];
    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    return 0;
}