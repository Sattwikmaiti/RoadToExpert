// https://codeforces.com/problemset/problem/2004/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string arr[n];
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sort(arr[i].begin(), arr[i].end());

            mp[arr[i]].push_back(i);
        }

        while (q--)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            int k = max(a, b);
            int l = min(a, b);
            a = l;
            b = k;
            string s = arr[a];
            string d = arr[b];

            if (s[0] == d[0] || s[1] == d[1] || s[0] == d[1] || s[1] == d[0])
            {
                cout << abs(b - a) << endl;
                continue;
            }

            vector<string> sets;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    string t1(1, s[i]);
                    string t2(1, d[j]);
                    string val = t1 + t2;
                    sort(val.begin(), val.end());
                    sets.push_back(val);
                }
            }

            int ans = INT_MAX;
            for (string val : sets)
            {

                if (mp.find(val) != mp.end())
                {

                    auto pos = upper_bound(mp[val].begin(), mp[val].end(), a) - mp[val].begin();
                    
                    if(pos>0)
                    ans = min(ans, abs(a - mp[val][pos - 1]) + abs(mp[val][pos - 1] - b));
                    if(pos<mp[val].size())
                    ans = min(ans, abs(a - mp[val][pos]) + abs(mp[val][pos] - b));
                }
            }

            if (ans == INT_MAX)
                cout << -1 << endl;
            else
                cout << ans << endl;
        }
    }
}