#include <bits/stdc++.h>
using namespace std;

#define ll long long int
// gcd(a,b)= gcd(b,a%b)  where a is larger and b is smaller
vector<int> gcd(ll a, ll b)
{
    if (b == 0)
    {
        vector<int> xyg = {1, 0, a};
        return xyg;
    }

    vector<int> xyg = gcd(b, a % b);

    vector<int> xyg1 = {xyg[1], xyg[0] - (a / b) * xyg[1], xyg[2]};

    return xyg1;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    vector<int> xyg = gcd(a, b);
    cout << "GCD: " << xyg[2] << endl;
    cout << "X: " << xyg[0] << endl;
    cout << "Y: " << xyg[1] << endl;
    return 0;
}