// https://codeforces.com/contest/2014/problem/E
??ND
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<vector<ll>> dijkstra(vector<pair<ll, ll>> graph[], ll n, ll s, ll H[])
{

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    vector<ll> dis(n + 1, 1e9);
    // 0 ->without horse  1 -> with horse
    vector<vector<ll>> dist(2, vector<ll>(n + 1, 1e9));

    // wt,node,horse
    pq.push({0, s, H[s]});
    if (H[s] == 0)
        dist[1][s] = dist[0][s] = 0;
    else
    {
        dist[0][s] = 0;
        dist[1][s] = 0;
    }
    while (!pq.empty())
    {
        vector<ll> temp = pq.top();
        pq.pop();
        ll u = temp[1];
        ll w = temp[0];
        ll h = temp[2];

        for (auto i : graph[u])
        {
            ll v = i.first;
            ll wt = i.second;
            if (h == 0)
            {
                if (dist[0][v] > w + wt)
                {
                    dist[0][v] = w + wt;
                    if (H[v] == 0)
                        pq.push({dist[0][v], v, 0});
                    else
                    {
                        pq.push({dist[0][v], v, 1});
                        pq.push({dist[0][v], v, 0});
                    }
                }
            }
            else
            {
                if (dist[1][v] > w + wt / 2)
                {
                    dist[1][v] = w + wt / 2;
                    pq.push({dist[1][v], v, h});
                }
            }
        }
    }

    return dist;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, h;
        cin >> n >> m >> h;
        ll H[h + 2] = {0};

        for (ll i = 0; i < h; i++)
        {
            ll x;
            cin >> x;
            H[x] = 1;
        }

        vector<pair<ll, ll>> graph[n + 3];
        for (ll i = 0; i < m; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<vector<ll>> d1 = dijkstra(graph, n + 1, 1, H);
        vector<vector<ll>> d2 = dijkstra(graph, n + 1, n, H);

       
        ll ans = 1e9;
        for (ll i = 1; i <= n; i++)
        {
            ans = min(ans, max(d1[i], d2[i]));
        }

        if (ans == 1e9)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}