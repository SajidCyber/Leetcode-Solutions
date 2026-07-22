class MyStack {

    Queue<Integer> main = new LinkedList<>();
    Queue<Integer> help = new LinkedList<>();
    public MyStack() {
        
    }
    
    public void push(int x) {
        main.add(x);
    }
    
    public int pop() {
        if(main.size()==0) return -1;
        while(main.size()!=1){
            help.add(main.remove());
        }
        int rv = main.remove();
        while(help.size()!=0){
            main.add(help.remove());
        }
        return rv;
    }
    
    public int top() {
        if(main.size()==0) return -1;
        while(main.size()!=1){
            help.add(main.remove());

        }
        int rv = main.remove();
        while(help.size()!=0){
            main.add(help.remove());
        }
        main.add(rv);
        return rv;
    }
    
    public boolean empty() {
        if(main.size()==0) return true;
        return false;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */