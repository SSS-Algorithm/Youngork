#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compareChar(const pair<char, int>& a, const pair<char, int>& b) {
    return a.first < b.first;
}

vector<bool> visited;
vector< pair<char, int> > answer;

void lexicographical_Order(int a, string str) {
    int index = answer[a].second;

    vector< pair<char, int> > sample;
    for (int i = index+1 ; i < visited.size(); i++) {
        if (!visited[i]) {
            sample.push_back(make_pair(str[i], i));
        }
    }
    if (sample.size() == 0) {
        if (a - 1 > -1) {
            lexicographical_Order(a - 1, str);
        }
        return;
    } else {
        sort(sample.begin(), sample.end(), compareChar);
        answer.insert(answer.begin() + a + 1, sample.front());
        visited[sample.front().second] = true;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    visited.resize(str.length(), false);
    answer.push_back(make_pair('*', -1)); // 시작 인덱스는 -1로 초기화

    for (int i = 0; i < str.length(); i++) {
        lexicographical_Order(answer.size() - 1, str);
        for (int j = 1; j < answer.size(); j++) {
            cout << answer[j].first;
        }
        cout << '\n';
    }
    return 0;
}
