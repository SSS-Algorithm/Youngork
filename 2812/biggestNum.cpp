#include <iostream>
#include <string>
using namespace std;
/*
    자릿수가 큰 숫자가 큰 숫자인 경우가 가장 크다.
    따라서 origin 배열에서 한칸씩 검사해서 뒤에 자리가 있는 경우에서
    가장 큰 숫자를 골라서 답 배열에 넣어준다.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ori_count; // 원래 자릿수
    int cut_count; // 자를려는 숫자수
    cin >> ori_count >> cut_count;

    int ans_count = ori_count - cut_count; // 답 자릿수

    string origin;
    cin >> origin; 

    string answer;

    int pos = 0; // origin 배열 이동할 index

    for (int i = 0; i < ans_count; i++) { // i는 정답 배열의 인덱스
        if ((ori_count - pos) == (ans_count - i)) { 
            answer.push_back(origin[pos]);
            pos++; 
        }  // origin에서 검사할 자리와 answer의 남은 자리가 같을 경우 
        else if ((ori_count - pos) > (ans_count - i)) { 
            int target = 9; // 자리가 남았으니깐 9부터 있는지 확인
            if (target == 0 && i == 0){
                pos++;
                i--;
            } // 맨 처음 들어가는 숫자가 0이 아니여야한다.
            else {
                bool SC = false;
                while (!SC && !(target < 0)) {
                    for (int j = pos; j < origin.length(); j++) { // 큰 숫자를 찾기위해 
                        if ((origin[j] - '0') == target && (ori_count - j) >= ans_count - i) {
                            answer.push_back(origin[j]);
                            pos = j+1; // 다음 인덱스로
                            SC = true; // 2중반복문을 한번에 빠져나오기위해
                            break;
                        }
                    } 
                    target--;
                }
            }
        } else if ((ori_count - pos) < ans_count - i) {
            cout << "\nerror!";
        } else{
            cout << "\nwhy hear";
        } // 오류 처리
    }
    cout << answer;
    return 0;
}
