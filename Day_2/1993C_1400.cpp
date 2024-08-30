// https://codeforces.com/problemset/problem/1993/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        ll maxm = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxm = max(maxm, arr[i]);
        }

        sort(arr, arr + n);

        set<pair<ll, ll>> s;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == maxm)
            {
                s.insert({arr[i], 1});

                continue;
            }

            ll tn = (maxm + k - arr[i]) / k;

            ll parity = (tn - 1) % 2 == 0 ? 1 : 0;

            s.insert({(tn - 1) * k + arr[i], parity});
        }

        ll pos0 = -1, pos1 = -1;
        int par = -1;
        bool f = true;
        ll low = -1, high = -1;

     
        for (pair<ll, ll> p : s)
        {
            if (p.first == maxm)
            {
                if (par == -1)
                    par = p.second;

                else
                {
                    f = false;
                    break;
                }
            }

            if (p.second == 0)
            {

                if (pos1==1)
                {
                    f = false;
                    break;
                }
                pos0 = 1;

               
                    low = p.first + k;
            }

            if (p.second == 1)
            {
                pos1 = 1;

                if (pos0 == -1)
                    high = p.first;
                else if (high == -1)
                    high = p.first + k;
            }
        }

        if (f == false || low == high)
            cout << -1 << endl;
        else if (low == -1)
            cout << high << endl;
        else
            cout << low << endl;
    }
}