#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Compare {
public:
    bool operator() (int a, int b){
        return a > b;
    }
};

priority_queue<int, vector<int>, Compare> PQ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        if (x==0) {
            if (PQ.empty()){
                cout << "0\n";
                continue;
            }
            cout << PQ.top() << '\n';
            PQ.pop();
        }
        else {
            PQ.push(x);
        }

    }

    return 0;
}