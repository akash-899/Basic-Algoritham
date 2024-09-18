#include<bits/stdc++.h>
using namespace std;
const int N = 1e+5;
bool dp[N];
bool make(int target,int current)
{
    if(current == target) return true;
    if(current > target || dp[current]) return false;
    dp[current] = true;
   int  ans = make(target,current+3) || make(target,current*2);
   return ans;
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        memset(dp,false,sizeof(dp));
        if(make(n,1))
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