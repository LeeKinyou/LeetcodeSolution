#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class TaskManager {
public:
    map<int, int> taskId_to_uesrId;
    map<int, int> taskId_to_priority;
    priority_queue<pair<int, int>> taskPriority;
    
    TaskManager(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            this->taskId_to_uesrId[tasks[i][1]] = tasks[i][0];
            this->taskId_to_priority[tasks[i][1]] = tasks[i][2];
            this->taskPriority.push(make_pair(tasks[i][2], tasks[i][1]));
        }
    }
    
    void add(int userId, int taskId, int priority) {
        this->taskId_to_uesrId[taskId] = userId;
        this->taskId_to_priority[taskId] = priority;
        this->taskPriority.push(make_pair(priority, taskId));
    }
    
    void edit(int taskId, int newPriority) {
        this->taskPriority.push(make_pair(newPriority, taskId));
        this->taskId_to_priority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        if (this->taskId_to_uesrId.find(taskId) != this->taskId_to_uesrId.end()) {
            this->taskId_to_uesrId.erase(taskId);
        }
    }
    
    int execTop() {
        while (taskPriority.size() > 0) {
            pair<int, int> temp = this->taskPriority.top();
            int temp_taskId = temp.second;
            int temp_priority = temp.first;
            if (this->taskId_to_uesrId.find(temp_taskId) == this->taskId_to_uesrId.end()) {
                this->taskPriority.pop();
            } else {
                this->taskPriority.pop();
                if (this->taskId_to_priority[temp_taskId] < temp_priority) {
                } else {
                    int ans = this->taskId_to_uesrId[temp_taskId];
                    this->rmv(temp_taskId);
                    return ans;
                }
            }
        }
        return -1;
    }
};


int main() {
    vector<vector<int>> tasks = {{2,12,32},{3,27,33},{10,5,23},{8,4,3}};
    TaskManager taskManager(tasks);
    taskManager.edit(4, 48);
    cout << taskManager.execTop() << endl;
    return 0;
}