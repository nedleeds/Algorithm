#include <iostream>
#include <queue>
using namespace std;

int MIN_CNT = 2134567890;
struct Item{ int value, cnt; };


void bfs(int n){
    queue<Item> Q;
    Q.push({n, 0});

    while (!Q.empty())
    {
        for (int i = 0; i < Q.size(); i++){
            Item now = Q.front();
            Q.pop();

            if (now.value % 3 == 0){
                if (now.value / 3 == 1){
                    MIN_CNT = now.cnt + 1;
                    return;
                }
                else{
                    Q.push({now.value / 3, now.cnt +1});
                }
            }
            if (now.value % 2 == 0){
                if (now.value / 2 == 1){
                    MIN_CNT = now.cnt + 1;
                    return;
                }
                else {
                    Q.push({now.value / 2, now.cnt + 1});
                }
            }
            if (now.value - 1 == 1){
                MIN_CNT = now.cnt + 1;
                return;
            }
            else{
                Q.push({now.value - 1, now.cnt + 1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    bfs(n);
    cout << MIN_CNT << '\n';

    return 0;
}