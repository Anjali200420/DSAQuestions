class Solution {
public:
    bool judgeCircle(string moves) {
        int row = 0, col = 0;

        for(int i = 0; i < moves.length(); i++){
            char dir = moves[i];

            if(dir == 'R') col += 1;
            else if(dir == 'L') col -= 1;
            else if(dir == 'U') row -= 1;
            else if(dir == 'D') row += 1;
        }

        return (row == 0 && col == 0);
    }
};