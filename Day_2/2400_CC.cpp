// https://www.codechef.com/problems/MMA
//  https://www.codechef.com/problems/CXZ

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(vector<ll> &arr, ll n, ll x, ll k, map<ll, int> &mp)
{
    // only x with iff possible k use for freq>1 only once - c

    // agar isse bada koi elemenet nhi - n . else jo >=x , that index
    ll pos = lower_bound(arr.begin(), arr.end(), x * k) - arr.begin();
    ll t = pos;
    ll kpos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    if (pos == 0)
    {
        cout << 0 << endl;
        return;
    }
    ll duble[n] = {0};

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (mp[arr[i]] > 1)
                duble[i] = 1;
            else
                duble[i] = 0;
        }
        else if (mp[arr[i]] > 1)
        {
            duble[i] = duble[i - 1] + 1;
        }
        else
        {
            duble[i] = duble[i - 1];
        }
    }

    ll spos = kpos;

    spos--;
    // atleast one answer is there
    ll ans = 0;


    int len = 0;
  

    for (int i = spos; i >= 0; i--)
    {
        len++;

        pos = lower_bound(arr.begin(), arr.end(), arr[i] * k) - arr.begin();

        pos--;

       

        ll kt=pos>spos? spos : pos; 

        ll extra=i==0?duble[kt] : duble[kt]-duble[i-1];

        ll nw= pos>spos ? extra+ i + pos-spos +len : extra+i+len;




      
        ans = max(ans, nw);
    }
    cout << max(ans, t) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, k;
        cin >> n >> x >> k;

        map<ll, int> mp;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            mp[x]++;
        }

        vector<ll> arr;
        for (auto x : mp)
        {
            arr.push_back(x.first);
        }

        solve(arr, mp.size(), x, k, mp);
    }
}