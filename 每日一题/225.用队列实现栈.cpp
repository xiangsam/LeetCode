/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <iostream>
#include <queue>
// @lc code=start
class MyStack1 {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack1() {

    }
    
    void push(int x) {
        q1.emplace(x);
        while(!q2.empty()){
            q1.emplace(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int ret = q2.front();
        q2.pop();
        return ret;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q2.empty();
    }
};

class MyStack {
public:
    queue<int> q;
    MyStack() {

    }
    
    void push(int x) {
        int n = q.size();
        q.emplace(x);
        for(int i = 0; i < n; ++i){
            q.emplace(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

