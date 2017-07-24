#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t, n, q, flag, x, y, loser, winner;
    int s[10005] = {0};
    int chef[10005];
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        priority_queue<int>dish[n];
        for (int j = 0; j < n; j++) {
            chef[j] = j;
            cin >> s[j];
            dish[j].push(j);
        }
        cin >> q;
        for (int j = 0; j < q; j++) {
            cin >> flag;
            if (flag == 0) {
                cin >> x;
                cin >> y;
                x--;
                y--;
                if (chef[x]==chef[y]) {
                    cout << "Invalid query!" << endl;
                    continue;
                } else {
                    if (s[x]<s[y]) {
                        loser = chef[x];
                        winner = chef[y];
                    } else if (s[y]<s[x]) {
                        loser = chef[y];
                        winner = chef[x];
                    }    
                    while (!dish[loser].empty()) {
                        chef[dish[loser].top()] = winner;
                        dish[winner].push(x);
                        dish[loser].pop();
                    }
                }
            } else {
                cin >> x;
                winner = chef[x-1]+1;
                cout << winner << endl;
            }
        }
    } 
    return 0;
}
