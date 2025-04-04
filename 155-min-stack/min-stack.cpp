class MinStack {
public:
    stack<int> s;
    vector<int> v;
    int ans = INT_MAX; 

    MinStack() {}
    
    void push(int val) {
        s.push(val);
        v.push_back(val);
    }
    
    void pop() {
        int z = s.top();
        s.pop();
        
        auto it = find(v.begin(), v.end(), z);
        if (it != v.end()) {
            v.erase(it);
        }
    }
    
    int top() {
        return s.top(); 
    }
    
    int getMin() {
        return *min_element(v.begin(), v.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */