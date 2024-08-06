#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Step {
  string value, cmd;
};
vector<string> Ans;

string op_d(const string &a) {
  int tmp = atoi(a.c_str()) * 2;
  tmp = tmp > 9999 ? tmp % 10000 : tmp;
  return to_string(tmp);
}

string op_s(const string &a) {
  int tmp = atoi(a.c_str());
  tmp = (tmp == 0) ? 9999 : tmp - 1;
  return to_string(tmp);
}

string op_l(const string &a) {
  auto l = a.length();
  string a_new;
  for (int i = 1; i <= l; i++) {
    a_new = (i < l) ? a_new + a[i] : a_new + a[0];
  }
  return a_new;
}

string op_r(const string &a) {
  auto l = a.length();
  string a_new;
  a_new += a[l - 1];
  for (int i = 0; i < l - 1; i++) {
    a_new += a[i];
  }

  return a_new;
}

void bfs(string src, string tgt) {
  queue<Step> q;
  q.push({src, ""});

  while (!q.empty()) {
    bool stop = false;
    Step now_s = q.front();
    q.pop();

    if (now_s.value == tgt) {
      Ans.push_back(now_s.cmd);
      stop = true;
    }

    q.push({op_d(now_s.value), now_s.cmd + "D"});
    q.push({op_s(now_s.value), now_s.cmd + "S"});
    q.push({op_l(now_s.value), now_s.cmd + "L"});
    q.push({op_r(now_s.value), now_s.cmd + "R"});

    if (stop) {
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  int test_case;
  cin >> test_case;

  while (test_case--) {
    string a, b;
    cin >> a >> b;

    bfs(a, b);

    for (auto a : Ans) {
      cout << a << '\n';
    }
    Ans.clear();
  }

  return 0;
}
