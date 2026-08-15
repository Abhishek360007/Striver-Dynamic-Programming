# Maximum Sum of Non-Adjacent Elements | Dynamic Programming

## Problem Statement

Given an array of integers, find the maximum possible sum such that no two selected elements are adjacent.

### Example

Input:

```text
nums = [2, 1, 4, 9]
```

Output:

```text
11
```

Explanation:

The optimal selection is:

```text
2 + 9 = 11
```

The selected elements are not adjacent.

---

# Intuition

At every index, we have two choices:

1. Take the current element.
2. Do not take the current element.

If we take the current element, we cannot take the previous element.

Therefore:

```text
take = nums[i] + dp[i-2]
```

If we don't take the current element:

```text
notTake = dp[i-1]
```

So the recurrence is:

```text
dp[i] = max(take, notTake)
```

---

# DP State

Define:

```text
dp[i] = maximum sum that can be obtained
        from elements 0 to i
        without selecting adjacent elements.
```

---

# Recurrence

For every index `i`:

### Take

If we select `nums[i]`, we must skip `nums[i-1]`.

```text
take = nums[i] + dp[i-2]
```

### Not Take

If we don't select `nums[i]`:

```text
notTake = dp[i-1]
```

Therefore:

```text
dp[i] = max(take, notTake)
```

---

# Base Case

For the first element:

```text
dp[0] = nums[0]
```

Because there is only one element available.

---

# Approaches

## 1. Recursion

At every index, we make two choices:

```text
Take
Not Take
```

This creates overlapping subproblems.

### Complexity

Time Complexity:

```text
O(2^N)
```

Space Complexity:

```text
O(N)
```

---

## 2. Memoization

We store the result of each index in a DP array.

If a state has already been calculated, we reuse its result.

### Complexity

Time Complexity:

```text
O(N)
```

Space Complexity:

```text
O(N)
```

- DP Array: `O(N)`
- Recursion Stack: `O(N)`

Memoization is also called:

```text
Top-Down Dynamic Programming
```

---

## 3. Tabulation

We solve the problem iteratively from left to right.

For every index:

```text
dp[i] = max(
    nums[i] + dp[i-2],
    dp[i-1]
)
```

### Complexity

Time Complexity:

```text
O(N)
```

Space Complexity:

```text
O(N)
```

Tabulation is also called:

```text
Bottom-Up Dynamic Programming
```

---

## 4. Space Optimization

To calculate the current state, we only need:

```text
dp[i-1]
dp[i-2]
```

Therefore, we don't need the complete DP array.

We maintain:

```text
prev1 = dp[i-1]
prev2 = dp[i-2]
```

Then calculate:

```text
current = max(nums[i] + prev2, prev1)
```

### Complexity

Time Complexity:

```text
O(N)
```

Space Complexity:

```text
O(1)
```

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

- Every DP state can have a `Take` and `Not Take` choice.
- If we take the current element, we must skip the previous element.
- Memoization removes repeated calculations.
- Tabulation converts recursion into iteration.
- Only the previous two states are required for the optimized solution.
- This is an important example of the `Take / Not Take` DP pattern.

---

# DP Pattern

```text
                Current Element
                      |
             ┌────────┴────────┐
             ↓                 ↓
           TAKE             NOT TAKE
             |                 |
      nums[i] + dp[i-2]       dp[i-1]
             |                 |
             └────────┬────────┘
                      ↓
                    MAX
```

---

# Final Optimized Solution

```text
Time Complexity  : O(N)
Space Complexity : O(1)
```

---

## Conclusion

Maximum Sum of Non-Adjacent Elements introduces the important:

```text
Take / Not Take
```

Dynamic Programming pattern.

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

This pattern appears in many important DP problems, including variations of House Robber.