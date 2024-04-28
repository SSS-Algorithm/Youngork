#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, L; //입력받는다.
    cin >> N >> M >> L;

    vector<int> restAreas(N + 2);
    restAreas[0] = 0; 
    restAreas[N + 1] = L;

    for (int i = 1; i <= N; ++i) {
        cin >> restAreas[i];
    }
    sort(restAreas.begin(), restAreas.end());
    // 위치입력받고 정렬

    int left = 1, right = L;

    while (left <= right) {
 
        int mid = (left + right) / 2;
        int count = 0; //설치할 휴게소 개수

        for (int i = 1; i < restAreas.size(); ++i) {
            count += (restAreas[i] - restAreas[i - 1] - 1) / mid; //두 휴게소 사이에 지을 수 있는 갯수
        } 

        if (count > M) { //설치할 휴게소가 M개 보다 크다면 왼쪽을 범위를 줄
            left = mid + 1;
        } else { //설치할 휴게소가 M 개보다 적다면 오른쪽을 줄여서 mid 값을 낮추고 결과적으로 count를 올림
            right = mid - 1;
        }
    }

    cout << left;

    return 0;
}
