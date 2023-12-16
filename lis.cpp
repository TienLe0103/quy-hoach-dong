/*
    16 / 12 / 2023
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define in int64_t
#define FOR(x, l, r) for(in x = l; x < r; x++)
#define FOr(x, l, r) for(in x = l; x >= r; x--)
#define vi vector<in>

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    in n; cin >> n;
    vi a(n), dp(n, 1);
    
    FOR(i, 0, n) cin >> a[i];

    FOR(i, 0, n)
        FOR(j, 0, i)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    // Truy van
    in length = *max_element(dp.begin(), dp.end());
    vi lis;
    FOr(i, n - 1, 0) if (dp[i] == length) lis.push_back(a[i]), length--;
    reverse(lis.begin(), lis.end());
    for(in x : lis) cout << x << ' ';
}
