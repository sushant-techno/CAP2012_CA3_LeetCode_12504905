// LeetCode 225 - Implement Stack using Queues
class MyStack {
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int count = (int)q.size();
        while (count > 1) {
            q.push(q.front());
            q.pop();
            count--;
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
