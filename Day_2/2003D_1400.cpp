// https://codeforces.com/contest/2003/problem/D1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    vector<ll> bhai(200002, 0);
    for (int i = 0; i <= 200000; i++)
        bhai[i] = i;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        ll maxm = 0;

        for (int i = 1; i <= n; i++)
        {
            ll l;
            cin >> l;

            set<ll> s;

            for (int j = 1; j <= l; j++)

            {
                ll x;
                cin >> x;
                s.insert(x);
            }

            int change = 0;
            auto it = s.begin();
            ll jp = 0;
            while (change != 2)
            {
                 //  cout<<*it<<' '<<jp<<endl;
                if (*it == jp)
                {
                    jp++;

                    it++;
                }
                else
                {
                     maxm = max(maxm, jp);
                    jp++;

                    change++;
                }

                if (it == s.end())
                {   
                   
                    if(change == 1)
                    maxm = max(maxm, jp);

                    if(change==0)
                      maxm = max(maxm, jp+1);
                       


                    break;
                }
            }
        }

        ll s = (maxm + 1) * maxm;

        ll s2 = 0;
        if (m > maxm)
            s2 = ((m * (m + 1) / 2) - ((maxm * (maxm + 1) / 2))) + (maxm + 1) * maxm;
        else
            s2 = (m + 1) * maxm;

        cout << s2 <<endl;
    }
}