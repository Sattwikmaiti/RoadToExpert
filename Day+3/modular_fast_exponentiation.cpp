#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll xpown(ll x,ll n,ll p)
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


int main()
{
    cout<<xpown(2,4,1000007);
       
}
