#include <iostream>
#include <set>
using namespace std;

auto get_max(const multiset<int>& ms){
    auto rit = ms.rbegin();
    auto it = rit.base();
    return --it;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int test_case;
    cin >> test_case;
    while(test_case--){
        int k;
        cin >> k;
        multiset<int> ms;
        while(k--){
            char op;
            int n;
            cin >> op >> n;
            if (op == 'I'){
                ms.insert(n);
            }
            else if (op == 'D'){
                if (n == 1){
                    if (!ms.empty()){
                        ms.erase(get_max(ms));
                    }
                }
                else if (n == -1){
                    if (!ms.empty()){
                        ms.erase(ms.begin());
                    }
                }
            }

        }
        if (ms.empty()){
            cout << "EMPTY\n";
        }
        else{
            auto max_it = get_max(ms);
            int max = *max_it;
            int min = *ms.begin();
            cout << max << ' ' << min << '\n';
        }
    }
}