#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    vector<int> prorequisites; // 다음과목
    int inDegree; // 진입차수
    int semester; // 몇 학기 들어야하는 지
};

void topologicalSort(vector<Node>& subjects){ //위상정렬
    queue<int> topological; // 노드 인덱스

    for(int i = 0; i< subjects.size(); i++){
        if(subjects[i].inDegree == 0){
            topological.push(i);
        }
    }
    while(!topological.empty()){
        int start = topological.front();
        topological.pop();

        for(int i = 0; i < subjects[start].prorequisites.size(); i++){
            int next = subjects[start].prorequisites[i];
            subjects[next].inDegree--;
            subjects[next].semester = subjects[start].semester +1;

            if(subjects[next].inDegree == 0){
                topological.push(next);
            }
        }
    }
    return ;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<Node> Subjects(N);

    for(int i=0; i< N; i++){ //초기화
        Subjects[i].semester =1; 
        Subjects[i].inDegree =0;
    }
    for(int i=0; i< M; i++){
        int a, b;
        cin >> a >> b;
        Subjects[a-1].prorequisites.push_back(b-1); // 인덱스 맞춰줌
        Subjects[b-1].inDegree++; // 진입차수 하나 추가
    }

    topologicalSort(Subjects);

    for(int i=0; i< N; i++){
        cout << Subjects[i].semester;
        if(i!=N-1){
            cout << " ";
        }
    }

    return 0;
}