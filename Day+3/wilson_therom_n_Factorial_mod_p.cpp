#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll p = 299;

// (n-p)<=1000
// a ^ b (log b)

ll exp(ll x, ll n)
{
    // x^n mod p

    ll ans = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            // odd n
            ans = (ans * x) % p;
            n--;
        }

        // n is even now

        x = (x * x) % p;
        n = n / 2;
    }

    return ans;
}
int main()
{

    ll n;
    cin >> n;
    if (n >= p)
    {
        cout << 0 << endl;
        return 0;
    }

    ll ans = p - 1;

    for (ll i = n + 1; i < p; i++)
        ans = (ans * exp(i, p - 2)) % p;

    cout << ans << endl;
}