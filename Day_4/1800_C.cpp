// https://codeforces.com/contest/2005/problem/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string ans = "narek";

int dp[10000][6];

int f(string arr[], int n, int ind, int pos)
{
    if (ind == n)
    {
        return -2 * pos;
    }

    if(dp[ind][pos]!=-1)
       return dp[ind][pos];

    int ntake = f(arr, n, ind + 1, pos);

    int take=0;

    int l=pos;
    

    for (int i = 0; i < arr[ind].length(); i++)
    {
        if (arr[ind][i] == ans[pos])
        {
            pos = (pos + 1) % 5;
            take++;
        }
        else if (arr[ind][i] == 'n' || arr[ind][i] == 'a' || arr[ind][i] == 'r' || arr[ind][i] == 'e' || arr[ind][i] == 'k')
            take--;
    }

 take+= f(arr, n, ind + 1, pos);
    return dp[ind][l]= max(ntake, take);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string arr[n];

        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << f(arr, n, 0, 0) << endl;
    }
}