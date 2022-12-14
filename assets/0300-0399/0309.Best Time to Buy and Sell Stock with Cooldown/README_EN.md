# [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown)



## Description

<p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:</p>

<ul>
	<li>After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).</li>
</ul>

<p><strong>Note:</strong> You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> prices = [1,2,3,0,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> transactions = [buy, sell, cooldown, buy, sell]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> prices = [1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 5000</code></li>
	<li><code>0 &lt;= prices[i] &lt;= 1000</code></li>
</ul>


## Solutions

<!-- tabs:start -->

### **Python3**

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        f1, f2, f3 = -prices[0], 0, 0
        for price in prices[1:]:
            pf1, pf2, pf3 = f1, f2, f3
            f1 = max(pf1, pf3 - price)
            f2 = max(pf2, pf1 + price)
            f3 = max(pf3, pf2)
        return f2
```

### **Java**

```java
class Solution {
    public int maxProfit(int[] prices) {
        int f1 = -prices[0], f2 = 0, f3 = 0;
        for (int i = 1; i < prices.length; ++i) {
            int pf1 = f1, pf2 = f2, pf3 = f3;
            f1 = Math.max(pf1, pf3 - prices[i]);
            f2 = Math.max(pf2, pf1 + prices[i]);
            f3 = Math.max(pf3, pf2);
        }
        return f2;
    }
}
```

### **C++**

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f1 = -prices[0], f2 = 0, f3 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int pf1 = f1, pf2 = f2, pf3 = f3;
            f1 = max(pf1, pf3 - prices[i]);
            f2 = max(pf2, pf1 + prices[i]);
            f3 = max(pf3, pf2);
        }
        return f2;
    }
};
```

### **Go**

```go
func maxProfit(prices []int) int {
	f1, f2, f3 := -prices[0], 0, 0
	for i := 1; i < len(prices); i++ {
		pf1, pf2, pf3 := f1, f2, f3
		f1 = max(pf1, pf3-prices[i])
		f2 = max(pf2, pf1+prices[i])
		f3 = max(pf3, pf2)
	}
	return f2
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

### **...**

```

```

<!-- tabs:end -->
