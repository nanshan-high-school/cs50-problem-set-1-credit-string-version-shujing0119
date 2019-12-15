#include <iostream>
using namespace std;

int main() {
    string cardNum;
    cout << "請輸入卡號:";
    cin >> cardNum;

    int icount = 0;

    for(icount = 0; cardNum[icount] != '\0'; icount++){
        if(cardNum[icount] > '9' || cardNum[icount] < '0'){
            cout << "有非數字的字元";
            return 0;
        }
    } 
    if(icount == 0)
        return 0;

    //char cardNum_array[icount + 1];
    if (icount == 16) {
        if (cardNum[0] == 0x34) {
            cout << "Visa";
        } else if (cardNum[0] == 0x35 && (cardNum[1] >= 0x31 && cardNum[1] <= 0x35)) {
            cout << "MasterCard";
        } else {
            cout << "卡號錯誤";
            return 0;
        }
    } else if (icount == 15) {
        if (cardNum[0] == 0x33 && (cardNum[1] == 0x34 || cardNum[1] == 0x37)) {
            cout << "American Express";
        } else {
            cout << "卡號錯誤";
            return 0;
        }
    } else if (icount == 13) {
        if (cardNum[0] == 0x34) {
            cout << "Visa";
        } else {
            cout << "卡號錯誤";
            return 0;
        }
    } else {
        cout << "卡號錯誤";
        return 0;
    }

    cout << "\n";

    int total = 0;
    int odd = 0;

    for(int i = icount - 1; i >= 0; i--) {
        int inum = cardNum[i] - 0x30;
        odd++;

        if(odd % 2 == 0) {
            inum *= 2;
            inum = (inum / 10) + (inum % 10);
        } else {
            inum *= 1;
        }

        total = total + inum;
    }

    cout << total << "\n";

    if(total % 10 == 0) {
        cout << "卡號無誤";
    } else {
        cout << "卡號有誤";
    }
}

// 650275 杜心妍
