/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <iostream>
#include <stack>
#include <queue>
// @lc code=start
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {

    }
    
    void push(int x) {
        while(!s2.empty()){
            s1.emplace(s2.top());
            s2.pop();
        }
        s1.emplace(x);
        while(!s1.empty()){
            s2.emplace(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
        int value = s2.top();
        s2.pop();
        return value;
    }
    
    int peek() {
        return s2.top();
    }
    
    bool empty() {
        return s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

