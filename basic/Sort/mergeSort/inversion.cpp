//The header need for this template
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int res = 0;

void mergeSort(int l, int s, vector<int> &arr) {
    if (l >= s) return;
    int mid = (l + s) >> 1;
    mergeSort(l, mid, arr);
    mergeSort(mid + 1, s, arr);
    int i = l, j = mid + 1;
    int cnt = 0; 
    vector<int> c(s - l + 1, 0);
    while(i <= mid && j <= s) {
        if (arr[i] <= arr[j]) {
            c[cnt++] = arr[i++];
        } else {
            c[cnt++] = arr[j++];
            res += (mid - i + 1);
        }
    }
    while(j <= s) {
        c[cnt++] = arr[j++];
    }
    while(i <= mid) {
        c[cnt++] = arr[i++];
    }
    for (int i = 0; i < cnt; i++) {
        arr[l + i] = c[i];
    }
}

/*
* use Merge Sort to find the Inversion counts for a sequence. 
*/
