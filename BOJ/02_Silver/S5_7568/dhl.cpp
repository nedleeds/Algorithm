#include <iostream>
#include <vector>
using namespace std;

struct Info{ int w, h; } info;

int main(){
    freopen("input.txt", "r", stdin);

    int n, wght, hght;
    cin >> n;

    vector<Info> people(n);
    for (int i = 0; i < n; i ++){
        cin >> info.w >> info.h;
        people[i] = info;
    }  

    for (int r = 0; r < n; r++){
        int cnt = 1;
        for (int c = 0; c < n; c++ && (r!=c)){
            if (people[c].w > people[r].w && people[c].h > people[r].h){
                cnt++;
            }
        }
        cout << cnt << ' ';
    }
    cout << '\n';

    return 0;
}
/*
- 핵심 
: 등수는 자기보다 덩치큰 사람의 수 + 1 만큼이다.

- 부연 
: 브루트 포스는 N 크기를 보고 알았음
*/