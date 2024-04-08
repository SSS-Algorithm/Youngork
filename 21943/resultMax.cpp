#include <iostream>
#include <vector>
using namespace std;

static int max_result = 0;

void search_max(vector<int> cal,int plus){
   if(plus == 0){
        int result = 1;
        while(!cal.empty()){
            int num = cal.front();
            cal.erase(cal.begin());
            result = result * num;
        }
        if(result > max_result){
            max_result = result;
        }
        return ;
   }else{
        for(int j=0; j< cal.size()-1 ; j++ ){
            for(int i=0 ; i < cal.size()-(j+1) ; i++ ){
                //벡터 변경해서 보내줌
                vector<int> copy_cal(cal);
                int plus_num = copy_cal[i] + copy_cal[i+j+1];

                copy_cal.erase(copy_cal.begin()+i);
                copy_cal.erase(copy_cal.begin()+i+j);
                copy_cal.insert(copy_cal.begin()+i,plus_num);
                search_max(copy_cal,plus-1);
            }
        }
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 정수 개수
    int plus; // 더하기 개수
    int multiply; // 곱하기 개수

    vector<int> cal; // 정수들

    cin >> N;

    for(int i =0 ; i < N ; i++){
        int k;
        cin >> k;
        cal.push_back(k);
    }

    cin >> plus;
    cin >> multiply;

    int sum =0;
    if(multiply == 0){
        for(int i : cal){ sum = sum + i; }
        max_result = sum;
    }
    else{
        search_max(cal,plus);
    }

    cout << max_result;
    return 0;
}
