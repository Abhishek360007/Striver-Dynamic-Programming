# Climbing Stairs | Dynamic Programming

## Problem Statement

You are climbing a staircase with `n` steps.

At each move, you can climb either:

- 1 step
- 2 steps

Find the total number of distinct ways to reach the top.

### Example

Input:

```text
n = 3
```

Output:

```text
3
```

Explanation:

The three possible ways are:

```text
1 + 1 + 1
1 + 2
2 + 1
```

---

## Intuition

To reach stair `n`, the last move can be:

1. From stair `n - 1` by taking 1 step.
2. From stair `n - 2` by taking 2 steps.

Therefore:

```text
ways(n) = ways(n - 1) + ways(n - 2)
```

This recurrence is similar to the Fibonacci sequence.

---

## Base Cases

For `n = 0`:

```text
ways(0) = 1
```

There is one way to reach the starting position: take no steps.

For `n = 1`:

```text
ways(1) = 1
```

There is only one way:

```text
1
```

---

# Approaches

## 1. Recursion

The recurrence is directly implemented using recursion.

```text
ways(n) = ways(n - 1) + ways(n - 2)
```

### Complexity

Time Complexity: `O(2^N)`

Space Complexity: `O(N)`

The recursive solution repeatedly calculates the same subproblems.

---

## 2. Memoization

Memoization stores the result of already calculated subproblems.

Before calculating a state, we check whether its answer is already present in the DP array.

### Complexity

Time Complexity: `O(N)`

Space Complexity: `O(N)`

- DP Array: `O(N)`
- Recursion Stack: `O(N)`

Memoization is also called **Top-Down Dynamic Programming**.

---

## 3. Tabulation

Tabulation solves the problem from the smallest subproblems to the final answer.

We start with:

```text
dp[0] = 1
dp[1] = 1
```

Then:

```text
dp[i] = dp[i - 1] + dp[i - 2]
```

### Complexity

Time Complexity: `O(N)`

Space Complexity: `O(N)`

Tabulation is also called **Bottom-Up Dynamic Programming**.

---

## 4. Space Optimization

To calculate the current state, we only need the previous two states.

Therefore, instead of maintaining an entire DP array, we use two variables:

```text
prev2
prev1
```

This reduces the space complexity.

### Complexity

Time Complexity: `O(N)`

Space Complexity: `O(1)`

---

# Complexity Comparison

| Approach | Time | Space |
|---|---:|---:|
| Recursion | O(2^N) | O(N) |
| Memoization | O(N) | O(N) |
| Tabulation | O(N) | O(N) |
| Space Optimization | O(N) | O(1) |

---

# Key Learnings

- Dynamic Programming can optimize repeated subproblems.
- Recursion is the simplest way to derive the solution.
- Memoization stores previously calculated results.
- Tabulation builds the solution iteratively.
- Space optimization removes unnecessary DP storage.
- Climbing Stairs follows the same recurrence as Fibonacci.

---

# DP Pattern

```text
Recursion
    ↓
Identify repeated subproblems
    ↓
Memoization
    ↓
Convert to Tabulation
    ↓
Optimize Space
```

---

## Conclusion

Climbing Stairs is a fundamental Dynamic Programming problem.

It demonstrates the complete progression:

```text
Recursive
   ↓
Memoization
   ↓
Tabulation
   ↓
Space Optimization
```

The final optimized solution runs in:

```text
Time Complexity  : O(N)
Space Complexity : O(1)
```