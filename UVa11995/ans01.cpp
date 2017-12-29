#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <array>
#include <functional>
#include <vector>
using namespace std;

string table[5] = { "stack", "queue", "priority queue", "impossible", "not sure" };
array<bool, 3> possible = { true, true, true }; // stack,queue,priority queueの可能性

/* 各データ構造に対して、データの挿入（Throw）・参照・削除（TakeOut）を行う */
//可能性の残っているデータ構造にデータを格納
inline void Throw(int data, stack<int>& s, queue<int>& q, priority_queue<int> & pq){
	if (possible[0]) s.push(data);
	if (possible[1]) q.push(data);
	if (possible[2]) pq.push(data);
}
//可能性が残っているデータ構造からデータを取得
inline bool TakeOut(int data, stack<int>& s, queue<int>& q, priority_queue<int> & pq){
	if (possible[0]){
		if (!s.empty()){
			int output = s.top(); s.pop();
			if (data != output) possible[0] = false;
		}
		else return true; //取り出せないなら"impossible"
	}
	if (possible[1]){
		if (!q.empty()){
			int output = q.front(); q.pop();
			if (data != output) possible[1] = false;
		}
		else return true; //取り出せないなら"impossible"
	}
	if (possible[2]){
		if (!pq.empty()){
			int output = pq.top(); pq.pop();
			if (data != output) possible[2] = false;
		}
		else return true; //取り出せないなら"impossible"
	}
	return false; //取り出せたならfalse
}

/* 各データ構造の判定を行う関数 */
//他のデータ構造の該当添え字を計算
inline int calIndex(int index, int plus){
	return (index + plus) % 3;
}
//各データ構造について確認
inline bool if_judge(int index){
	if (possible[index]){
		if (!possible[calIndex(index, 1)] && !possible[calIndex(index, 2)]){
			cout << table[index] << endl;
			return true; //データ構造が確定
		}
		cout << table[4] << endl;
    return true; //複数の可能性がある
	}
	return false; //可能性がない
}
//データ構造の特定と出力
inline void judge(bool flag){
	if (!flag){
		for (int k = 0; k < 3; k++){
			if (if_judge(k)) return;
		}
	}
	cout << table[3] << endl; //特定不能(impossible)
	return;
}

int main(){
	int n;
	while (cin >> n){
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool flag = false; //確実に出し入れできないときtrue
		while (n--){
			int com, data; cin >> com >> data;
			//コマンドに対応した処理
			switch (com){
			case 1: Throw(data, s, q, pq);  break;
			case 2: flag = TakeOut(data, s, q, pq); break;
			}
		}
		judge(flag);
		possible.fill(true); //各データ構造の可能性初期化
	}
}
