#include <bits/stdc++.h>

using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        hashset.resize(1000001, 0);
    }
    
    void add(int key) {
        hashset[key] = 1;
    }
    
    void remove(int key) {
        hashset[key] = 0;
    }
    
    bool contains(int key) {
        return hashset[key] == 1;
    }

private:
    vector<int> hashset;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {

    return 0;
}