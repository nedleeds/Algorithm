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
        int m, n, tgt_x, tgt_y;
        cin >> m >> n >> tgt_x >> tgt_y;

        int year = 1;
        int x = 1; int y = 1;
        while (true){
            if (x == tgt_x && y == tgt_y){ break; }
            else {
                if (x == m && y == n){ year = -1; break; }
            } 

            x = (x < m) ? x + 1 : 1;
            y = (y < n) ? y + 1 : 1;
            ++year;
        }
        cout << year << '\n';
    }

    return 0;
}