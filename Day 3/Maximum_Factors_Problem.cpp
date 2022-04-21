#include <iostream>
#include <map>
using namespace std;

#define int long long

int32_t main()
{

    int t;
    scanf("%lld", &t);

    while (t-- > 0)
    {
        int n;
        scanf("%lld", &n);

        map<int, int> mp;

        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {

                mp[i]++;
                n /= i;
            }
        }
        
        if(n > 1) mp[n]++;
        
        int total = 1;
        
        for(auto &it : mp) 
        {
            total *= (it.second + 1);
        }
        
        int prevFactors = 0;
        int ans = 1;
        
        for (auto &it : mp)
        {
            int factors = ((total) / (it.second + 1)) * (it.second);
            
            if(factors > prevFactors) {
                prevFactors = factors;
                ans = it.first;
            }
        }

        printf("%lld\n", ans);
    }
}