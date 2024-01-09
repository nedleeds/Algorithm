#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    int m = 1;
    int s = 1;

    cin >> n >> k;
    for (int i = n-k+1; i <= n; i++){
        m = m * i;
    }

    for (int j = 1; j <= k; j++){
        s = j * s;
    }

    int ans = int(m / s);
    cout << ans << '\n';

    return 0;
}