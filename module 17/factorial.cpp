#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n == 0) //base case
    {
        return 1;
    }
    int choto = fact(n-1);
    return choto*n;
}
int main()
{
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}