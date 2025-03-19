//https://www.codechef.com/problems/SHOOT0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
     int t;
     cin>>t;
     while(t--)
     {
          int x,n;
          cin>>x>>n;
          int a[n];
          for(int i=0;i<n;i++)
             cin>>a[i];

          for(int i=0;i<n;i++)    
          {
            int al=0,k=0;
            //al - 1  kr - 2  both - 3 
             for(int j=0;j<n;j++)
             {
                if(a[j]==0 || a[j]==3)
                  continue;

                 if(a[j]==1) 
                    al+=abs(j-i);
                  else 
                  k+=abs(j-i)  ;

                 
             }

             cout<<abs(al-k)<<" ";
          }
          cout<<endl;
     }
}