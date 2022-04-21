#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

int pow(int x, int n)
{

    if (n == 0)
        return 1;

    if (n & 1)
        return x * pow(x, n - 1);

    int half = pow(x, n / 2);

    return half * half;
}

int f(string &s, string &res, int type)
{
    int n = s.size();
    vector<int> boys, girls;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != res[i])
        {
            if (s[i] == 'B')
                boys.push_back(i);
            else
                girls.push_back(i);
        }
    }

    int ans = 0;
    n = boys.size();

    for (int i = 0; i < n; i++)
        ans += pow(abs(boys[i] - girls[i]), type);

    return ans;
}

void solve()
{
    int type;
    cin >> type;

    type = min(type, 1ll);

    string s;
    cin >> s;

    int n = s.size();

    int cg = 0;
    int cb = 0;

    for (int i = 0; i < n; i++)
    {
        cb += s[i] == 'B';
        cg += s[i] == 'G';
    }

    if (cg < cb)
    {
        swap(cg, cb);

        for (int i = 0; i < n; i++)
            if (s[i] == 'G')
                s[i] = 'B';
            else
                s[i] = 'G';
    }

    if (cg - cb > 1)
    {
        cout << -1 << endl;
        return;
    }

    string res = "";
    for (int i = 0; i < cb; i++)
        res += "GB";

    if (cg - cb == 1)
    {
        res += "G";
        cout << f(s, res, type) << endl;
    }
    else
    {
        int ans1 = f(s, res, type);
        reverse(res.begin(), res.end());
        int ans2 = f(s, res, type);

        cout << min(ans1, ans2) << endl;
    }
}

int32_t main()
{

    int tc;
    cin >> tc;

    while (tc--)
        solve();
}