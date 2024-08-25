// https://codeforces.com/problemset/problem/1605/C

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(int n, string &s)
{

    int minm = 1e9;

    int first = -1;

    int a = 0, b = 0, c = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            a++;
            pos.push_back(i);
        }
        if (s[i] == 'b')
            b++;
        if (s[i] == 'c')
            c++;

        if (b > a || c > a)
        {
            first = -1;
            a = 0;
            b = 0;
            c = 0;
        }
        else

            if (s[i] == 'a' && first == -1)
        {
            first = i;
        }
        else
        {

            if (first != -1 && i - first + 1 >= 2)
            {
                if (a > b && a > c)
                {
                    minm = min(minm, i - first + 1);
                    first = i;
                    a = 1;
                    b = 0;
                    c = 0;
                }
            }
        }
    }

    if (minm != 1e9)
    {
        cout << minm << endl;
        return;
    }

    bool f = false;
    int k=pos.size();
  
    for (int i = 0; i <= (k - 3); i++)
    {
        int p1 = pos[i];

        int p3 = pos[i + 2];
        int b=0,c=0;
         

        for(int i1=p1+1;i1<p3;i1++)
        {
            if(s[i1]=='b')
            b++;
            if(s[i1]=='c')
            c++;

        }

        if(b==2 && c==2)
              f=true;
    }

    if(f)
    cout<<7<<endl;
    else cout<<-1<<endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        solve(n, s);
    }
}