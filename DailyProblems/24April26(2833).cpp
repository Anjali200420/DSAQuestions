class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int leftMoves = 0, rightMoves = 0;

        for(int ind = 0; ind < n; ind++){
            if(moves[ind] == 'L') leftMoves++;
            else if(moves[ind] == 'R') rightMoves++;
        }

        return (leftMoves < rightMoves) ? (n - 2*leftMoves) : (n - 2*rightMoves);
    }
};