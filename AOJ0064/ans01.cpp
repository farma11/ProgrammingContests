#include <iostream>
using namespace std;

char mp[12][13];  // 12x12の平面図 (mp[][12]は'\0'用)

// 4方位探索用
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
void dfs(int x, int y){
    mp[x][y] = '0';  // 探索済みの部分を '0' に置き換える
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (mp[nx][ny] == '1') dfs(nx, ny);
    }
}

int main() {
    // 平面図の1行目の入力がある限りループをまわす
    while (cin >> mp[0]){
        // 平面図の残り2行目～12行目の入力
        for (int i = 1; i < 12; i++){
            cin >> mp[i];
        }

        int islands = 0; // 島の個数を保持
        // 平面図を(0,0)から順に探索
        for (int x = 0; x < 12; x++){
            for (int y = 0; y < 12; y++){
                // 島を発見したら
                if (mp[x][y] == '1'){
                    islands++;
                    dfs(x, y);
                }
            }
        }
        cout << islands << endl;
    }
}
