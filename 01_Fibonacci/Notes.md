# Fibonacci | Dynamic Programming

## Problem

Find the nth Fibonacci number.

Example:

Input:
5

Output:
5

---

## Approaches

### 1. Recursion

Idea:
- Break the problem into smaller subproblems.
- Very easy to write.
- Calculates the same values many times.

Time Complexity:
O(2^N)

Space Complexity:
O(N)

---

### 2. Memoization (Top Down)

Idea:
- Store already calculated answers.
- Avoid repeated calculations.

Time Complexity:
O(N)

Space Complexity:
O(N)

---

### 3. Tabulation (Bottom Up)

Idea:
- Start from base cases.
- Build the answer iteratively.

Time Complexity:
O(N)

Space Complexity:
O(N)

---

### 4. Space Optimization

Idea:
- We only need the previous two Fibonacci values.
- No DP array required.

Time Complexity:
O(N)

Space Complexity:
O(1)

---

## Learning

✔ Recursion

✔ Overlapping Subproblems

✔ Memoization

✔ Tabulation

✔ Space Optimization

✔ Time-Space Tradeoff