#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            /*
            n(1-1/p1)(1-1/p2)...(1-1/pk)
            (n-n/p1)(1-1/p2)...(1-1/pk)
            n1(1-1/p2)...(1-1/pk)
            */

            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{

    ll n;
    cin >> n;

    cout << phi(n);
}