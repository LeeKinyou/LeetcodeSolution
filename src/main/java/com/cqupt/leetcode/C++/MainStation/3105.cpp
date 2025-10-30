#include <list>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    list<int>l;
    
    l.push_back(1);
    l.push_front(2);
    l.push_back(2);
    for (auto i: l) {
        cout << i << " ";
    }

    return 0;
}