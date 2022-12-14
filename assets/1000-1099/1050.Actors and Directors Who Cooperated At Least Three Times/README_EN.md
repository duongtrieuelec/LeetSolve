# [1050. Actors and Directors Who Cooperated At Least Three Times](https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times)



## Description

<p>Table: <code>ActorDirector</code></p>



<pre>

+-------------+---------+

| Column Name | Type    |

+-------------+---------+

| actor_id    | int     |

| director_id | int     |

| timestamp   | int     |

+-------------+---------+

timestamp is the primary key column for this table.

</pre>



<p>&nbsp;</p>



<p>Write a SQL query for a report that provides the pairs <code>(actor_id, director_id)</code> where the actor have cooperated with the director at least 3 times.</p>



<p><strong>Example:</strong></p>



<pre>

ActorDirector table:

+-------------+-------------+-------------+

| actor_id    | director_id | timestamp   |

+-------------+-------------+-------------+

| 1           | 1           | 0           |

| 1           | 1           | 1           |

| 1           | 1           | 2           |

| 1           | 2           | 3           |

| 1           | 2           | 4           |

| 2           | 1           | 5           |

| 2           | 1           | 6           |

+-------------+-------------+-------------+



Result table:

+-------------+-------------+

| actor_id    | director_id |

+-------------+-------------+

| 1           | 1           |

+-------------+-------------+

The only pair is (1, 1) where they cooperated exactly 3 times.

</pre>



## Solutions

Use `GROUP BY` & `HAVING`.

<!-- tabs:start -->

### **SQL**

```sql
# Write your MySQL query statement below
SELECT
    actor_id, director_id
FROM
    ActorDirector
GROUP BY actor_id, director_id
HAVING count(1) >= 3;
```

<!-- tabs:end -->