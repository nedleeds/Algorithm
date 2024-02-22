#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int start, end;
};
vector<Node> Nodes;
bool compare(Node a, Node b){
    if (a.end < b.end) {
        return true;
    }
    if (a.end == b.end){
        if (a.start < b.start) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        Node nd;
        cin >> nd.start >> nd.end;
        Nodes.push_back(nd);
    }

    sort(Nodes.begin(), Nodes.end(), compare);

    int curEnd = Nodes[0].end;
    int cnt = 1;
    for (int i = 1; i < Nodes.size(); i++){
        if (Nodes[i].start < curEnd) { continue; }
        curEnd = Nodes[i].end;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}