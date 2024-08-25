// https://codeforces.com/problemset/problem/1223/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool solve(ll arr[], ll n, ll x, ll a, ll y, ll b, ll k, ll t)
{

    sort(arr, arr + n);

    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    int j = 0;

  


    for (int i = 1; i <= t; i++)
    {

        if (i % a != 0 && i % b != 0)
        {
            mp[arr[j]]--;
            j++;
        }
    }

    vector<ll> nw;

    for (pair<ll, ll> p : mp)
    {
        for (int i = 1; i <= p.second; i++)
            nw.push_back(p.first);
    }

    sort(nw.begin(), nw.end());
    reverse(nw.begin(), nw.end());
  
//   for(ll x: nw)
//     cout<<x<<" ";
//     cout<<endl;

    ll s=0,s1=0;

    
    ll c1=true,c2=true;

    if(c1)
    {
        ll j=0;

        for(int i=1;i<=t;i++)
        {
              if(i%a==0 && i%b==0)
                {
                    s1+=nw[j] * ((x+y)/100.0);
                    j++;
                }
              
        }
        for(int i=1;i<=t;i++ )
           {
           
            if(i%a==0 && i%b!=0)
               {
                s1+=nw[j] * (x/100.0);
                j++;
               }
           }
           for(int i=1;i<=t;i++ )
           {
            
            if(i%b==0 && i%a!=0)
               {
                s1+=nw[j] * (y/100.0);
                j++;
               }
           }
    }
    if(c2) {
        ll j=0;
          for(int i=1;i<=t;i++)
        {
              if(i%a==0 && i%b==0)
                {
                    s+=nw[j] * ((x+y)/100.0);
                    j++;
                }
              
        }
        for(int i=1;i<=t;i++ )
           {
           
            if(i%b==0 && i%a!=0)
               {
                s+=(nw[j] * (y/100.0));
                j++;
               }
           }
        for(int i=1;i<=t;i++ )
           {
            if(i%a==0 && i%b!=0)
               {
                s+=(nw[j] * (x/100.0));
                j++;
               }
           }

         
           

    }

    return s>=k || s1>=k;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, a, y, b, k;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cin >> x >> a;
        cin >> y >> b;
        cin >> k;

        ll ans = -1;
        ll l = 0, h = n;
        while (l <= h)
        {
            ll midp = (l + h) / 2;
           
           //cout<<midp<<endl;
            if(solve(arr, n, x, a, y, b, k,midp))
            {
                ans = midp;
                h = midp - 1;
            }
            else
                l = midp + 1;
        }

        cout << ans << endl;
    }
}