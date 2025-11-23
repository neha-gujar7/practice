class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        // Move all but last from q1 → q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Last element is the TOP of the stack
        int val = q1.front();
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
        return val;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int val = q1.front(); // top element
        q1.pop();
        q2.push(val); // Put it back

        swap(q1, q2);
        return val;
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};
