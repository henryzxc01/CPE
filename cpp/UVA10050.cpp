//https://zerojudge.tw/ShowProblem?problemid=e579
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int days, parties;
        cin >> days >> parties;

        int isHartalDay[3700];
        memset(isHartalDay, 0, sizeof(isHartalDay));

        // 標記每個政黨造成的罷工日
        for (int i = 0; i < parties; i++) {
            int hartalParameter;
            cin >> hartalParameter;

            for (int day = hartalParameter; day <= days; day += hartalParameter) {
                isHartalDay[day] = 1;
            }
        }

        // 題目規定：星期五和星期六不算損失工作日
        // 第 1 天是星期日，所以第 6, 13, 20... 天是星期五
        for (int day = 6; day <= days; day += 7) {
            isHartalDay[day] = 0;
        }

        // 第 7, 14, 21... 天是星期六
        for (int day = 7; day <= days; day += 7) {
            isHartalDay[day] = 0;
        }

        int lostWorkingDays = 0;

        for (int day = 1; day <= days; day++) {
            lostWorkingDays += isHartalDay[day];
        }

        cout << lostWorkingDays << '\n';
    }

    return 0;
}
