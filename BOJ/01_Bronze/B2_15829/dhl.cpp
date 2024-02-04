#include <iostream>
#include <string>
using namespace std;

unsigned long long hash_function(string str){
    int m = 1234567891;
    int r = 31;
    unsigned long long s = 0;
    int a = 0;

    for (int i = 0; i < str.size(); i++){
        unsigned long long r_n = 1;
        for (int j = 1; j <= i; j++){
            r_n = r * (r_n % m);
            if (r_n > m){ r_n %= m; }
        }
        a = str[i] - 'a' + 1;
        s += a * r_n;
    }

    return s % m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n;
    string s;
    cin >> n >> s;

    cout << hash_function(s) << '\n';

    return 0;
}