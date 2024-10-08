// https://codeforces.com/contest/2019/problem/E
??ND
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[500004];
ll maxm =0 ;

void dfs(vector<ll> graph[], ll node, ll parent, ll level)
{

    ll count = 0;

    maxm = max(level, maxm);
     // cout<<"#1 "<<node<<" "<<parent<<" "<<level<<" "<<count<<endl;
    for (ll child : graph[node])
    {
        if (child != parent)
        {
            count++;
        
          
            dfs(graph, child, node, level + 1);
        }

    }
  //  cout<<"#2 "<<node<<" "<<parent<<" "<<level<<" "<<count<<endl;
    // if(count>0)
    //  dp[level+1] += level + count ;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        maxm=0;

        memset(dp,0,sizeof(dp));
        
  

        vector<ll> graph[n + 1];
        for (ll i = 0; i < n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(graph, 1, -1, 0);

        for(ll i=0;i<=maxm;i++)
          cout<<dp[i]<<" ";
          cout<<endl;

        ll ans = 1e9;
        for (ll i=0;i<=maxm;i++)
            ans=min(ans,n-(dp[i]+1));
        cout<<ans<<endl;
    }
}