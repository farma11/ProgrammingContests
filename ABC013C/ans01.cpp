#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long int

LL n, h; 
LL a, b, c, d, e; 

// 質素な食事の最低限の回数が求められる
inline LL minCheapFood(double x){
    return ((n - x)*e - h - b*x) / (d + e) + 1;
}

int main(){
    cin >> n >> h;
    cin >> a >> b >> c >> d >> e;

    LL cost = 1e14;
    for (LL x = 0; x <= n; x++){
        LL y = max(0LL, minCheapFood(x));
        if (x + y <= n){
            cost = min(cost, (LL)(a*x + c*y));
        }
    }
    cout << cost << endl;
}