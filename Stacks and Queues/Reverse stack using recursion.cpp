void reverse(Stack<Integer> stk ){
        if(stk.size()==1)
            return;
        int temp=stk.pop();
        reverse(stk);
        pushInStack(stk,temp);
    }

    void pushInStack(Stack<Integer> stk, int temp){
        if(stk.size()==0){
            stk.push(temp);
            return;
        }else{
            int value=stk.pop();
            pushInStack(stk,temp);
            stk.push(value);
            return;
        }
    }
