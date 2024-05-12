#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{
    int one;
    int two;
    int weight;
};
vector<int> root;

int find(int v) {
    if (root[v] == v)
        return v;
    return find(root[v]);
}
void united(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    root[xset] = yset;
}

bool compareEdge(const edge& a, const edge& b){
    return a.weight < b.weight;
}

int Kruskal(int n, vector<edge>& R){
    int total=0;

    root.clear();
    for(int i =0; i<n; i++){
        root.push_back(i);
    }
    sort(R.begin(), R.end(), compareEdge);

    for(int i=0; i < R.size(); i++){
        if(find(R[i].one) != find(R[i].two)){
            united(R[i].one,R[i].two);
            total = total + R[i].weight;
        }
    }
    return total;
}

int main(void){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    int a,b,c; // 임시변수
    char d; // 임시변수
    int loveroad; // 사심경로 가중치 = 정답

    vector<bool> university; // 0:남자, 1:여자
    vector<edge> road;
    cin >> N;
    cin >> M;
    
    for(int i=0; i< N; i++){
        cin >> d;
        if(d=='M')
            university.push_back(false);
        if(d=='W')
            university.push_back(true);
    } // 대학교 남초 여초 입력
    for(int i=0; i< M; i++){
        cin >> a >> b >> c;
        if(university[a-1] != university[b-1]){
            int one = a>b ? b-1 : a-1;
            int two = a>b ? a-1 : b-1;
            int weight = c;
            for(int i=0; i<road.size() ; i++){
                if(one==road[i].one && two==road[i].two){
                    if(c > road[i].weight){
                        weight = road[i].weight;
                    }
                    road.erase(road.begin() + i);
                }
            }
            edge temp = {one,two,weight};
            road.push_back(temp); //인덱스로 저장
        }
    } // 여자 남자 이어질 수 있는 곳만 골라서 데이터 넣기
    loveroad = Kruskal(N,road);
    for(int i =0; i< N; i++){
        if(find(root[i]) != find(0))
            loveroad =-1;
    }

    cout << loveroad;

    return 0;
}
