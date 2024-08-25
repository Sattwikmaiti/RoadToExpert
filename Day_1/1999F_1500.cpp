// https://codeforces.com/problemset/problem/1999/F

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll f[200002];
ll p=1e9+7;
// a ^ b (log b)
// exponentation by squaring
ll exp(ll a, ll b) {
    if (b == 0) return 1;
    if (b ==  1) return a;
    ll half = exp(a, b/2) % p;
    ll ans = (half * half) % p;
    if (b&1) {ans *= a; ans %= p;}
    return ans;
}
 
 //nCr
ll nCr(ll n, ll r) {
    if (r > n) return 0;
    return ((f[n] * exp(f[r], p-2)) % p * exp(f[n-r], p-2)) % p;
}

void initFact()
{
    f[0]=f[1]=1;
     
     for(ll i=2;i<=200002;i++)
     {
        f[i]=(f[i-1]*i)%p;
         
     }
}
 
int main()
{
    initFact();
    int t;
    cin >> t;
  
 
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll arr[n], pref[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

           
        }

        sort(arr,arr+n);

        for(int i=0;i<n;i++)
        {
             if (i == 0)
            {
                pref[i] = arr[i];
            }
            else
            {
                pref[i] = pref[i - 1] + arr[i];
            }
        }

        ll ans = 0;
        
        for (int i = 0; i < n; i++)
        {

            if (arr[i] == 0)
                continue;

            ll s1=nCr(i,(k-1)/2);
            
            ll s2=nCr(pref[n-1]-pref[i],(k-1)/2);

           
            ans=(ans+(s1*s2)%p)%p;


        }
        cout<<ans<<endl;
    }
}