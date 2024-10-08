// https://www.codechef.com/problems/FILLIN0

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = 998244353;

int main()
{
    int t;
    cin >> t;
  
    ll fact[2 * 100001 + 2];

    fact[0] = fact[1] = 1;

    for (ll i = 2; i <= 2 * 100001; i++)
    {

        fact[i] = (fact[i - 1] * i) % mod;
    }

    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[2 * n + 4];

      
        vector<bool> prs(2 * n + 2, false);
        for (int i = 1; i <= 2 * n; i++)
        {
            cin >> arr[i];
            if (arr[i] != 0)
                prs[arr[i]] = true;
        }

        ll pair=0,first=0,second=0;
        for(ll i=1;i<=2*n; i++)
          {
            if(prs[i]==false)
            {
                 if(i<=n)
                   first++;
                   else 
                    second++;
            }

          }
         

          for(ll i=1;i<=2*n;i+=2)
             {
                 if(arr[i]==0 && arr[i+1]==0) 
                    {
                        pair++;
                    }
             }
         // cout<<first<<" "<<second<<" "<<pair<<endl;
             ll prdt=((fact[first]*fact[second])%mod);

             for(int i=1;i<=pair;i++)
                {
                    prdt=(prdt*2)%mod;
                }

             cout<<prdt<<endl;
    }
}