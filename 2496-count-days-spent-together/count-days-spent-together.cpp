class Solution {
public:
    vector<int>t(string s){
        stringstream ss(s);
        string token;
        vector<int>tokens;
        while(getline(ss,token,'-')){
            tokens.push_back(stoi(token));
        }
        return tokens;
    }
    int days(vector<int> arr){
        int fi = (275 * arr[0]) / 9;
        int si = 2 * ((arr[0] + 9) / 12);
        return fi - si + arr[1] - 30;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>AA,AL,BA,BL;
        AA=t(arriveAlice);
        AL=t(leaveAlice);
        BA=t(arriveBob);
        BL=t(leaveBob);

        int aa,al,ba,bl;
        aa=days(AA);
        al=days(AL);
        ba=days(BA);
        bl=days(BL);
        int start=max(aa,ba);
        int end=min(al,bl);
        return max(0,end-start+1);

    }
};