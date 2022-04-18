#include <iostream>
#include <vector>
using namespace std;

void solve()
{

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;


    vector<int> pre(n + 1, 0);
    pre[0] = s[0] == '1';
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1')
            pre[i] = 1 + pre[i - 1];
    }

    vector<int> suf(n + 1, 0);
    suf[n - 1] = s[n - 1] == '1';
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '1')
            suf[i] = 1 + suf[i + 1];
    }

    int ans = k + suf[k];
    for (int i = k; i < n; i++)
    {
        int cur = k + pre[i - k] + suf[i + 1];
        ans = max(ans, cur);
    }

    cout << ans << endl;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}