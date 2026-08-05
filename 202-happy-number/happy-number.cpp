class Solution {
public:

    int sqsum(int n){
        int sum = 0;
        while(n>0){
            int r = n%10;
            sum += r*r;
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = sqsum(n);
        while(fast!=1 && slow != fast){
            slow = sqsum(slow);
            fast = sqsum(sqsum(fast));
        }
        return fast == 1;
    }
};