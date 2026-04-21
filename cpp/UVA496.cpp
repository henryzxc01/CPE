//https://zerojudge.tw/ShowProblem?problemid=d691
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

// 快速讀取一行數字並轉為排序好的 vector
vector<int> get_vec(string s) {
    stringstream ss(s);
    int n;
    vector<int> v;
    while (ss >> n) v.push_back(n);
    sort(v.begin(), v.end());
    return v;
}

int main() {
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        vector<int> A = get_vec(s1), B = get_vec(s2);

        bool A_in_B = includes(B.begin(), B.end(), A.begin(), A.end());
        bool B_in_A = includes(A.begin(), A.end(), B.begin(), B.end());

        if (A_in_B && B_in_A) 
            cout << "A equals B" << endl;
        else if (A_in_B) 
            cout << "A is a proper subset of B" << endl;
        else if (B_in_A) 
            cout << "B is a proper subset of A" << endl;
        else {
            // 檢查交集是否為空
            vector<int> intersect;
            set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(intersect));
            
            if (intersect.empty()) cout << "A and B are disjoint" << endl;
            else cout << "I'm confused!" << endl;
        }
    }
    return 0;
}
/*python
import sys

# 讀取所有輸入並過濾掉空行
lines = [line.strip() for line in sys.stdin if line.strip()]

# 每兩行為一組處理 (A, B)
for i in range(0, len(lines), 2):
    A = set(map(int, lines[i].split()))
    B = set(map(int, lines[i+1].split()))
    
    if A == B:
        print("A equals B")
    elif A < B:
        print("A is a proper subset of B")
    elif A > B:
        print("B is a proper subset of A")
    elif not (A & B):
        print("A and B are disjoint")
    else:
        print("I'm confused!")*/
