#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll f[200002];
ll p=1e9+7;
// a ^ b (log b)

ll exp(ll x,ll n)
{
      // x^n mod p 

      ll ans=1;

      while(n>0)
      {
          if(n%2==1)
          {
              //odd n 
              ans=(ans*x)%p;
              n--;
          }

          // n is even now

          x= (x*x)%p;
          n=n/2;


      }

      return ans;
}
// nCr
ll nCr(ll n, ll r) {
    if (r > n) return 0;
    return ((f[n] * exp(f[r], p-2)) % p * exp(f[n-r], p-2)) % p;
}

void initFact() {
    f[0] = f[1] = 1;
    for(ll i = 2; i <= 200002; i++) {
        f[i] = (f[i-1] * i) % p;
    }
}
int main()
{  
    initFact();
    cout<<nCr(5,2);

      
}