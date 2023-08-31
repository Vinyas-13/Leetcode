class Solution {
public:
    int minBitFlips(int start, int goal) {
        int XOR=start^goal;// xor will set all bits which are not matched
        int flips=0;
        while(XOR) //count the no of set bits using Brian Kernighan’s Algorithm 
        {
            XOR=XOR&(XOR-1);
            flips++;
        }
        return flips;
    }
};