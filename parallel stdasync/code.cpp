#include <iostream>
#include <future>

int compute_square(int x) {
    return x * x;
}

int main() {
    // Run compute_square asynchronously
    std::future<int> result = std::async(std::launch::async, compute_square, 5);

    // Program continues while the task runs
    std::cout << "Computing square in the background...\n";

    // Retrieve the result
    std::cout << "Result: " << result.get() << '\n';

    return 0;
}
#include <iostream>
#include <future>

int main() {
    // Use a lambda to calculate factorial asynchronously
    std::future<int> factorial = std::async(std::launch::async, [](int n) {
        int result = 1;
        for (int i = 1; i <= n; ++i) result *= i;
        return result;
    }, 5);

    std::cout << "Calculating factorial in the background...\n";

    // Retrieve the result
    std::cout << "Factorial of 5: " << factorial.get() << '\n';

    return 0;
}
#include <iostream>
#include <future>

int compute_square(int x) {
    std::cout << "Computing square now...\n";
    return x * x;
}

int main() {
    // Use deferred execution
    std::future<int> result = std::async(std::launch::deferred, compute_square, 7);

    std::cout << "Task is deferred. Result not computed yet.\n";

    // Trigger computation when needed
    std::cout << "Result: " << result.get() << '\n';

    return 0;
}
#include <iostream>
#include <future>

long long compute_sum(long long start, long long end) {
    long long sum = 0;
    for (long long i = start; i <= end; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    long long N = 1'000'000;

    // Divide the task into two parts and execute them asynchronously
    std::future<long long> first_half = std::async(std::launch::async, compute_sum, 1, N / 2);
    std::future<long long> second_half = std::async(std::launch::async, compute_sum, (N / 2) + 1, N);

    // Combine results from both tasks
    long long total_sum = first_half.get() + second_half.get();

    std::cout << "Sum of numbers from 1 to " << N << " is: " << total_sum << '\n';

    return 0;
}
