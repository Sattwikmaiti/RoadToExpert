// https://codeforces.com/problemset/problem/1990/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        map<ll, ll> mp;
        map<ll, ll> mp2;
        ll fre[n];

        ll fre2[n];

        ll s = 0;
        ll maxm = 0;
        ll maxm2 = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;

            s += arr[i];
            if (mp[arr[i]] >= 2 && arr[i] > maxm)
                maxm = arr[i];

            fre[i] = maxm;
            mp2[fre[i]]++;

            if (mp2[fre[i]] >= 2 && fre[i] > maxm2)
                maxm2 = fre[i];

            fre2[i] = maxm2;

            s += fre[i];
        }

         maxm = 0;
        ll tk = 0;
        for (ll i = 0; i < n; i++)
        {
            if (fre2[i] == 0)
                continue;

            maxm = max(maxm, n - i);

            s += fre2[i] * (maxm - tk);
            tk++;
        }
        cout << s << endl;
    }
}