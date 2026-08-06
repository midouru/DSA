class Solution {
public:

    int prodofdig(int n){
        if (n == 0) return 0;
        int prod = 1;
        while(n>0){
            int dig = n%10;
            prod = prod*dig;
            n=n/10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
  
        for(int i = n; ;i++){
            int prod = prodofdig(i);
            if(prod%t == 0){
                return i;
            }
        }

 
    }
};