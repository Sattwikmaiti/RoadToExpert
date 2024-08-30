// https://codeforces.com/problemset/problem/1985/F
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool check(ll atk[], ll cool[], ll T, ll n, ll health)
{
    for (int i = 0; i < n; i++)
    {
        health -= atk[i];
        if (health <= 0)
           return true;
    }

    
    for (int i = 0; i < n; i++)
    {
        ll kp = (T - 1) / cool[i];
        health -= kp * atk[i];
      
       if (health <= (ll)0)
           return true;

       
    }


     if (health <=(ll) 0)
           return true;
           else return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll health, n;
        cin >> health >> n;

        ll atk[n], cool[n];

        for (int i = 0; i < n; i++)
            cin >> atk[i];

        for (int i = 0; i < n; i++)
            cin >> cool[i];

        ll ans = -1;

        ll l = 1, h = 1e12;

        // cout<<check(atk,cool,2,n,health)<<endl;

        while (l <= h)
        {
            ll midp = (l + h) / 2;
            if (check(atk, cool, midp, n, health))
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