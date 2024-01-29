class MyQueue {
public:
    stack<int> a, b;
    MyQueue() {}

    void push(int x) {
        while (a.size()) {
            b.push(a.top());
            a.pop();
        }
        a.push(x);
        while (b.size()) {
            a.push(b.top());
            b.pop();
        }
    }

    int pop() {
        int num = a.top();
        a.pop();
        return num;
    }

    int peek() { return a.top(); }

    bool empty() { return a.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
