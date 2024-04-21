#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ // 이분 탐색
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, more, length;
    cin >> num >> more >> length;

    vector<int> apart;
    int max1 = 0, max2 =0;

    if(num == 0){
        max1 = (length+more)/(more+1);
        cout << max1;
        return 0;
    }
    int k;
    int *distance = new int[num+2];
    distance[0] = 0;
    distance[num+1] = length;

    for(int i=1; i<num+1 ; i++){
        cin >> k;
        distance[i]=k;
    } // 다담아
    sort(distance,distance+num+2);

    int st=0, en;
    for(int i = 0 ; i < num+1 ; i++){
        apart.push_back(distance[i+1]-distance[i]);
    } // 차이 배열 만들기
    delete []distance;
    int mor = more;
    
//////////////////////////////////////////////////////////////////////////////////////////////
    for(int repeat = 0 ; repeat < mor ; repeat++ ){
        for(int i=0; i< apart.size() ; i++){ // 젤 큰 값이랑 두번째로 큰 값 찾기
            if(apart[i] >= max1){
                max1 = apart[i];
            }
            else if(apart[i] > max2){
                max2 = apart[i];
            }
        }
        cout <<"\n max1 = " << max1 << " max2 = " << max2;

        if((max1+more)/(more+1)>max2){
            max1 = (max1+more)/(more+1);
            cout << "\n나간다.\n";
            break;
        }

        else{ // 인덱스가 필요가 없네?
            for(int i=0; i< apart.size() ; i++){ 
                if(apart[i] == max1){
                    apart.erase(apart.begin() + i);
                    apart.push_back(max1/2);
                    apart.push_back((max1+1)/2);
                    more--;
                    break;
                }
            }
        }
        cout<< "\n";
        for(int i =0; i< apart.size() ; i++){
            cout << " " << apart[i];
        }
        cout << "\n";
        max1 = 0;
        max2 = 0;
        for(int i=0; i< apart.size() ; i++){
            if(apart[i] >= max1){
                max1 = apart[i];
            }
            else if(apart[i] > max2){
                max2 = apart[i];
            }
        }
    }
    cout << max1;

    return 0;
}
