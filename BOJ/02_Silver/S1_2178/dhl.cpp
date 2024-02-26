#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dR[4] = {1, -1, 0, 0};
int dC[4] = {0, 0, -1, 1};
struct Node {int r, c, cnt;};
queue<Node> Q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n);
    vector<vector<int>> vst(n);
    for (int r = 0; r < n; r++){
        string x;
        cin >> x;
        for (int c = 0; c < m; c++){
            arr[r].push_back(int(x[c] - '0'));
            vst[r].push_back(0);
        }
    }

    Node start = {0, 0, 1};
    vst[start.r][start.c] = 1;
    Q.push(start);
    
    while (!Q.empty()){
        Node now = Q.front();
        Q.pop();

        if (now.r == n - 1 && now.c == m - 1){
            cout << now.cnt << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i ++){
            if (now.r + dR[i] < 0 || now.r + dR[i] >= n) { continue; }
            if (now.c + dC[i] < 0 || now.c + dC[i] >= m) { continue; }
            
            Node nxt = {now.r + dR[i], now.c + dC[i], now.cnt + 1};
            if (vst[nxt.r][nxt.c])      continue;
            if (arr[nxt.r][nxt.c] == 0) continue;

            vst[nxt.r][nxt.c] = 1;
            Q.push(nxt);
        }

    }


    return 0;
}