#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n, num;
    priority_queue<int>q;
    scanf("%d", &n);
    int size = n;
    for (int i = 0; i < size; i++) {
        cin >> num;
        //cout << "num = " << num << " ";
        //cout << "i = " << i << " ";
        if (num==n) {
            cout << num << " ";
            n--;
            while (!q.empty() && q.top()>=n) {
                cout << q.top() << " ";
                q.pop();
                n--;
            }
        } else {
            q.push(num);
            //cout << "enqueue: " << q.top() << endl;
        }

        cout << endl;
    }

    return 0;
}
