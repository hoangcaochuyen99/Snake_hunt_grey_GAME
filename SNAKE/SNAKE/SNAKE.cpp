#include <iostream>
#include "mylib.h"
using namespace std;

int main() {
    int i = 1;//biến màu
    int x = 10, y = 0;
    int xcu = x, ycu = y;
    int check = 0;
    // set bien bang (100,28)
    // 0 cham vao bien tren - di xuong
    // 1 cham vào bien duoi - di len
    // 2 cham vao bien phai - di qua trai
    // 3 cham vao bien trai - di qua phai
    while (true) {
        gotoXY(xcu, ycu);
        cout << "                     ";
        gotoXY(x, y);
        cout << "HOC LAP TRINH THAT DE";
        xcu = x;
        ycu = y;
        SetColor(i);
        i++;
        if (i > 15) {
            i = 1;
        }
        // dieu khien
        if (_kbhit()) {
            char kitu = _getch();
            if (kitu == -32) {
                kitu = _getch();
                // su dung ki hieu mui ten duoi dang ma Ascii
                if (kitu == 72)//di len
                {
                    check = 1;
                }
                else if (kitu == 80)//di xuong
                {
                    check = 0;
                }
                else if (kitu == 75)//qua trai
                {
                    check = 2;
                }
                else if (kitu == 77)//qua phai
                {
                    check = 3;
                }

            }
        }
        // kiem tra huong
        if (check == 0) {
            y++;
        }
        else if (check == 1) {
            y--;
        }
        else if (check == 2) {
            x--;
        }
        else if (check == 3) {
            x++;
        }
        //kiem tra bien
        if (y == 28) {
            check = 1;
        }
        else if (y == 0) {
            check = 0;
        }
        else if (x == 0) {
            check = 3;
        }
        else if (x == 100) {
            check = 2;
        }
        Sleep(100);
    }
    _getch(); //tranh man hinh console tat qua nhanh
    return 0;
}