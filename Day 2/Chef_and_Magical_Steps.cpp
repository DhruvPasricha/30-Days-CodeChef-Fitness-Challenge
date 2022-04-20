

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

using namespace std;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

const int N = 10000000;
int lp[N + 1] = {0};
vector<int> pr;

void pre()
{
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int justGreater(int x)
{
    int l = -1;
    int r = pr.size();

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (pr[m] >= x)
            r = m;
        else
            l = m;
    }
    return r;
}

int justSmaller(int x)
{
    int l = -1;
    int r = pr.size();

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (pr[m] <= x)
            l = m;
        else
            r = m;
    }
    return l;
}

int primes(int l, int r)
{
    if (l > r)
        return 0;

    l = justGreater(l);
    r = justSmaller(r);

    if (l > r)
        return 0;
    return r - l + 1;
}

#define length(l, r) r - l

void solve()
{

    int l, r;
    cin >> l >> r;
    int ans = length(l, r) - primes(l + 2, r);

    cout << ans << endl;
}

int32_t main()
{
    FastIO;
    pre();
    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //