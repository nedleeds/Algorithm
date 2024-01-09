#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin); // 채점 시 주석처리
    deque<int> dq;

    int n, value;
    cin >> n;

    while(n--){
        string op;
        cin >> op;

        if (op == "push_back"){
            cin >> value;
            dq.push_back(value);
        }
        else if (op == "push_front"){
            int value;
            cin >> value;
            dq.push_front(value);
        }
        else if (op == "pop_front"){
            if (dq.empty()){
                cout << "-1\n";
            }
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (op == "pop_back"){
            if (dq.empty()){
                cout << "-1\n";
            }
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (op == "size"){
            cout << dq.size() << '\n';
        }
        else if (op == "empty"){
            if (dq.empty()){
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (op == "front"){
            if (dq.empty()){
                cout << "-1\n";
            }
            else{
                cout << dq.front() << '\n';
            }
        }
        else if (op == "back"){
            if (dq.empty()){
                cout << "-1\n";
            }
            else{
                cout << dq.back() << '\n';
            }
        }
    }

    return 0;
}