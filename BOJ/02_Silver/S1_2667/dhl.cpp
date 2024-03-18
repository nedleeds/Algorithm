#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int N, Cnt = 1;
int dR[4] = {1, -1, 0, 0};
int dC[4] = {0, 0, -1, 1};
vector<vector<int>> Map, Vst, Grp;
struct Node{ int r, c; };

void set_map()
{
    cin >> N;
    Map.resize(N, vector<int>(N, 0));
    Vst.resize(N, vector<int>(N, 0));
    Grp.resize(N, vector<int>(N, 0));

    for (int r = 0; r < N; r++){
        string s;
        cin >> s;
        for (int c = 0; c < N; c++){
            Map[r][c] = s[c] - '0';
        }
    }
}

void bfs(int r, int c)
{
    queue<Node> q;
    q.push({r, c});
    Vst[r][c] = 1;

    while (!q.empty()){
        Node now = q.front();
        q.pop();

        if (Map[now.r][now.c]){
            Grp[now.r][now.c] = ++Cnt;
        }

        for (int i = 0; i < 4; i++){
            Node nxt = {now.r + dR[i], now.c + dC[i]};
            if (nxt.r < 0 || nxt.r >= N) continue;
            if (nxt.c < 0 || nxt.c >= N) continue;
            if (Vst[nxt.r][nxt.c]) continue;

            if (Map[nxt.r][nxt.c]){
                Vst[nxt.r][nxt.c] = 1;
                q.push(nxt);
                Grp[nxt.r][nxt.c] = Cnt;
            }
        }

    }
}

int main()
{   
    fastio;
    freopen("input.txt", "r", stdin);
    
    set_map();
    bfs(0, 0);

    cout << Cnt << '\n';

    return 0;
}