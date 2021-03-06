#include <iostream>
#include <algorithm>
using namespace std;

enum {
    B10 = 10000, B5 = 5000, B1 = 1000
};

inline bool isCorrect(int x10, int x5, int x1, int n, long y){
    bool isPositive = ((x10 >= 0) && (x5 >= 0) && (x1 >=0));
    bool isCorrectN = (n == x10 + x5 + x1);
    bool isCorrectY = (y - B10*x10 - B5*x5 - B1*x1 == 0);

    return isPositive && isCorrectN && isCorrectY;
}

// O(n)
void fastAns(int& x10, int& x5, int& x1, int n, long y){
    x10 = min(n, int(y / B10));
    for(; x10 >= 0; x10--){
        int det = B1 - B5; // -4000
        x5 = ( (n - x10)*B1 - (y - B10*x10)) / det;
        x1 = (-(n - x10)*B5 + (y - B10*x10)) / det;
        if(isCorrect(x10, x5, x1, n, y)) return;
    }
}

int main(){
    int  n; cin >> n;
    long y; cin >> y;

    int x10 = -1, x5 = -1, x1 = -1;
    fastAns(x10, x5, x1, n, y);

    if(isCorrect(x10, x5, x1, n, y)){
        cout << x10 << " " << x5 << " " << x1 << endl; 
    } else {
        cout << "-1 -1 -1" << endl;
    }
}
