#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long int 
enum{ MON, HUNG };
LL n, h; 
LL a, b, c, d, e; 

// 普通の食事の日数: x, 質素な食事の日数: y
inline bool isNotHunger(LL x, LL y){
    return h + b*x + d*y - e*(n - x - y) > 0;
}

int main(){
	cin >> n >> h;
	cin >> a >> b >> c >> d >> e;
	LL cost = 1e14;

	LL x = 0, y = 0; // 普通の食事の日数: x, 質素な食事の日数: y

	// 普通の食事だけの場合、必要となる回数を求める
	while (n > x && !isNotHunger(x, 0)) x++;

	while (1){
		//条件を満たすなら最低値を更新
		if (isNotHunger(x, y)) cost = min(cost, a*x + c*y);
		else break;

		//条件を満たさなくなるまでxを減らす(減らせないなら終了)
		if (x == 0) break;
		while (isNotHunger(x, y)) x--;

		//条件を満たすまでyを増やす(増やせないなら終了)
		if (x + y == n) break;
		while (!isNotHunger(x, y)) y++;
	}
	cout << cost << endl;
}