/*Problem Statement: Knight Rider
You are given a n x m chessboard and q knights, each with a unique starting position and a step size. A knight can move to any of the 8 possible positions in an "L" shape, but the distance it can cover in a single move can vary and is determined by its step size k. The step size k denotes the maximum number of steps the knight can take in one move (i.e., the knight can move k times its normal move distance).

Your task is to determine the minimum number of moves required to reach a square on the board that is visited by all q knights. If there is no such square, return -1.

Input
The first line contains three integers n, m, and q (1 <= n, m <= 100, 1 <= q <= 100): the dimensions of the chessboard and the number of knights, respectively.
The next q lines each contain three integers x, y, and k (0 <= x < n, 0 <= y < m, 1 <= k <= 100): the starting position (x, y) and the step size k for each knight.
Output
Output a single integer: the minimum number of moves required for a square to be visited by all q knights. If no such square exists, output -1.
Example
Input:

5 5 3
0 0 1
4 4 1
2 2 2
Output:

5 //they all meet at (2,2) square in total of 5 moves
Explanation
Knight 1 starts at (0, 0) with a step size of 1.
Knight 2 starts at (4, 4) with a step size of 1.
Knight 3 starts at (2, 2) with a step size of 2.
The minimum number of moves required for all three knights to visit the same square is 3. If no such square exists, the output should be -1.*/

/*Hint:: what does k mean?

In the context of the problem statement, the "step size" k refers to a modification of the knight's movement in chess.

Normally, a knight moves in an "L" shape: it can move two squares in one direction and then one square perpendicular to that, or one square in one direction and then two squares perpendicular to that. This results in up to 8 possible moves for the knight from any given position.

The "step size" k modifies this behavior as follows:

The knight can move up to k times its normal move distance in one step.
For example, if the step size k is 2:

A normal knight move of 2 squares in one direction and 1 square in a perpendicular direction can be extended to up to 4 squares in one direction and 2 squares in a perpendicular direction.
In the given problem, this modification allows the knight to cover larger distances in fewer moves, which impacts how quickly it can reach different squares on the chessboard.

The BFS (breadth-first search) algorithm implemented in the code takes into account this step size k to calculate the minimum number of moves required for the knight to reach each square on the board. This is done by adjusting the number of moves based on the step size and ensuring the moves are counted correctly.

Example
Consider a 5x5 board with a knight starting at position (0, 0) with a step size of 2. The knight can move:

Up to 4 squares in one direction and 2 squares in a perpendicular direction.
So the possible moves would be:

From (0, 0) to (4, 2)
From (0, 0) to (2, 4)
From (0, 0) to (-4, 2) (not valid on the 5x5 board)
From (0, 0) to (-2, 4) (not valid on the 5x5 board)
From (0, 0) to (4, -2) (not valid on the 5x5 board)
From (0, 0) to (2, -4) (not valid on the 5x5 board)
From (0, 0) to (-4, -2) (not valid on the 5x5 board)
From (0, 0) to (-2, -4) (not valid on the 5x5 board)
The BFS algorithm would consider these extended moves and calculate the minimum number of steps to reach each square on the board based on these possible moves.*/

// solution::
#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <queue>
using namespace std;
class ChessBoard
{
public:
    int n, m, q;                    // n=row,m=coloumn,q=no. of knights
    vector<vector<int>> visitCount; // 2D matrix of order nxm to store how many knights visit a certain cell
    // di[i]+ dj[i]=knight's move along x-axis + knight's move along y-axis
    int di[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dj[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    vector<vector<int>> sumSquare; // 2D matrix of order nxm to store it takes total how many moves to reach the cell (i,j) for 1 or more knights
public:
    ChessBoard(int n, int m, int q) // constructor
    {
        this->n = n;
        this->m = m;
        this->q = q;
        // resizing the 2D matrices
        visitCount.resize(n);
        sumSquare.resize(n);
        for (int i = 0; i < n; i++)
        {
            visitCount[i].resize(m);
            sumSquare[i].resize(m);
        }
    }
    bool isValidMove(int x, int y) // checking whether (x,y) fall inside the board or not
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    bool BFS(int x, int y, int k)
    {
        vector<vector<int>> distance(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        q.push({x, y});
        distance[x][y] = 0; // the moves for its own square is always 0
        visitCount[x][y]++;
        while (q.empty() != true)
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            // for all 8 possible knight moves
            for (int i = 0; i < 8; i++)
            {
                int new_x = x + di[i];
                int new_y = y + dj[i];
                if (isValidMove(new_x, new_y) && distance[new_x][new_y] == -1)
                {
                    q.push({new_x, new_y});
                    visitCount[new_x][new_y]++;
                    distance[new_x][new_y] = distance[x][y] + 1;
                }
            }
        }
        // modifying sumSquare 2D matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (distance[i][j] > -1)
                {
                    sumSquare[i][j] += (distance[i][j] + k - 1) / k;
                    // suppose for a knight k=2, initial position=(0,0). If it were a normal knight then it would move (0,0)->(1,2)->(3,3). It reaches (3,3) in 2 moves but as k=2 then it can cover this in a single move. If it tries to reach (1,4) afterwards then it have to give another move like a normal knight
                }
            }
        }
    }
    int findMinMove()
    {
        int min_move = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // we only consider the squares that have been visited by all the k riders
                if (visitCount[i][j] == q)
                {
                    min_move = min(min_move, sumSquare[i][j]);
                }
            }
        }
        return min_move;
    }
};

int main()
{
    int n, m, q, x, y, k;
    cin >> n >> m >> q;
    ChessBoard board1(n, m, q);
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y >> k;
        board1.BFS(x, y, k);
    }
    cout << board1.findMinMove();
}