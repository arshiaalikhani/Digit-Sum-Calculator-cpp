#include <iostream>

/**
 * Counts the number of digits in a given non-negative integer.
 *
 * @param number The number whose digits are to be counted.
 * @return The total digit count.
 */
int countDigits(int number) {
    int count = 0;
    while (number > 0) {
        count++;
        number /= 10;
    }
    return count;
}

/**
 * Calculates the place value divisor needed to extract the
 * leftmost digit of a number with the given digit count.
 * Example: a 3-digit number requires a divisor of 100.
 *
 * @param digitCount The total number of digits in the target number.
 * @return The divisor corresponding to the highest place value.
 */
int calculateDivisor(int digitCount) {
    int divisor = 1;
    for (int i = 1; i < digitCount; i++) {
        divisor *= 10;
    }
    return divisor;
}

/**
 * Prints each digit of the number from left to right and
 * accumulates their sum.
 *
 * @param number  The number to process.
 * @param divisor The initial place-value divisor (from calculateDivisor).
 * @return The sum of all digits.
 */
int printDigitsAndSum(int number, int divisor) {
    int sum = 0;
    std::cout << "Digits from left to right:\n";
    while (divisor > 0) {
        int digit = number / divisor;
        std::cout << digit << " " << std::endl;
        sum += digit;
        number %= divisor;
        divisor /= 10;
    }
    return sum;
}

int main() {
    int number;
    std::cout << "Please enter a number: ";
    std::cin >> number;

    // Handle the edge case where the input is zero
    if (number == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    int digitCount = countDigits(number);
    int divisor = calculateDivisor(digitCount);
    int sum = printDigitsAndSum(number, divisor);

    std::cout << "The sum of the digits is: " << sum << std::endl;
    return 0;
}
