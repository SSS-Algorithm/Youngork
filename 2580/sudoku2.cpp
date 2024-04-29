#include <iostream>
using namespace std;

const int N = 9;

bool isValid(int sudoku[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (sudoku[row][x] == num) {
            return false;
        }
    }// 가로에 중복된 숫자가 있는지 확인
    
    for (int y = 0; y < N; y++) {
        if (sudoku[y][col] == num) {
            return false;
        }
    }// 세로에 중복된 숫자가 있는지 확인
    
    // 3x3 박스에 중복된 숫자가 있는지 확인
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// 스도쿠 퍼즐을 해결하는 함수
bool solveSudoku(int sudoku[N][N]) {
    int row, col;
    bool isEmpty = true;
    
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (sudoku[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    } // 0인 걸 하나 찾는다.
    
    if (isEmpty) {
        return true;
    } // 0인게 없으면 해결
    
    for (int num = 1; num <= 9; num++) {
        if (isValid(sudoku, row, col, num)) { //숫자가 유효하면
            sudoku[row][col] = num; //숫자를 넣고
            if (solveSudoku(sudoku)) { // 확인한다
                return true;
            } 
            sudoku[row][col] = 0; // 해결 실패시 다시 0으로 되돌림
        }
    }
    // 해결이 안된 경우
    return false;
}

void printSudoku(int sudoku[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << sudoku[row][col] << " ";
        }
        cout << endl;
    }
} //출력

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sudoku[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sudoku[i][j];
        }
    }// 스도쿠 퍼즐 입력 받음
    
    if (solveSudoku(sudoku)) {
        printSudoku(sudoku);
    } else {
        cout << "No solution exists";
    }
    
    return 0;
}
