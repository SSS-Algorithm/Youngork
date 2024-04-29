#include <iostream>
#include <vector>
using namespace std;

struct PBs {
    int x;
    int y;
    vector<int> possibleNum = {1,2,3,4,5,6,7,8,9};
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sudoku[9][9];
    vector<PBs> problems;
    
    for(int i = 0; i< 9 ; i++){
        for(int j = 0; j< 9 ; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0){
                PBs p;
                p.x = i;
                p.y = j;
                problems.push_back(p);
            }
        }
    }

    int n = 0; // n은 problems 에 있는 점들을 순환할 것이다.
    while(problems.size() > 0) {
        for(int i = 0; i< 9 ; i++){
            for(int j =0; j < problems[n].possibleNum.size(); j++){
                if(sudoku[problems[n].x][i] == problems[n].possibleNum[j]){
                    problems[n].possibleNum.erase(problems[n].possibleNum.begin() + j);
                    j--;
                    break;
                }
            }
        } // 가로 하나 보고 그거랑 같은지 possible 을 돌려봄 맞으면 하나 빼고 다음 가로로 넘어감

        if(problems[n].possibleNum.size() == 1){
            sudoku[problems[n].x][problems[n].y] = problems[n].possibleNum.front();
            problems.erase(problems.begin() + n);
            continue;
        } // 하나남았으면 넣음

        for(int i = 0; i< 9 ; i++){
            for(int j =0; j < problems[n].possibleNum.size(); j++){
                if(sudoku[i][problems[n].y] == problems[n].possibleNum[j]){
                    problems[n].possibleNum.erase(problems[n].possibleNum.begin() + j);
                    j--;
                    break;
                }
            }
        } // 세로 하나 보고 그거랑 같은지 possible 을 돌려봄 맞으면 하나 빼고 다음 가로로 넘어감

        if(problems[n].possibleNum.size() == 1){
            sudoku[problems[n].x][problems[n].y] = problems[n].possibleNum.front();
            problems.erase(problems.begin() + n);
            continue;
        } // 하나남았으면 넣음

        // 3x3 배열 신경써야될 곳
        int X = problems[n].x/3 * 3;
        int Y = problems[n].y/3 * 3;

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<problems[n].possibleNum.size(); k++){
                    if(problems[n].possibleNum.size()==1)
                        break;
                    else if(sudoku[X+i][Y+j] == problems[n].possibleNum[k]){
                        problems[n].possibleNum.erase(problems[n].possibleNum.begin() + j);
                        k--;
                        break;
                    }
                }
            }
        }
        if(problems[n].possibleNum.size() == 1){
            sudoku[problems[n].x][problems[n].y] = problems[n].possibleNum.front();
            problems.erase(problems.begin() + n);
            continue;
        } // 하나남았으면 넣음
        n++;
    }

    for(int i = 0; i< 9 ; i++){
        for(int j = 0; j< 9 ; j++){
            cout << sudoku[i][j];
            if(j != 9)
                cout << ' ';
        }
        if(i != 9)
            cout << '\n';
    }

    return 0;
}