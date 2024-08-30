// https://codeforces.com/problemset/problem/1965/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);

        // x==1 alice chance
        int x = 1;
        ll sub = 0;

        int i = 0;
        while (i != n)
        {
            if (arr[i] - sub == 0)
            {
                i++;
                continue;
            }

            arr[i]-=sub;


            sub = (arr[i]);
            i++;
            x = 1 - x;
        }
        x^=1;

        if(x)
          cout<<"Alice"<<endl;
          else cout<<"Bob"<<endl;
    }
}