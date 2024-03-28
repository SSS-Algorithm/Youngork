#include <iostream>
#include <deque>
using namespace std;
struct Position{
    int time;
    int row;
    int col;
    Position(int a, int b, int c) : time(a), row(b), col(c) {}
};
bool SC = false;
char Maze[8][9][9]; // [시간][행][열]
deque<Position> possible;

void ExitMaze(void){

    Position pos = possible.front();
    possible.pop_front();

    int time = pos.time;
    int row = pos.row;
    int col = pos.col;

    int mv_row;
    int mv_col; 
    
    if(time==7){
        while(possible.empty()){
            possible.pop_front(); // 다 없애자
        }
        SC = true;
        return ;
    }
      
    //오대위
    if(col != 7){
        mv_row = row -1; mv_col = col +1;
        if(mv_row == 0){ 
            while(possible.empty()){
                possible.pop_front(); // 다 없애자
            }
            SC = true;
            return ;
        }
        if(Maze[time+1][mv_row][mv_col] != '#' && Maze[time][mv_row][mv_col] != '#'){ 
            possible.push_front(Position(time+1,mv_row,mv_col));
        }// 현재 위치랑 그 위가 벽이 아니면
    } 

    //왼대위
    if(col != 0){
        mv_row = row -1; mv_col = col -1;
        if(mv_row == 0){ 
            while(possible.empty()){
                possible.pop_front(); // 다 없애자
            }
            SC = true;
            return ;
        }
        if(Maze[time+1][mv_row][mv_col] != '#' && Maze[time][mv_row][mv_col] != '#'){ 
            possible.push_front(Position(time+1,mv_row,mv_col));
        }// 현재 위치랑 그 위가 벽이 아니면
    } 

    //위
    if(row != 0){
        mv_row = row-1; mv_col = col;
        if(mv_row == 0){ // 이러면 성공
            while(possible.empty()){
                possible.pop_front(); // 다 없애자
            }
            SC = true;
            return ;
        }
        if(Maze[time+1][mv_row][mv_col] != '#' && Maze[time][mv_row][mv_col] != '#'){ 
            possible.push_front(Position(time+1,mv_row,mv_col));
        }// 현재 위치랑 그 위가 벽이 아니면
    }

    //오른쪽
    if(col != 7){
        mv_row = row; mv_col = col+1;
        if(Maze[time+1][mv_row][mv_col] != '#' && Maze[time][mv_row][mv_col] != '#'){ 
            possible.push_front(Position(time+1,mv_row,mv_col));
        }
    }

    //왼쪽
    if(col != 0){
        mv_row = row; mv_col = col-1;
        if(Maze[time+1][mv_row][mv_col] != '#' && Maze[time][mv_row][mv_col] != '#'){ 
            possible.push_front(Position(time+1,mv_row,mv_col));
        }
    }

    //정지
    mv_row = row; mv_col = col;
    if(Maze[time+1][mv_row][mv_col] != '#' && Maze[time][mv_row][mv_col] != '#'){ 
        possible.push_front(Position(time+1,mv_row,mv_col));
    }   

    //오른쪽아래
    if(col != 7 && row != 7){
        mv_row = row+1; mv_col = col+1;
        if(Maze[time+1][mv_row][mv_col] != '#' && Maze[time][mv_row][mv_col] != '#'){ 
            possible.push_front(Position(time+1,mv_row,mv_col));
        }
    }

    //왼쪽 아래
    if(col != 0 && row != 7){
        mv_row = row+1; mv_col = col-1;
        if(Maze[time+1][mv_row][mv_col] != '#' && Maze[time+1][mv_row][mv_col] != '#'){ 
            possible.push_front(Position(time+1,mv_row,mv_col));
        }
    }
}




int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0 ; i < 8 ; i++){
        cin >> Maze[0][i];
    } //이러면 계행도 넣어버려서 9x9 로 만듬

    for(int k = 0 ; k < 7 ; k++){
        for(int i = 0 ; i < 8 ; i++){ // 벽움지기기 
            for(int j =0 ; j < 8 ; j++){
                Maze[k+1][i+1][j] =  Maze[k][i][j];
            }
            if(i==0){
                for(int j =0 ; j < 8 ; j++){
                    Maze[k+1][0][j] =  '.';
                }
            }
        }
    } //시간에 따라서 다 저장

    Position start = Position(0,7,0);
    possible.push_front(start);
    
    while(!possible.empty()){
        ExitMaze();
    }
    if(SC){
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}