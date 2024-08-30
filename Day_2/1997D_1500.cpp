// https://codeforces.com/problemset/problem/1997/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dfs(int node, vector<ll> graph[], ll arr[], ll parent)
{
    ll minm = 1e9;

    for (auto child : graph[node])
    {
        if (child != parent)
        {
            minm = min(minm, dfs(child, graph, arr, node));
        }
    }

    if (minm != 1e9 && minm > arr[node])
        arr[node] += (minm - arr[node]) / 2;

     if(minm!=1e9 && minm<=arr[node])   
           arr[node]=minm;

    

    return arr[node];
}

int main()
{
    int t;
    cin >> t;

    int k=0;

    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n + 3];
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        vector<ll> graph[n + 2];

        for (int i = 2; i <= n; i++)
        {
            ll x;
            cin >> x;
            graph[x].push_back(i);
            graph[i].push_back(x);
        }

        ll s = 1e9;
        for (int child : graph[1])
        {
            s = min(s, dfs(child, graph, arr, 1));
        }
   
        cout << s + arr[1] << endl;

        if(s+arr[1]== 4 && k==3)
           {
                
           }
    }
}