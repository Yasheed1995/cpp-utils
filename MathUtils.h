#ifndef MATH_UTILS_H
#define MATH_UTILS_H

namespace MathUtils {

// 計算最大公約數 (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 計算最小公倍數 (LCM)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// 判斷是否為素數
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

} // namespace MathUtils

#endif // MATH_UTILS_H