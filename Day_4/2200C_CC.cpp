// https://www.codechef.com/problems/SEQSEARCH

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;

    srand(time(0));
 
    while (t--)
    {
    


        



        ll a, b, k;
         cin >> a >> b >> k;

    

       
       ll ans=0;


        if (a == b)
        {
         
          ans=(k/2)*b;
        //  cout<<ans<<endl;




        }
        else if (a > b)
        {
        ll m=(a/b);
       // cout<<m<<endl;

       if(k==1)
        ans=0;
        else 


           if(k<=m+1)
              {
                  // cout<<(k-1)*b<<endl;
                ans=(k-1)*b;

              }else if (k==m+2)
                {
                   
                    ans=a;
                     //cout<<ans<<endl;

                }
                else {
                    k-=(m+2);

                    ll tk=k/2;
                    if(k%2!=0)
                      ans=(m+tk+1)*b;
                      else ans=a+(tk)*b;

                }

        }
        else
        {

            if(k==1)
               ans=0;
               else if(k==2)
                ans=a;
                  else if(k==3)
                  ans=b;
                  else {
                    ll tk=k-3;
                    ll m=tk/2;
                    ll kt=tk%2;
                    if(kt)
                    ans=a+(m+1)*b;
                      else ans=(m+1)*b;

                  }
        }

       cout<<ans<<endl;
    }
}