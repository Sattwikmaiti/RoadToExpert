// https://codeforces.com/problemset/problem/1951/C

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll norm[n];

        pair<ll, ll> arr[n];ll freq[n];
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            norm[i] = x;
            arr[i] = {x, i};

            freq[i] = 0;
        }

        sort(arr, arr + n);

        for (int i = 0; i < n; i++)
        {
            if (k >= m)
            {
                freq[arr[i].second] = m;
                k -= m;
            }
            else
            {
                freq[arr[i].second] = k;
                break;
            }
        }
        ll ans = 0;
        ll fr = 0;

        for (int i = 0; i < n; i++)
        {
            if (freq[i] > 0)
            {
                ans += norm[i] * freq[i] + fr * freq[i];
                fr+=freq[i];
            }
        }
        cout<<ans<<endl;
    }
}