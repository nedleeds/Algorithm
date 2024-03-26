#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;

    while (tc--){
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int is_true = 1;
        int cnt = 1;
        int og_x = x; int og_y = y;
        while (is_true){
            ++cnt;
            x = (x < m) ? x + 1 : 1;
            y = (y < n) ? y + 1 : 1;
            
            if (x == m && y == n){
                break;
            }
            if (x == og_x && y == og_y){
                cnt = -1;
                is_true = 0;
                break;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}