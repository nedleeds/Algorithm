#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dH[6] = {1, -1, 0,  0, 0,  0};
int dC[6] = {0,  0, 1, -1, 0,  0};
int dR[6] = {0,  0, 0,  0, 1, -1};
            
int M, N, H;
struct Tomato{int h, r, c; };
queue<Tomato> Ripe;
vector<vector<vector<int>>> Box;
vector<vector<vector<int>>> Vst;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    cin >> M >> N >> H;

    Box.resize(H, vector<vector<int>>(N, vector<int>(M, 0)));
    Vst.resize(H, vector<vector<int>>(N, vector<int>(M, -1)));

    for (int h = 0; h < H; h++){
        for (int r = 0; r < N; r++){
            for (int c = 0; c < M; c++){
                cin >> Box[h][r][c];

                if (Box[h][r][c] == 1){
                    Vst[h][r][c] = 0;
                    Ripe.push({h, r, c});
                }
            }
        }
    }

    int day = -1;
    while (!Ripe.empty()){
        Tomato now = Ripe.front();
        Ripe.pop();
        // ++day;

        for (int i = 0; i < 6; i++){
            Tomato nxt = {now.h + dH[i], now.r + dR[i], now.c + dC[i]};
            if (nxt.h < 0 || nxt.h >= H) continue;
            if (nxt.r < 0 || nxt.r >= N) continue;
            if (nxt.c < 0 || nxt.c >= M) continue;
            if (Box[nxt.h][nxt.r][nxt.c] == -1) continue;
            if (Vst[nxt.h][nxt.r][nxt.c] != -1) continue;
            
            Ripe.push(nxt);
            Vst[nxt.h][nxt.r][nxt.c] = day;
        }
    }

    cout << day << '\n';

    return 0;
}