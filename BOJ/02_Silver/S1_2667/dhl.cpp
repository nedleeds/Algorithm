#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int dR[4] = {-1, 1, 0, 0};
int dC[4] = { 0, 0,-1, 1};
vector<vector<int>> Map, Vst;
struct Node { int r, c; };

bool compare(int a, int b){
    return a < b;
}

int bfs(Node start, int& cnt)
{
    int element_num = 1;
    queue<Node> q;
    q.push(start);

    while (!q.empty()){
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            Node nxt = {now.r + dR[i], now.c + dC[i]};
            if (N <= nxt.r || nxt.r < 0 || N <= nxt.c || nxt.c < 0) continue;
            if (!(Map[nxt.r][nxt.c]) || Vst[nxt.r][nxt.c]) continue;
            q.push(nxt);
            Vst[nxt.r][nxt.c] = cnt;
            element_num++;
        }
    }

    cnt++;
    return element_num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    cin >> N;
    Map.resize(N, vector<int>(N, 0));
    Vst.resize(N, vector<int>(N, 0));

    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            char x;
            cin >> x;
            Map[r][c] = x - '0';
        }
    }

    int cnt = 1;
    vector<int> ans;
    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            if (Map[r][c] && !Vst[r][c]){
                Vst[r][c] = cnt;
                ans.push_back(bfs({r, c}, cnt));
            }
        }
    }
    
    cout << cnt - 1 << '\n';
    sort(ans.begin(), ans.end(), compare);
    for (auto v: ans){
        cout << v << '\n';
    }

    return 0;
}