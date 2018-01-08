#include <iostream>
#include <algorithm>
using namespace std;

long n, h; 
int a, b, c, d, e; 

// 普通の食事の日数: x, 質素な食事の日数: y
inline bool isNotHunger(int x, int y){
    return h + b*x + d*y - e*(n - x - y) > 0;
}

int main(){
    cin >> n >> h;
    cin >> a >> b >> c >> d >> e;

    long cost = 1e10;
    for (int x = 0; x <= n; x++){
        for (int y = 0; y <= n - x; y++){
            if(isNotHunger(x, y)){
                cost = min(cost, long(a*x + c*y));
            }
        }
    }
    cout << cost << endl;
}
