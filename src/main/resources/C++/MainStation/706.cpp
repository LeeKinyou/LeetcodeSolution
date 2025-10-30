#include <bits/stdc++.h>

using namespace std;

class MyHashMap {
public:
    MyHashMap() {
        hashmap.resize(1000001, {-1, -1});
    }
    
    void put(int key, int value) {
        hashmap[key] = {key, value};
    }
    
    int get(int key) {
        if (hashmap[key].first == key) {
            return hashmap[key].second;
        }
        return -1;
    }
    
    void remove(int key) {
        hashmap[key] = {-1, -1};
    }
private:
    vector<pair<int, int>> hashmap;
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
int main() {

    return 0;
}