#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    queue<int> q;

    while(N--){
        string cmd;
        cin >> cmd;
        
        if (cmd == "push"){
            int v;
            cin >> v;
            q.push(v);
        }
        else if (cmd == "pop"){
            if (q.empty()){
                cout << "-1\n";
            }
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (cmd == "size"){
            cout << q.size() << '\n';
        }
        else if (cmd == "empty"){
            if (q.empty()){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if (cmd == "front"){
            if (q.empty()){
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
            }
        }
        else if (cmd == "back"){
            if (q.empty()){
                cout << "-1\n";
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }
}