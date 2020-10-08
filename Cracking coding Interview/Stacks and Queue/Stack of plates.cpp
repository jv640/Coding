/*
  Description : Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple. 
                Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. 
                Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
                SetOfStacks. push () and SetOfStacks. pop () should behave identically to a single stack (that is, pop ( ) 
                should return the same values as it would if there were just a single stack).
                FOLLOW UP
                    Implement a function popAt (int index) which performs a pop operation on a specific sub-stack. 
*/
// Approach is to use vector of stacks and 2 variable to keep track of push and pop

// code
  class DinnerPlates {
    int cap;
    vector<stack<int>> stks;
    int leftMost, rightMost;
public:
    DinnerPlates(int capacity) {
        cap = capacity;
        leftMost = 0;
        rightMost = 0;
    }
    
    void push(int val) {
        // traverse the leftMost 
        while(leftMost < stks.size() and stks[leftMost].size() == cap) {
            leftMost++;
        }
        
        // at the end
        if(leftMost == stks.size()) {
            stack<int> stk;
            stk.push(val);
            stks.push_back(stk);
        }
        else { // stack already created
            stks[leftMost].push(val);
        }
        
        // finally update the rightMost value
        rightMost = max(leftMost, rightMost);
    }
    
    int pop() {
        while(rightMost >= 0 and stks[rightMost].empty()) {
            rightMost--;
        }
        
        if(rightMost < 0) return -1;
        
        int top = stks[rightMost].top();
        stks[rightMost].pop();
        leftMost = min(leftMost, rightMost);
        return top;
    }
    
    int popAtStack(int index) {
        //if the particular stack is not present in stks
        if(stks.size() <= index) {
            return -1;
        }
        
        // if the stack is empty at given index
        if(stks[index].empty()) {
            return -1;
        }
        
        // if stack is not empty then return the value
        int tp = stks[index].top();
        stks[index].pop();
        
        leftMost = min(leftMost, index);
        
        return tp;
    }
};


/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
