#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<vector<int>> network;
    bool visit[101] = {false};
    network.resize(101);

    int c;
    cin >> c;
    for (int i = 0; i < c; i++){
        int src, tgt;
        cin >> src >> tgt;

        network[src].push_back(tgt);
        network[tgt].push_back(src);
    }

    int cnt = 0;
    queue<int> q;
    q.push(1);
    visit[1] = true;
    while (!q.empty()){
        int from = q.front();
        q.pop();

        for (auto to: network[from]){
            if (!visit[to]){
                visit[to] = true;
                cnt++;
                q.push(to);
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}