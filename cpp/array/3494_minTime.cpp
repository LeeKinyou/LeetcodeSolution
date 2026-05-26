#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<ll> times(n);
        for (int j = 0; j < m; j++) {
            ll cur_time = 0;
            for (int i = 0; i < n; i++) {
                cur_time = max(cur_time, times[i]) + skill[i] * mana[j];
            }
            times[n - 1] = cur_time;
            for (int i = n - 2; i >= 0; i--) {
                times[i] = times[i + 1] - skill[i + 1] * mana[j];
            }
        }
        return times[n - 1];
    }
};
class StInfo
{
    /********* Begin *********/
    //在此处声明StInfo类
public:
    int SID;
    string Name, Class, Phone;
    StInfo(int SID, string Name, string Class, string Phone) {
        this->SID = SID;
        this->Name = Name;
        this->Class = Class;
        this->Phone = Phone;
    }
    
    void PrintInfo() {
        cout << SID << " " << Name << " " << Class << " " << Phone << endl;
    }
    
    
    /********* End *********/
};

struct Linked
{
    /********* Begin *********/
    //结构体的成员变量
    int student_id;
    float score;
    Linked *next;

    Linked() : student_id(-1), score(-1), next(nullptr) {}

    Linked(int student_id, float score) : student_id(student_id), score(score), next(nullptr) {}
    /********* End *********/
};

Linked* Create()
{
    /********* Begin *********/
    //创建并返回一个新链表
    return new Linked();
    /********* End *********/
}

void InsertAfter(Linked *node,int num,float sc)
{
    /********* Begin *********/
    //在指定节点后插入一个新节点，内容由 num，sc 参数指定
    Linked *newNode = new Linked(num, sc);
    newNode->next = node->next;
    node->next = newNode;
    /********* End *********/
}

void DeleteAfter(Linked *node)
{
    /********* Begin *********/
    //删除此节点之后的一个节点
    auto tmp = node->next;
    node->next = node->next->next;
    delete tmp;
    /********* End *********/
}

Linked* GetByIndex(Linked *head,int index)
{
    /********* Begin *********/
    //返回指定索引处的节点
    auto cur = head->next;
    while (index--) {
        cur = cur->next;
    }
    return cur;
    /********* End *********/
}

void PrintAll(Linked *head)
{
    /********* Begin *********/
    //按格式打印此链表中所有节点的成员变量
    auto cur = head->next;
    while (cur) {
        cout << cur->student_id << " " << cur->score << endl;
        cur = cur->next;
    }
    /********* End *********/
}


int main()
{
	int num;
	float score;
	cin >> num >> score ;
    Linked *lk = Create();
    InsertAfter(lk,num,score);
	cin >> num >> score ;
    InsertAfter(GetByIndex(lk,0),num,score);
	cin >> num >> score ;
    InsertAfter(GetByIndex(lk,1),num,score);
    DeleteAfter(GetByIndex(lk,0));
    PrintAll(lk);
}