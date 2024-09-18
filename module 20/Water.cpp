#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans=INT_MIN;
        int ai,aj;
        int i = 0;
        int j = n-1;
        while(i < j)
        {
            if(min(a[i],a[j]) > ans)
            {
                ans = min(a[i],a[j]);
                ai = i;
                aj = j;
            }
            if(a[i] < a[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        cout << ai << " " << aj << endl;
    }
    return 0;
}