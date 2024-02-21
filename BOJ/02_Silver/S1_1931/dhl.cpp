#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node { int start, end; };
queue<int> Qstarts;
vector<vector<int>> AdjList(100001);
bool Visit[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        Qstarts.push(start);

        AdjList[start].push_back(end);
    }    

    while !Qstarts.empty(){
        int start = Qstarts.front();
        Qstarts.pop();
        Visit[start] =true;

        if (AdjList[start].empty()){ continue; }

        
        Visit.clear();
    }

    return 0;
} 