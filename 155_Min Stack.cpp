class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if(minstk.empty()) 
        {
            minstk.push(x);
            return;
        }
        if(x <= minstk.top()) 
        {
            minstk.push(x);
        }
    }
    
    void pop() {
        int tmp = stk.top();
        stk.pop();
        if(!minstk.empty() && minstk.top() == tmp) minstk.pop(); 
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
private:
    stack<int> stk;
    stack<int> minstk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
