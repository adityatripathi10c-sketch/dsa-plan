class MyQueue {
private:
    stack<int> s1; // Input stack
    stack<int> s2; // Output stack

public:
    MyQueue() {}
    
    // 📥 Push: O(1)
    void push(int x) {
        s1.push(x);
    }
    
    // 👀 Peek: Amortized O(1)
    int peek() {
        // Transfer tabhi karenge jab s2 khali ho
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    // 📤 Pop: Amortized O(1)
    int pop() {
        int val = peek(); // Pehle front element ko s2 ke top par laayenge
        s2.pop();
        return val;
    }
    
    // ❓ Empty: O(1)
    bool empty() {
        return s1.empty() && s2.empty();
    }
};