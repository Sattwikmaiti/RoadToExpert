// https://codeforces.com/problemset/problem/1201/C

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool check(ll arr[],ll n,ll k,ll maxm)
{
    int end=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<maxm)
            {
                end=i;
            }
    }

    if(end<n/2)
       return true;

       for(int i=n/2;i<=end;i++)
         {
              k-=(maxm-arr[i]);
         }

        
   
   return k>=0;

}

int main()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    ll ans = arr[n / 2];
    ll l = ans, h = 1e10;

    while (l <= h)
    {
         ll midp=(l+h)/2;
            
         if(check(arr,n,k,midp))
          {
            ans=midp;
            l=midp+1;
          }
          else 
            {
                h=midp-1;
            }

    }
    cout<<ans<<endl;
}