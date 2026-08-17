# House Robber | Dynamic Programming

## Problem Statement

You are a professional robber planning to rob houses along a street.

Each house contains a certain amount of money.

However, two adjacent houses cannot be robbed on the same night.

Given an array `nums`, where:

```text
nums[i] = money available in house i
```

Find the maximum amount of money that can be robbed.

---

## Example

Input:

```text
nums = [2, 7, 9, 3, 1]
```

Output:

```text
12
```

### Explanation

Rob house:

```text
2 + 9 + 1 = 12
```

We cannot rob adjacent houses.

Therefore:

```text
Maximum Money = 12
```

---

# Intuition

At every house, we have two choices:

1. Rob the current house.
2. Skip the current house.

If we rob the current house, we cannot rob the previous house.

Therefore:

```text
take = nums[i] + dp[i-2]
```

If we skip the current house:

```text
notTake = dp[i-1]
```

Therefore:

```text
dp[i] = max(take, notTake)
```

---

# DP State

Define:

```text
dp[i] = maximum amount of money that can be robbed
        from houses 0 to i.
```

---

# Recurrence

For every house:

### Take

If we rob house `i`:

```text
take = nums[i] + dp[i-2]
```

### Not Take

If we don't rob house `i`:

```text
notTake = dp[i-1]
```

Therefore:

```text
dp[i] = max(take, notTake)
```

---

# Base Case

For the first house:

```text
dp[0] = nums[0]
```

There is only one house, so we simply rob it.

---

# Approaches

## 1. Recursion

At every house we make two choices:

```text
Rob
Skip
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

We store the answer for every index.

If the result for an index has already been calculated, we reuse it.

### Complexity

Time Complexity:

```text
O(N)
```

Space Complexity:

```text
O(N)
```

- DP Array: O(N)
- Recursion Stack: O(N)

This is Top-Down Dynamic Programming.

---

## 3. Tabulation

We solve the problem iteratively.

Initialize:

```text
dp[0] = nums[0]
```

For every house:

```text
take = nums[i] + dp[i-2]

notTake = dp[i-1]

dp[i] = max(take, notTake)
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

This is Bottom-Up Dynamic Programming.

---

## 4. Space Optimization

To calculate the current state, we only need:

```text
dp[i-1]
dp[i-2]
```

Therefore, we don't need the entire DP array.

We maintain:

```text
prev1 = dp[i-1]
prev2 = dp[i-2]
```

Then:

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

- House Robber follows the Take / Not Take DP pattern.
- Robbing a house means skipping the adjacent previous house.
- Skipping a house means keeping the previous maximum.
- Memoization removes repeated recursive calculations.
- Tabulation solves states iteratively.
- Space can be optimized because only the previous two states are needed.
- The optimized solution runs in O(N) time and O(1) space.

---

# DP Pattern

```text
                 Current House
                       |
                ┌──────┴──────┐
                ↓             ↓
              ROB           SKIP
                ↓             ↓
       nums[i] + dp[i-2]     dp[i-1]
                \             /
                 \           /
                    MAX
```

---

# Relation With Day 5

House Robber is essentially a real-world version of:

```text
Maximum Sum of Non-Adjacent Elements
```

Day 5:

```text
[2, 1, 4, 9]
```

Day 6:

```text
Houses containing money
```

The DP logic is the same:

```text
Take current
OR
Skip current
```

---

# Final Optimized Solution

```text
Time Complexity  : O(N)
Space Complexity : O(1)
```

---

## Conclusion

House Robber reinforces the important:

```text
Take / Not Take
```

Dynamic Programming pattern.

The progression is:

```text
Recursion
    ↓
Memoization
    ↓
Tabulation
    ↓
Space Optimization
```

This pattern is extremely useful for solving many sequence and array-based DP problems.