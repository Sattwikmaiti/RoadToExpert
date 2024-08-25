// https://codeforces.com/problemset/problem/1443/C

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool check(ll arr[], ll brr[], ll n, ll mid)
{

   

    vector<pair<ll, ll>> vr;
    for (int i = 0; i < n; i++)
    {
        vr.push_back({arr[i], brr[i]});
    }
    sort(vr.begin(), vr.end());
    ll s=0;
    
    for(int i=0;i<n;i++)
    {
          if(arr[i]<=mid)
            continue;

            s+=brr[i];


    }

    return s<=mid;

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n], brr[n];
        ll h = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
            h += brr[i];
        }

        ll l = 0, ans = 0;
        while (l <= h)
        {
            ll midp = (l + h) / 2;

            if (check(arr, brr, n, midp))
            {
                ans = midp;
                h = midp - 1;
            }
            else
            {
                l = midp + 1;
            }
        }

        cout << ans << endl;
    }
}