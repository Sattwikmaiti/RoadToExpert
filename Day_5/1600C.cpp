#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/1920/C
#define ll long long int

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n+2];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        vector<ll> fact;
        for(ll i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                fact.push_back(i);
                if(n/i!=i)
                {
                    fact.push_back(n/i);
                }
            }
        }

        sort(fact.begin(),fact.end());

    

        ll ans=0;

       

        for(ll k:fact)

        {
            
             ll gcd=-1;
              for(ll i=1;i<=n-k;i++)
                 {
                    ll m=abs(arr[i]-arr[i+k]);
                    //cout<<m<<endl;
                    if(gcd==-1)
                    {
                        gcd=m;
                    }
                    else
                    {
                        gcd=__gcd(gcd,m);
                    }

                 }
                 
                 if(gcd>=2 || gcd==0 || k==n)
                    ans++;
                    //cout<<k<<"- > "<<gcd<<endl;
        }

     cout<<ans<<endl;


    }
}