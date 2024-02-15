#include <iostream>
#include <queue>
using namespace std;

struct POS{ int p, cnt; };
bool DAT[100001];
queue<POS> Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int s, b;
    cin >> s >> b;

    Q.push({s, 0});
    while (!Q.empty()){
        
        for (int i = 0; i < Q.size(); i++){
            POS sis = Q.front();
            DAT[sis.p] = true;
            Q.pop();

            if (sis.p == b){
                cout << sis.cnt << '\n';
                return 0;
            }      
            
            if (sis.p + 1 <= 100000 && !DAT[sis.p + 1]){
               Q.push({sis.p + 1, sis.cnt + 1});
            }
            if (sis.p - 1 >= 0 && !DAT[sis.p - 1]){
                Q.push({sis.p - 1, sis.cnt + 1});
            }
            if (sis.p * 2 <= 100000 && !DAT[sis.p * 2]){
                Q.push({sis.p * 2, sis.cnt + 1});
            }
        } 
    }

    return 0;
}