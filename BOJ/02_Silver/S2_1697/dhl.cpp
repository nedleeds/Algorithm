#include <iostream>
#include <queue>
using namespace std;

struct POS{ int p, cnt; };
queue<POS> Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int s, b;
    cin >> s >> b;

    Q.push({s, 0});
    POS ans = {0, -99};
    while (!Q.empty()){
        
        for (int i = 0; i < Q.size(); i++){
            POS sis = Q.front();
            Q.pop();

            if (sis.p + 1 == b or sis.p - 1 == b or sis.p * 2 == b){
                ans.cnt = sis.cnt + 1;
                break;
            }      

            Q.push({sis.p + 1, sis.cnt + 1});
            Q.push({sis.p - 1, sis.cnt + 1});
            Q.push({sis.p * 2, sis.cnt + 1});
        } 
        if (ans.cnt != -99){ break; }
    }

    cout << ans.cnt << '\n';

    return 0;
}