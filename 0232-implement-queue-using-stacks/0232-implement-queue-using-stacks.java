class MyQueue {

    Stack<Integer> main = new Stack<>();
    Stack<Integer> help = new Stack<>();
    public MyQueue() {
        
    }
    
    public void push(int x) {
        main.push(x);
    }
    
    public int pop() {
        if(main.size()==0) return -1;
        while(main.size()!=1){
            help.push(main.pop());
        }
        int rv = main.pop();
        while(help.size()!=0){
            main.push(help.pop());
        }
        return rv;
    }
    
    public int peek() {
         if(main.size()==0) return -1;
        while(main.size()!=1){
            help.push(main.pop());
        }
        int rv = main.pop();
        main.push(rv);
        while(help.size()!=0){
            main.push(help.pop());
        }
        return rv;
        
    }
    
    public boolean empty() {
        if(main.size()==0) return true;
        return false;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */