// https://codeforces.com/problemset/problem/1989/C

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int b[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];
        // neg=-1,-1  pos=1,1
        int neg = 0, pos = 0;

        int s1 = 0, s2 = 0;

        for (int i = 0; i < n; i++)
        {
            if ((a[i] == 0 && (b[i] == -1 || b[i] == 0)) || (b[i] == 0 && (a[i] == -1 || a[i] == 0)))
                continue;

            if (a[i] == 1 && b[i] == 1)
                pos++;
            else if (a[i] == -1 && b[i] == -1)
                neg++;
            else
            {
                if (a[i] == 1 && (b[i] == 0 || b[i] == -1))
                    s1++;
                else
                    s2++;
            }
        }

        int maxm = max(s1, s2);
        int minm = min(s1, s2);

        if (pos > 0)
        {

            int excess = maxm - minm;

            if (pos >= excess)
            {
                minm = maxm;
                pos -= excess;
                maxm+=pos/2;
                minm+=(pos-pos/2);
            }
            else
                minm += pos;
        }

        if (neg > 0)
        {
            int excess = maxm - minm;

            if (neg >= excess)
            {
                maxm = minm;
                neg -= excess;
                maxm-=neg/2;
                minm-=(neg-neg/2);
            }
            else
            {
                maxm -= neg;
            }
        }

        cout<<min(maxm,minm)<<endl;
    }
}