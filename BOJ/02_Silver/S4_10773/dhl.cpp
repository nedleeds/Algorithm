#include <iostream>
#include <vector>
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    
    int k; 
    cin >> k;

    vector<int> v;
    for (int i = 0; i < k; i++){
        int x;
        cin >> x;

        if (x == 0){
            v.pop_back();
        }
        else{
            v.push_back(x);
        }
    }

    int s = 0;
    for (auto j : v){
        s += j;
    }
    cout << s << '\n';

    return 0;
}