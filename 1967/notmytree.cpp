#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> near[10001]; // 인접한 노드의 정보 <노드 번호, 해당 노드까지 거리>
vector<int> child_distance_vec[10001]; //한 정점에서 연결된 자식들부터 시작해서 뻗어나갈 수 있는 거리를 저장해두는 벡터. 입력받은 후 정렬시킨 뒤에 사용한다.
int ans; // 트리의 지름

int dfs(int nodeNum) {
	for (pair<int, int> p : near[nodeNum]) { // p로써 near[nodeNum] 을 돈다.
		int next_num = p.first;
		int next_distance = p.second;
		
		int c_distance = next_distance + dfs(next_num); 
		child_distance_vec[nodeNum].push_back(c_distance); 
	}

	sort(child_distance_vec[nodeNum].begin(), child_distance_vec[nodeNum].end()); // 정렬

	if (child_distance_vec[nodeNum].empty()) {
		return 0;
	} // 자식이 없으면 끝
	else if (child_distance_vec[nodeNum].size() == 1) {
		int bigIdx = child_distance_vec[nodeNum].size() - 1;
		ans = max(ans, child_distance_vec[nodeNum][bigIdx]); //
		return child_distance_vec[nodeNum][bigIdx];
	} //자식이 하나라면 답이랑 하나랑 비교해서 그냥 올린다.
	else {
		int firstBig = child_distance_vec[nodeNum].size() - 1;
		int secondBig = child_distance_vec[nodeNum].size() - 2;
		ans = max(ans, child_distance_vec[nodeNum][firstBig] + child_distance_vec[nodeNum][secondBig]); // 자식
		return child_distance_vec[nodeNum][firstBig];
	} // 자식이 하나가 아니라면 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node_num; // 노드의 개수
	cin >> node_num;

	int parNode, childNode, distance;
	for (int i = 1; i < node_num; i++){
		cin >> parNode >> childNode >> distance; // 부모 , 자식, 거리 를 입력
		near[parNode].push_back({ childNode, distance }); // 부모 노드에 자식 노드, 거리를 입력
	}

	dfs(1); // 가장 긴 거리 찾기

	cout << ans;

	return 0;
}