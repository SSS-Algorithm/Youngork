/*
파일의 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)이다. 
둘째 줄부터 n-1개의 줄에 각 간선에 대한 정보가 들어온다. 
간선에 대한 정보는 세 개의 정수로 이루어져 있다. 
첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고,
두 번째 정수는 자식 노드를, 
세 번째 정수는 간선의 가중치를 나타낸다. 
간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고, 
부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 
루트 노드의 번호는 항상 1이라고 가정하며, 
간선의 가중치는 100보다 크지 않은 양의 정수이다.
*/
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int number; // 번호
    node* parent; // 부모
    vector<node> child; //자식
    int weight; //부모와의 가중치
}; //노드 정보

void Add_child(node* p, int c, int w){
    node child;
    child.number = c;
    child.parent = p;
    child.weight = w;
    (*p).child.push_back(child);
} // 자식 추가

int main(void){
    int num; // 노드의 개수
    node root;
    root.number = 1; root.weight = 0; root.parent = &root;
    node* now = &root;

    std::cin >> num;
    
    // 벡터 인덱스 0 부터시작 , 그리고 size 가 원소의 개수 
    // 그래서 0부터해서 1칸씩가다가 size 만큼 반복하던지 아니면 한칸씩가면 될거같음
    for(int i = 0; i < num; i++ ){
        int p_num;
        int child_num;
        int weight;
        std::cin >> p_num >> child_num >> weight;
        // 1번 넣고 p_num 이 지금이랑 다르면 child num 다 보고 그거랑도 다르면 번호 1씩 증가시켜가면서 봄
        if((*now).number == p_num){
            Add_child(now,child_num,weight);
        }
        else{
            for(int j = 0 ; j < (*now).child.size(); j++){
                if((*now).child[j].number == p_num){
                    now = &(*now).child[j];
                    Add_child(now,child_num,weight);
                    break;
                } 
            }
        }
    }
    



    // 새로운 노드를 받아준다.
    // 그리고 그거에 대한 정보를 전달해준다.
    // 부모의 대한정보도 전달시켜줘야된다.
    // 첫번쨰는 부모, 두번째는 자기자신에 대한 정보
    // 마지막은 가중치
    // 문제는 번호로 어떻게 노드를 식별하냐는 것인데
    // 이진탐색도 아니라서 반복문으로 짜기는 좀 그렇고
    // if 문으로 더 크면 위로갔다 오른쪽 아래로 이제 아래가 아니라 오른쪽으로 가야될 것같다.
    // 그래서 위아래로 움직이려면 자식노드의 주소도 알아야 하는데
    // 자식이 여러개 올 수 있으니, 이걸 어떻게 해결해야 할까?
    // 예전에는 left right 로 했던거같은데, 여러개 노드로 갈 때 어떻게 가야할까
    // 동적으로 추가할 수 있는 것들 -> list, vector
    


    return 0;
}