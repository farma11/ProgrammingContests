#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

int main() {
    int n, balls[10]; cin >> n;
    while(n--){
        for(int i = 0; i < 10; i++) cin >> balls[i];

        enum {IDX, B, C};
        stack<tuple<int, int, int> > states;

        bool sortable = false;
        states.push(make_tuple(0,0,0));
        while(!states.empty()){
            tuple<int, int, int> now = states.top();
            states.pop();

            int idx = get<IDX>(now);
            if(idx < 10){
                if(get<B>(now) < balls[idx]){
                    if(idx == 9){
                        sortable = true; break;
                    }
                    states.push(make_tuple(idx+1,balls[idx],get<C>(now)));
                }
                if(get<C>(now) < balls[idx]){
                    if(idx == 9){
                        sortable = true; break;
                    }
                    states.push(make_tuple(idx+1,get<B>(now),balls[idx]));
                }
            }
        }
        cout << (sortable ? "YES" : "NO") << endl;
    }
}
