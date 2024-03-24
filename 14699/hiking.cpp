#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct shelter {
    int altitude; // 높이
    int answer; // 최대 몇개 갈 수 있는 지
    vector<int> near; // 연결된 쉼터 목록
};
int main(void){ //dp

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_shelter;
    int n_road;

    cin >> n_shelter;
    cin >> n_road;

    vector<shelter> shelters;

    vector<int> height;
    vector<int> order;

    for(int i = 0 ; i < n_shelter ; i++){
        shelter S = {0};
        S.answer = 1;
        cin >> S.altitude;
        height.push_back(S.altitude);
        shelters.push_back(S);
    } 
    // 쉼터마다 높이 저장

    for(int j = 0; j < n_road ; j++){
        int a, b;
        cin >> a >> b;
        shelters[a-1].near.push_back(b-1);
        shelters[b-1].near.push_back(a-1);
    } 
    // 길 저장 -> 쉼터마다 연결된 쉼터 저장

    sort(height.rbegin(), height.rend());

    for(int i=0; i < height.size(); i++  ){
        for(int j = 0; j < shelters.size() ; j++ ){
            if(height[i] == shelters[j].altitude){
                order.push_back(j);
            } 
        }
    }

    for(int i = 0; i < shelters.size() ; i ++){
        int n = order[i];
        int biggest_answer = 0;

        for(int j = 0 ; j < shelters[n].near.size(); j ++){ //  주변 노드들 하나 씩 검사
            if(shelters[n].altitude < shelters[shelters[n].near[j]].altitude){ // 내 높이 보다 높으면
                if(biggest_answer < shelters[shelters[n].near[j]].answer){
                    biggest_answer = shelters[shelters[n].near[j]].answer;
                    shelters[n].answer = biggest_answer +1;
                }
            } // 높은게 있으면 그 높은 것들 중에 답이 제일 큰 것 +1
        }
    }
    
    for(int i = 0 ; i < n_shelter; i++){
        cout <<  shelters[i].answer ;
        if(i != n_shelter -1){
            cout << "\n";
        }
    }
    return 0;
}