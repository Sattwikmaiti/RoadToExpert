// 1.?ND https://leetcode.com/problems/sorted-gcd-pair-queries/description/
// 2.https://www.youtube.com/watch?v=3trTWCCakHg (coprime pairs)
// 3.https://cses.fi/problemset/task/2185 prime multiples
// 4.?ND https://cses.fi/problemset/task/2417 counting coprimes

// 2. coprime pairs
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long ll

// ll main() {
//     ll a, b;
//     ll N=1e6+1;
//     cin >> a >> b;
//     vector<bool> isPrime(N,1);
//     vector<ll> primes;

//     for(ll i=2;i<=N;i++)
//     {

//         if(isPrime[i]!=1)
//           continue;
//         isPrime[i]=0;
//         primes.push_back(i);

//         for(ll j=i*i;j<=N;j+=i)
//               isPrime[j]=0;

//     }

//     vector<ll> req;
//     for(ll i=2;i<a+2;i++)
//       req.push_back(primes[i]);

//       ll ncp= (a*(a-1))/2 - b;
//       ll s=0;

//       if(ncp==0)
//       {
//             for(ll x:req)
//                cout<<x<<" ";
//                cout<<endl;
//                return 0 ;
//       }

//       req[0]*=2;
//       ll last=-1;

//       for(ll i=1;i<a;i++)
//        {
//            last=i;
//             if(s+i<ncp)
//                 {
//                     req[i]*=2;
//                     s+=i;

//                 }
//                 else break;

//        }
//       ncp-=s;

//       if(ncp)
//       {
//           req[last]*=3;
//           ll i=0;

//           while(ncp--)
//           {
//               req[i]*=3;
//               i++;
//           }

//       }

//       for(ll x:req)
//           cout<<x<<" ";

//     return 0;
// }

// 3.prime multiples

// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long int

// vector<vector<ll>> generateSubsets(ll arr[], ll n)
// {

//     vector<vector<ll>> subsets;

//     // Iterate over all possible combinations (2^n)
//     for (ll i = 0; i < (1 << n); ++i)
//     { // 1 << n is 2^n
//         vector<ll> subset;

//         // Check each bit of number i
//         for (ll j = 0; j < n; ++j)
//         {
//             // If j-th bit of i is set, include arr[j] in the subset
//             if (i & (1 << j))
//             {
//                 subset.push_back(arr[j]);
//             }
//         }

//         subsets.push_back(subset);
//     }

//     return subsets;
// }

// int main()
// {

//     ll n, k;
//     cin >> n >> k;
//     ll arr[k];

//     for (ll i = 0; i < k; i++)
//         cin >> arr[i];

//     ll ans = 0;
//     vector<vector<ll>> subs = generateSubsets(arr, k);
//     for (vector<ll> v : subs)
//     {
//         if(v.size()==0)
//           continue;
        
//         ll pr = n;
//         for (ll x : v)
//         {
//             pr /= x;
           
//         }
       

//         if (v.size() % 2 != 0)
//             ans +=pr;
//         else
//             ans -=  pr;
//     }
//     cout << ans << endl;

//     return 0;
// }