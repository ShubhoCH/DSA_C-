//Time:  O(1);
//Space: O(N);
class MinStack {
public:
    std::vector<int> stackVec;
    MinStack() {
        
    }
    
    void push(int val) {
        stackVec.push_back(val);
    }
    void pop() {
         stackVec.pop_back();
    }
    int top() {
        return stackVec.back();
    }
    int getMin() {   
        return *min_element(stackVec.begin(),stackVec.end());
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
