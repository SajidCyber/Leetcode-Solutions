class MinStack {

    Stack<Integer> st = new Stack<>();
    Stack<Integer> min = new Stack<>();
    public MinStack() {
        
    }
    
    public void push(int value) {
        st.push(value);
        if(min.size()==0 || value<=min.peek()){
            min.push(value);
        }
    }
    
    public void pop() {
        if(st.size()==0) return;
        int rv = st.pop();
        if(rv==min.peek()) min.pop();
    }
    
    public int top() {
        if(st.size()==0) return -1;
        return st.peek();
    }
    
    public int getMin() {
        if(min.size()==0) return -1;
        return min.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */