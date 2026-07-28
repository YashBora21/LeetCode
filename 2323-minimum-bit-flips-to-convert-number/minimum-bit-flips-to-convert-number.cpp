class Solution {
public:
    
    int minBitFlips(int start, int goal) {
        if(goal==start)return 0;
        int ans=start^goal;
        int count =0;

        while(ans!=1){
            if(ans&1) count++;
            ans=ans>>1;
        }
        return count+1;
    }
};