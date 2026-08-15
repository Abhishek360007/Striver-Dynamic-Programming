# Frog Jump with K Distance | Dynamic Programming

## Problem Statement

There are `N` stairs.

A frog starts at the first stair and wants to reach the last stair.

The frog can jump a maximum of `K` stairs at a time.

In other words, from stair `i`, the frog can jump:

```text
1 stair
2 stairs
3 stairs
...
K stairs
```

The energy required to jump from stair `i` to stair `j` is:

```text
abs(heights[i] - heights[j])
```

Find the minimum energy required to reach the last stair.

---

## Example

Input:

```text
N = 5
K = 2

Heights = [10, 20, 30, 10, 20]
```

The frog can jump either 1 or 2 stairs.

The goal is to find the path with the minimum total energy.

---

# Intuition

For the normal Frog Jump problem, the frog could jump only:

```text
1 stair
2 stairs
```

Now the frog can jump up to `K` stairs.

Therefore, to reach stair `i`, we try every possible previous stair:

```text
i - 1
i - 2
i - 3
...
i - K
```

For every possible jump, we calculate:

```text
previous energy + jump energy
```

and choose the minimum.

---

# DP State

Define:

```text
dp[i] = minimum energy required to reach stair i
```

To calculate `dp[i]`, we try all possible jumps from `1` to `K`.

The transition is:

```text
dp[i] =
min(
    dp[i-jump] + abs(heights[i] - heights[i-jump])
)
```

where:

```text
1 <= jump <= K
```

and:

```text
i - jump >= 0
```

---

# Base Case

The frog starts at stair `0`.

No energy is required to start there.

Therefore:

```text
dp[0] = 0
```

---

# Approaches

## 1. Recursion

We recursively try every possible jump from `1` to `K`.

For each jump, we calculate the required energy and take the minimum.

### Complexity

Time Complexity:

```text
O(K^N)
```

Space Complexity:

```text
O(N)
```

The recursion tree grows rapidly because the same subproblems are calculated repeatedly.

---

## 2. Memoization

The recursive solution has overlapping subproblems.

We store the result of every calculated index in a DP array.

Before calculating a state, we check whether it has already been calculated.

### Complexity

Time Complexity:

```text
O(N * K)
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

Instead of recursion, we solve the problem iteratively.

We start with:

```text
dp[0] = 0
```

Then for every stair `i`, we try all possible jumps:

```text
1 to K
```

For each jump:

```text
energy =
dp[i-jump] + abs(heights[i] - heights[i-jump])
```

Then:

```text
dp[i] = minimum energy
```

### Complexity

Time Complexity:

```text
O(N * K)
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

In the normal Frog Jump problem, the frog can jump only 1 or 2 stairs.

Therefore, only two previous DP values are required.

However, in the K-distance version, the current state may depend on the previous `K` states:

```text
dp[i-1]
dp[i-2]
dp[i-3]
...
dp[i-K]
```

Therefore, we cannot generally reduce the space to `O(1)` using only two variables.

The straightforward DP implementation uses:

```text
O(N)
```

space.

### Complexity

Time Complexity:

```text
O(N * K)
```

Space Complexity:

```text
O(N)
```

---

# Complexity Comparison

| Approach | Time Complexity | Space Complexity |
|---|---:|---:|
| Recursion | O(K^N) | O(N) |
| Memoization | O(N × K) | O(N) |
| Tabulation | O(N × K) | O(N) |
| DP Array Approach | O(N × K) | O(N) |

---

# Key Learnings

- The DP state represents the minimum energy required to reach a particular stair.
- From each stair, we can try up to `K` possible jumps.
- Recursion helps derive the DP transition.
- Memoization removes repeated calculations.
- Tabulation removes recursion.
- The time complexity becomes `O(N × K)` after applying Dynamic Programming.
- Unlike the normal Frog Jump problem, the general K-distance problem cannot be reduced to just two variables.
- This problem teaches how the number of possible previous states affects DP optimization.

---

# DP Pattern

```text
Current Stair
      |
      ↓
Try jumps from 1 to K
      |
      ↓
Calculate energy for each jump
      |
      ↓
Take minimum
      |
      ↓
Store result in dp[i]
```

---

# Final Takeaway

The main idea is:

```text
dp[i] = minimum energy required to reach stair i
```

And for every stair:

```text
dp[i] =
min(
    dp[i-jump] + jumpCost
)
```

for:

```text
1 <= jump <= K
```

This extends the normal Frog Jump problem into a more general Dynamic Programming pattern.