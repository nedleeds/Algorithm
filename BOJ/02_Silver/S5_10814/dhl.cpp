#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
struct Student {
    int id;
    int age;
    string name;
};
vector<Student> V;

// cpp vector sorting method
bool compare(Student a, Student b){
    if (a.age < b.age) {return true;}
    if (a.age == b.age) { 
        if (a.id < b.id) { return true;}
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    Student s;

    V = vector<Student>(N);
    for (int i = 0; i < N; i++)
    {
        s.id = i;
        cin >> s.age >> s.name;
        V[i] = s;
    }

    sort(V.begin(), V.end(), compare);

    for (auto s: V){
        cout << s.age << " " << s.name << "\n";
    }

    return 0;
}