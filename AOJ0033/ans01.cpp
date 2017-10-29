#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;  // データセットの数
    while(n--){
        int balls[10] = {0};
        for(int i = 0; i < 10; i++) cin >> balls[i]; // 各データセットの入力

        bool isYES = true;  // 玉10個を振り分けられるかどうか
        int topB = 0, topC = 0;  // 筒B及び筒Cの最上部の玉の値
        for(int i = 0; i < 10; i++){
            if (topB < balls[i]){
                topB = balls[i];
            } else if (topC < balls[i]) {
                topC = balls[i];
            } else {
                isYES = false;
                break;
            }
        }
        cout << (isYES ? "YES" : "NO") << endl;
    }
}
