//https://zerojudge.tw/ShowProblem?problemid=e561
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int arr[50];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // 計算逆序對數量 (Bubble Sort 交換次數)
        int swaps = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    swaps++;
                }
            }
        }
        
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }
    
    return 0;
}
