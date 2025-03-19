#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*
Find the count of numbers from l to r whose sum of digits is equal to target.
*/

ll dp[20][200][2];

ll func(string &s, int inx, ll target, int type) {
    if (inx == s.length()) {
        return (target == 0) ? 1 : 0;
    }

    if (target < 0) {  // If target becomes negative, there's no valid sum / note if target ==0 , still there can ve 0's on the right side .
        return 0;
    }

    if (dp[inx][target][type] != -1) {
        return dp[inx][target][type];
    }

    int limit = (type == 1) ? s[inx] - '0' : 9;
    ll ans = 0;

    for (int i = 0; i <= limit; i++) {
        ans += func(s, inx + 1, target - i, (type == 1 && i == limit) ? 1 : 0);
    }

    return dp[inx][target][type] = ans;
}

ll solve(ll x, ll target) {
    if (x < 0) return 0;  // Prevents issues with l-1 being negative
    string s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return func(s, 0, target, 1);
}

int main() {

    int t;
    cin>>t;
    int k=1;
    while(t--)
    {
        
    ll l, r, target;
    cin >> l >> r >> target;

    ll ans1 = solve(r, target);
    ll ans2 = solve(l - 1, target);
    cout<<"Test case "<<k<<endl;
    k++;
    cout << "DP solution: " << ans1 - ans2 << endl;

    // Brute force checking
    int count = 0;
    for (int i = l; i <= r; i++) {
        int sum = 0, j = i;
        while (j > 0) {
            sum += j % 10;
            j /= 10;
        }
        if (sum == target) {
            count++;
        }
    }
    cout << "Brute force count: " << count << endl;

    cout<<endl;

   
}
}