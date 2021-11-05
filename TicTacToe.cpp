#include <iostream>
using namespace std;

string cell1 = " 1. ";
string cell2 = " 2. ";
string cell3 = " 3. ";
string cell4 = " 4. ";
string cell5 = " 5. ";
string cell6 = " 6. ";
string cell7 = " 7. ";
string cell8 = " 8. ";
string cell9 = " 9. ";
bool lastSymbolIsX = false;
int usedCells[9];
int countUsedCells;
void ShowCells() {
    cout << cell1 << cell2 << cell3 << std::endl;
    cout << cell4 << cell5 << cell6 << std::endl;
    cout << cell7 << cell8 << cell9 << std::endl;
}
void ChooseCell(int number, std::string symbol) {
    if (number != usedCells[number]) {
        usedCells[number] = number;
        switch (number) {
        case 1:
            cell1 = symbol;
            break;
        case 2:
            cell2 = symbol;
            break;
        case 3:
            cell3 = symbol;
            break;
        case 4:
            cell4 = symbol;
            break;
        case 5:
            cell5 = symbol;
            break;
        case 6:
            cell6 = symbol;
            break;
        case 7:
            cell7 = symbol;
            break;
        case 8:
            cell8 = symbol;
            break;
        case 9:
            cell9 = symbol;
            break;
        }
        lastSymbolIsX = !lastSymbolIsX;
        countUsedCells++;
    }
    else {
        cout << "This cell is occupied. Enter the number one more time." << endl;
    }
    ShowCells();
}
bool GameOverCheck() {
    //Horizontal Win
    if (cell1 == cell2 && cell2 == cell3 || cell4 == cell5 && cell5 == cell6 || cell7 == cell8 && cell8 == cell9) {
        lastSymbolIsX?cout << "X Win" : cout <<"O Win";
        return true;
    }
    //Vertical Win
    else if (cell1 == cell4 && cell4 == cell7 || cell2 == cell5 && cell5 == cell8 || cell3 == cell6 && cell6 == cell9) {
        lastSymbolIsX ? cout << "X Win" : cout << "O Win";
        return true;
    }
    //Diagonal Win
    else if (cell1 == cell5 && cell5 == cell9 || cell3 == cell5 && cell5 == cell7) {
        lastSymbolIsX ? cout << "X Win" : cout << "O Win";
        return true;
    }
    //Draw
    if (countUsedCells == 9) {
        cout << "Draw";
        return true;
    }
    return false;
}
int main()
{
    ShowCells();
    while (!GameOverCheck())
    {
        cout << "Enter the number: ";
        int number;
        cin >> number;
        if (lastSymbolIsX == false) {
            ChooseCell(number, " X ");
        }
        else {
            ChooseCell(number, " O ");
        }
    }
    return 0;
}