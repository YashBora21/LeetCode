class Solution {
public:
    int fibonacci(int n){
        if(n==1||n==0)return n;
        return fibonacci(n-2)+fibonacci(n-1);
    }
    int fib(int n) {
        //your code goes here
        return fibonacci(n);

    }
};