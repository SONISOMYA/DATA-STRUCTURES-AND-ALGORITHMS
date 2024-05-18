#include <iostream>
#include <ctime>

using namespace std;

// Function to multiply two 2x2 matrices and store the result in the first matrix
void multiply(long long F[2][2], long long M[2][2]) {
    long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

// Function to raise the matrix to the power of n using binary exponentiation
void power(long long F[2][2], int n) {
    if (n == 0 || n == 1)
        return;

    long long M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

// Function to calculate the nth Fibonacci number using matrix exponentiation
long long fibonacci(int n) {
    if (n == 0)
        return 0;
    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

int main() {
    int n = 10; // Starting Fibonacci index
    int iterations = 10; // Number of iterations

    cout << "Fibonacci Index, Time (s)\n";

    for (int i = 0; i < iterations; i++) {
        clock_t start, end;
        start = clock();
        long long result = fibonacci(n); // Calculate Fibonacci number
        end = clock();
        double time_taken = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        cout << n << ", " << time_taken << "\n";
        n *= 2; // Increase Fibonacci index
    }

    return 0;
}
