// https://www.codechef.com/problems/GDST

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
        string s;
        cin >> s;
       
        vector<int> ans;


        for(int i=0;i<n;i+=2)
        {
             if(s[i]==s[i+1])
                continue;

             if(ans.size()==0)   
             {
                  ans.push_back(i);
             }
             else {
                int x=s[ans[ans.size()-1]] -'0';
                int y=(s[i]-'0') ;
                 if((x ^ y)==0 )
                    {
                        ans.push_back(i+1);
                    }
                    else
                    {
                        ans.push_back(i);
                    }
             }

        }

        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
}