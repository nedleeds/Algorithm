#include <iostream>
#include <queue>
using namespace std;

struct Answer{
    string value, cmds;
};
queue<Answer> Q;

string op_d(const string &a){
    int tmp = atoi(a.c_str());
    tmp = tmp > 9999 ? tmp % 10000 : tmp;
    return to_string(tmp);
}

string op_s(const string &a){
    int tmp = atoi(a.c_str());
    tmp = (tmp == 0) ? 9999 : tmp - 1;
    return to_string(tmp);
}

string op_l(const string &a){
    auto l = a.length();
    string a_new;
    for (int i = 1; i <= l; i++){
        a_new = (i < l) ? a_new + a[i] : a_new + a[0];
    }
    return a_new;
}

string op_r(const string &a){
    auto l = a.length();
    string a_new;
    a_new += a[l - 1];
    for (int i = 0; i < l - 1; i++){
        a_new += a[i];
    }

    return a_new;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int test_case;
    cin >> test_case;

    while(test_case--){
        string a, b;
        cin >> a >> b;
        
        Q.push({a, ""});
        queue<string> ans;
        while(!Q.empty()){
            Answer now = Q.front();
            Q.pop();

            if (now.value == b){
                ans.push(now.cmds);
                cout << now.cmds << '\n';
                continue;
            }

            while(ans.size() == 0){
                Q.push({op_d(now.value), now.cmds + "D"});
                Q.push({op_s(now.value), now.cmds + "S"});
                Q.push({op_l(now.value), now.cmds + "L"});
                Q.push({op_r(now.value), now.cmds + "R"});
            }
        }
    }

    return 0;
}