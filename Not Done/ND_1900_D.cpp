// https://codeforces.com/contest/2013/problem/D
?? ND
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(ll arr[], ll n, ll dif, ll minm, ll maxm)
{
    // minm const , maxm change - decreased
    pair<ll, ll> ch1 = {minm, minm + dif};

    // minm is increased , maxm is const

    pair<ll, ll> ch2 = {maxm - dif, maxm};

    if (arr[0] >= ch2.first)
    {
         ll s=0;

         for(int i=0;i<n;i++) 
         {
             if(s>0 && arr[i]>ch2.first)
                {
                    ll p=s;
                    s-=min(p,arr[i]-ch2.first);
                }
                else if(arr[i]<ch2.first )
                {
                    s+=ch2.first-arr[i];
                }
         }

         return s==0;


    }

    if (arr[n - 1] <= ch1.second)
    {
        // 1st be applied
        


         ll s=0;

         for(int i=0;i<n;i++)
         {
               
               if(arr[i]<ch1.second)
               {
                ll p=s;
                  if(s>0)
                  s-=min(p,(ch1.second-arr[i]));
                  else 
                  s-=arr[i]-ch1.first;
               }
               else if(arr[i]>ch1.second)
               {
                     s+=arr[i]-ch1.second;
               }

             
         }
         return s==0;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        ll maxm = -1, minm = 1e12;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxm = max(maxm, arr[i]);
            minm = min(minm, arr[i]);
        }

        ll ans = 0, l = 0, h = maxm-minm;
        cout<<check(arr,n,3,minm,maxm)<<endl;

        while (l <= h)
        {
            ll mid = (l + h) / 2;

            if (check(arr, n, mid, minm, maxm))
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }
}