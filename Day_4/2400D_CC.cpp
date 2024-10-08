// https://www.codechef.com/problems/COUNTWINSUB

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = i; j < n; j++)
            {
                ll c0 = 0, c1 = 0;
                bool f = false;

                for (int k = i; k <= j; k++)
                {
                    if (arr[k] == 1)
                    {
                        c1++;
                        if (k + 1 <= j && arr[k + 1] == 1)
                        {
                            f = true;
                            break;
                        }
                        if (k + 1 <= j && k + 2 <= j && arr[k + 1] == 0 && arr[k + 2] == 1)
                        {
                            f = true;
                            break;
                        }
                    }
                    else
                        c0++;
                }
                if (c1 > c0 || f)
                    ans++;
            }
            // cout<<c1<<" "<<c2<<" "<<i<<" "<<j<<endl;
        }

        ll test = ans;

         // find ending index of 101 and 11 .
         /*
           1 1 0 0 1 1 0 1 
           0 1 2 3 4 5 6 7 

           11 - { 1, 5}
           101 - { 7 }

          i=0 1 - 1+[0-1,2,3,4,5,6,7]
           i=1 1 - 1+[ 5 ,6,7]
           i=2 0 - 0 + [ 5, 6,7]
           i=3 0 - 0 + [ 5, 6,7]
              i=4 1 - 1 + [ 5, 6,7]
              i=5 1 - 1+[ 7 ]
              
         
         */



        if (ans != test)
        {
            cout << n << " " << ans << " " << test << endl;
        }
    }
}