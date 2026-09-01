class Solution {
public:
    int fun(int n){
        int sum =0;
        while(n>0){
       int a = n%10;
       sum = sum + a*a;
       n= n/10;
        }
        return sum; 

    }
    bool isHappy(int n) {
    int slow = n;
    int fast = n;
    while(fast!=1){
        slow = fun(slow);
        fast= fun(fast);
        fast = fun(fast);
        if(slow == fast &&slow != 1){
            return false;
        }
        if(slow == 1){
        return true;
    }
    }

return true;
        
    }
};