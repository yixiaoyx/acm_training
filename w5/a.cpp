#include <iostream>
using namespace std;


void length(int i, int a[], int len[]) {
    if (i==0) {
        len[i]=1;
        return;
    }
    if (a[i]>a[i-1]) 
        len[i] = 1+len[i-1];
    else
        len[i] = 1;
}

int main() {
    int n;
    cin >> n;
    int array[n] = {0};
    int len[n] = {0};
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    
    for (int i = 0; i < n; i++) {
        length(i, array, len);
        if (len[i] > max) max = len[i];
    }

    cout << max << endl;

    return 0;
}
