#include <iostream>

std::string cell1 = " 1. ";
std::string cell2 = " 2. ";
std::string cell3 = " 3. ";
std::string cell4 = " 4. ";
std::string cell5 = " 5. ";
std::string cell6 = " 6. ";
std::string cell7 = " 7. ";
std::string cell8 = " 8. ";
std::string cell9 = " 9. ";
bool lastSymbolIsX = false;
int usedCells[9];
void ShowCells() {
    std::cout << cell1 << cell2 << cell3 << std::endl;
    std::cout << cell4 << cell5 << cell6 << std::endl;
    std::cout << cell7 << cell8 << cell9 << std::endl;
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
    }
    else {
        std::cout << "This cell is occupied. Enter the number one more time." << std::endl;
    }
    ShowCells();
}
bool GameOverCheck() {
    //Horizontal
    if (cell1 == cell2 && cell2 == cell3 || cell4 == cell5 && cell5 == cell6 || cell7 == cell8 && cell8 == cell9) {
        return true;
    }
    //Vertical
    else if (cell1 == cell4 && cell4 == cell7 || cell2 == cell5 && cell5 == cell8 || cell3 == cell6 && cell6 == cell9) {
        return true;
    }
    //Diagonal 
    else if (cell1 == cell5 && cell5 == cell9 || cell3 == cell5 && cell5 == cell7) {
        return true;
    }
    return false;
}
int main()
{
    ShowCells();
    while (!GameOverCheck())
    {
        std::cout << "Enter the number: ";
        int number;
        std::cin >> number;
        if (lastSymbolIsX == false) {
            ChooseCell(number, " X ");
        }
        else {
            ChooseCell(number, " O ");
        }
    }
    return 0;
}

