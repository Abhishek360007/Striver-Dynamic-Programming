# Frog Jump | Dynamic Programming

## Problem Statement

There are `N` stairs.

A frog starts at the first stair and wants to reach the last stair.

The frog can jump:

- 1 stair at a time
- 2 stairs at a time

The energy required for a jump from stair `i` to stair `j` is:

```text
abs(heights[i] - heights[j])
```

Find the minimum amount of energy required for the frog to reach the last stair.

---

## Example

Input:

```text
N = 4

Heights = [10, 20, 30, 10]
```

Output:

```text
20
```

### Explanation

One optimal path is:

```text
10 → 20 → 10
```

Energy:

```text
|10 - 20| + |20 - 10|

= 10 + 10

= 20
```

Therefore:

```text
Minimum Energy = 20
```

---

# Intuition

To reach stair `i`, the frog can come from:

1. Stair `i - 1`
2. Stair `i - 2`

Therefore, we calculate the minimum energy for both possibilities.

### One-step jump

```text
dp[i - 1] + abs(heights[i] - heights[i - 1])
```

### Two-step jump

```text
dp[i - 2] + abs(heights[i] - heights[i - 2])
```

Therefore:

```text
dp[i] = min(oneStep, twoStep)
```

---

# Base Case

At the first stair, no energy is required.

Therefore:

```text
dp[0] = 0
```

---

# Approaches

## 1. Recursion

We recursively calculate the minimum energy required to reach the current stair.

At every stair, we consider:

```text
One-step jump
Two-step jump
```

and take the minimum.

### Complexity

Time Complexity: `O(2^N)`

Space Complexity: `O(N)`

The recursion repeatedly solves the same subproblems.

---

## 2. Memoization

The recursive solution contains overlapping subproblems.

We store the answer for every index in a DP array.

Before calculating a state, we check whether it has already been calculated.

### Complexity

Time Complexity: `O(N)`

Space Complexity: `O(N)`

- DP Array: `O(N)`
- Recursion Stack: `O(N)`

This is Top-Down Dynamic Programming.

---

## 3. Tabulation

Instead of recursion, we solve the problem from the first stair toward the last stair.

We initialize:

```text
dp[0] = 0
```

Then calculate every state iteratively.

For every stair:

```text
oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1])

twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2])
```

Finally:

```text
dp[i] = min(oneStep, twoStep)
```

### Complexity

Time Complexity: `O(N)`

Space Complexity: `O(N)`

This is Bottom-Up Dynamic Programming.

---

## 4. Space Optimization

To calculate `dp[i]`, we only need:

```text
dp[i - 1]
dp[i - 2]
```

Therefore, we don't need the complete DP array.

We maintain only two variables:

```text
prev1 = dp[i - 1]
prev2 = dp[i - 2]
```

This reduces the space complexity.

### Complexity

Time Complexity: `O(N)`

Space Complexity: `O(1)`

---

# Complexity Comparison

| Approach | Time Complexity | Space Complexity |
|---|---:|---:|
| Recursion | O(2^N) | O(N) |
| Memoization | O(N) | O(N) |
| Tabulation | O(N) | O(N) |
| Space Optimization | O(N) | O(1) |

---

# Key Learnings

- A DP state represents the minimum energy required to reach a particular stair.
- Each state depends on the previous one or two states.
- Recursion helps derive the recurrence.
- Memoization removes repeated calculations.
- Tabulation removes recursion.
- Space optimization reduces the DP array to two variables.
- The `min()` function is used because we need the minimum energy path.

---

# DP Pattern

```text
Current State
     |
     ↓
Can come from i-1 or i-2
     |
     ↓
Calculate both costs
     |
     ↓
Take minimum
     |
     ↓
Store / optimize previous states
```

---

## Final Optimized Solution

```text
Time Complexity  : O(N)
Space Complexity : O(1)
```

---

## Conclusion

Frog Jump introduces an important DP pattern:

```text
dp[i] = minimum cost to reach state i
```

The problem can be progressively optimized:

```text
Recursion
    ↓
Memoization
    ↓
Tabulation
    ↓
Space Optimization
```

This pattern will be useful in many future Dynamic Programming problems.