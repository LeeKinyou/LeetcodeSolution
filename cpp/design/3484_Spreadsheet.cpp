#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Spreadsheet {
public:
    vector<vector<int>> cells;

    Spreadsheet(int rows) {
        this->cells.resize(26, vector<int>(rows + 1, 0));
    }

    int getColumn(string cell) {
        return cell[0] - 'A';
    }

    int getRow(string cell) {
        int num = 0;
        for (int i = 1; i < cell.size(); i++) {
            num = num * 10 + cell[i] - '0';
        }
        return num;
    }
    
    void setCell(string cell, int value) {
        this->cells[this->getColumn(cell)][this->getRow(cell)] = value;
    }
    
    void resetCell(string cell) {
        this->cells[this->getColumn(cell)][this->getRow(cell)] = 0;
    }

    int getNum(string cell) {
        if (cell[0] >= 'A' && cell[0] <= 'Z') {
            // cout << cell << endl;
            // cout << this->cells[this->getRow(cell)][this->getColumn(cell)] << endl;
            return this->cells[this->getColumn(cell)][this->getRow(cell)];
        } else {
            int num = 0;
            for (int i = 0; i < cell.size(); i++) {
                num = num * 10 + cell[i] - '0';
            }
            return num;
        }
    }
    
    int getValue(string formula) {
        string num1, num2;
        for (int i = 1; i < formula.size(); i++) {
            if (formula[i] == '+') {
                num1 = formula.substr(1, i - 1);
                num2 = formula.substr(i + 1, formula.size() - i - 1);
                break;
            }
        }
        return this->getNum(num1) + this->getNum(num2);
    }
};
int main() {
    Spreadsheet s(24);
    s.setCell("B24", 66688);
    s.resetCell("O15");
    return 0;
}