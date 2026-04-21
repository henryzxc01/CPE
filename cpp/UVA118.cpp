//https://zerojudge.tw/ShowProblem?problemid=c082
#include <iostream>
#include <map>
using namespace std;
int scent[55][55];
int dx[] = {0, 1, 0, -1}; //N, E, S, W
int dy[] = {1, 0, -1, 0};
 
int main() {
    int maxX, maxY, currX, currY, dirIdx, nextX, nextY;
    char dirChar;
    bool lost = false;
    string instructions;
    map <char, int> charToDir;
    map <int, char> dirToChar;
    charToDir['N'] = 0; dirToChar[0] = 'N';
    charToDir['E'] = 1; dirToChar[1] = 'E';
    charToDir['S'] = 2; dirToChar[2] = 'S';
    charToDir['W'] = 3; dirToChar[3] = 'W';
    cin >> maxX >> maxY;
    while (cin >> currX >> currY >> dirChar >> instructions){
        dirIdx = charToDir[dirChar];
        lost = false;
        for (int i = 0; i < instructions.size(); i++){
            if (instructions[i] == 'F'){
                nextX = currX + dx[dirIdx];
                nextY = currY + dy[dirIdx];
                if (nextX >= 0 && nextX <= maxX && nextY >= 0 && nextY <= maxY){
                    currX = nextX;
                    currY = nextY;
                } else {
                    if (scent[currX][currY] == 1){
                        //這個機器人正位在有標記的地方, 會忽略會讓他掉下去的指令。
                        continue;
                    } else {
                        cout << currX << " " << currY << " " << dirToChar[dirIdx] << " LOST\n";
                        lost = true;
                        scent[currX][currY] = 1;
                        break;
                    }
                }
            } else if (instructions[i] == 'R'){
                dirIdx = (dirIdx + 1) % 4;
            } else {
                dirIdx = (dirIdx - 1 + 4) % 4;
            }
        }
        if (!lost) cout << currX << " " << currY << " " << dirToChar[dirIdx] << "\n";
    }
    return 0;
}

