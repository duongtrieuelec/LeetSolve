# [1729. Find Followers Count](https://leetcode.com/problems/find-followers-count)



## Description

<p>Table: <code>Followers</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| follower_id | int  |
+-------------+------+
(user_id, follower_id) is the primary key for this table.
This table contains the IDs of a user and a follower in a social media app where the follower follows the user.</pre>

<p>Write an SQL query that will, for each user, return the number of followers.</p>

<p>Return the result table ordered by <code>user_id</code>.</p>

<p>The query result format is in the following example:</p>

<p>&nbsp;</p>

<pre>
Followers table:
+---------+-------------+
| user_id | follower_id |
+---------+-------------+
| 0       | 1           |
| 1       | 0           |
| 2       | 0           |
| 2       | 1           |
+---------+-------------+
Result table:
+---------+----------------+
| user_id | followers_count|
+---------+----------------+
| 0       | 1              |
| 1       | 1              |
| 2       | 2              |
+---------+----------------+
The followers of 0 are {1}
The followers of 1 are {0}
The followers of 2 are {0,1}
</pre>

<p>&nbsp;</p>

## Solutions

<!-- tabs:start -->

### **SQL**

```sql
# Write your MySQL query statement below
SELECT
    user_id, count(1) AS followers_count
FROM
    Followers
GROUP BY
    user_id
ORDER BY
    user_id
```

<!-- tabs:end -->
