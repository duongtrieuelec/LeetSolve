# [1275. Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game)



## Description

<p>Tic-tac-toe is played&nbsp;by&nbsp;two players <em>A</em> and <em>B</em> on a&nbsp;<i>3</i>&nbsp;x&nbsp;<i>3</i>&nbsp;grid.</p>

<p>Here are the rules of Tic-Tac-Toe:</p>

<ul>
	<li>Players take turns placing characters into empty squares (&quot; &quot;).</li>
	<li>The first player <em>A</em> always places &quot;X&quot; characters, while the second player <em>B</em>&nbsp;always places &quot;O&quot; characters.</li>
	<li>&quot;X&quot; and &quot;O&quot; characters are always placed into empty squares, never on filled ones.</li>
	<li>The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.</li>
	<li>The game also ends if all squares are non-empty.</li>
	<li>No more moves can be played if the game is over.</li>
</ul>

<p>Given an array <code>moves</code> where each element&nbsp;is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which <em>A</em> and <em>B</em> play.</p>

<p>Return the winner of the game if it exists (<em>A</em> or <em>B</em>), in case the game ends in a draw return &quot;Draw&quot;, if there are still movements to play return &quot;Pending&quot;.</p>

<p>You can assume that&nbsp;<code>moves</code> is&nbsp;<strong>valid</strong> (It follows the rules of Tic-Tac-Toe),&nbsp;the grid is initially empty and <em>A</em> will play <strong>first</strong>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre>

<strong>Input:</strong> moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]

<strong>Output:</strong> &quot;A&quot;

<strong>Explanation:</strong> &quot;A&quot; wins, he always plays first.

&quot;X  &quot;    &quot;X  &quot;    &quot;X  &quot;    &quot;X  &quot;    &quot;<strong>X</strong>  &quot;

&quot;   &quot; -&gt; &quot;   &quot; -&gt; &quot; X &quot; -&gt; &quot; X &quot; -&gt; &quot; <strong>X</strong> &quot;

&quot;   &quot;    &quot;O  &quot;    &quot;O  &quot;    &quot;OO &quot;    &quot;OO<strong>X</strong>&quot;

</pre>

<p><strong>Example 2:</strong></p>

<pre>

<strong>Input:</strong> moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]

<strong>Output:</strong> &quot;B&quot;

<strong>Explanation:</strong> &quot;B&quot; wins.

&quot;X  &quot;    &quot;X  &quot;    &quot;XX &quot;    &quot;XXO&quot;    &quot;XXO&quot;    &quot;XX<strong>O</strong>&quot;

&quot;   &quot; -&gt; &quot; O &quot; -&gt; &quot; O &quot; -&gt; &quot; O &quot; -&gt; &quot;XO &quot; -&gt; &quot;X<strong>O</strong> &quot; 

&quot;   &quot;    &quot;   &quot;    &quot;   &quot;    &quot;   &quot;    &quot;   &quot;    &quot;<strong>O</strong>  &quot;

</pre>

<p><strong>Example 3:</strong></p>

<pre>

<strong>Input:</strong> moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]

<strong>Output:</strong> &quot;Draw&quot;

<strong>Explanation:</strong> The game ends in a draw since there are no moves to make.

&quot;XXO&quot;

&quot;OOX&quot;

&quot;XOX&quot;

</pre>

<p><strong>Example 4:</strong></p>

<pre>

<strong>Input:</strong> moves = [[0,0],[1,1]]

<strong>Output:</strong> &quot;Pending&quot;

<strong>Explanation:</strong> The game has not finished yet.

&quot;X  &quot;

&quot; O &quot;

&quot;   &quot;

</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= moves.length &lt;= 9</code></li>
	<li><code>moves[i].length == 2</code></li>
	<li><code>0 &lt;= moves[i][j] &lt;= 2</code></li>
	<li>There are no repeated elements on <code>moves</code>.</li>
	<li><code>moves</code> follow the rules of tic tac toe.</li>
</ul>

## Solutions

<!-- tabs:start -->

### **Python3**

```python
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        n = len(moves)
        counter = [0] * 8
        for i in range(n - 1, -1, -2):
            row, col = moves[i][0], moves[i][1]
            counter[row] += 1
            counter[col + 3] += 1
            if row == col:
                counter[6] += 1
            if row + col == 2:
                counter[7] += 1
            if counter[row] == 3 or counter[col + 3] == 3 or counter[6] == 3 or counter[7] == 3:
                return "A" if (i % 2) == 0 else "B"
        return "Draw" if n == 9 else "Pending"
```

### **Java**

```java
class Solution {
    public String tictactoe(int[][] moves) {
        int n = moves.length;
        int[] counter = new int[8];
        for (int i = n - 1; i >= 0; i -= 2) {
            int row = moves[i][0], col = moves[i][1];
            ++counter[row];
            ++counter[col + 3];
            if (row == col) ++counter[6];
            if (row + col == 2) ++counter[7];
            if (counter[row] == 3 || counter[col + 3] == 3 || counter[6] == 3 || counter[7] == 3) {
                return (i % 2) == 0 ? "A" : "B";
            }
        }
        return n == 9 ? "Draw" : "Pending";
    }
}
```

### **C++**

```cpp
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        vector<int> counter(8, 0);
        for (int i = n - 1; i >= 0; i -= 2) {
            int row = moves[i][0], col = moves[i][1];
            ++counter[row];
            ++counter[col + 3];
            if (row == col) ++counter[6];
            if (row + col == 2) ++counter[7];
            if (counter[row] == 3 || counter[col + 3] == 3 || counter[6] == 3 || counter[7] == 3) {
                return (i % 2 == 0) ? "A" : "B";
            }
        }
        return n == 9 ? "Draw" : "Pending";
    }
};
```

### **...**

```

```

<!-- tabs:end -->
