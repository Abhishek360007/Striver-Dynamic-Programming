#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci Number = " << fibonacci(n);

    return 0;
}


/*
Time Complexity : O(2^N)

Reason:
Each function call creates two more recursive calls.

Space Complexity : O(N)

Reason:
Recursive call stack.
*/