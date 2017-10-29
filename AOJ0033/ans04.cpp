#include <iostream>
using namespace std;

int main() {
    int n, balls[10]; cin >> n;
    while(n--){
        for(int i = 0; i < 10; i++) cin >> balls[i];

        bool sortable = false;
        for(int i = 0; i < (1 << 10); i++){
            int bit = i;
            bool ok = true;

            int top[2] = {0,0}; //top[0]: B, top[1]: C
            for(int j = 0; j < 10; j++){
                if(top[bit & 1] > balls[j]){
                    ok = false; break;
                }
                top[bit & 1] = balls[j];
                bit >>= 1;
            }

            if(ok) {
                sortable = true; break;
            }
        }
        cout << (sortable ? "YES" : "NO") << endl;
    }
}
