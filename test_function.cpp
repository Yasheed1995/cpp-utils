#include "StringUtils.h"
#include "MathUtils.h"
#include "FileUtils.h"
#include "TimeUtils.h"
#include <cassert>
#include <iostream>
#include <thread>
#include <chrono>

void test_string_utils() {
    using namespace StringUtils;
    bool result;

    result = (split("a,b,c", ',') == std::vector<std::string>{"a", "b", "c"});
    assert(result);

    result = (trim("  hello  ") == "hello");
    assert(result);

    result = (to_lower("HELLO") == "hello");
    assert(result);

    result = (to_upper("hello") == "HELLO");
    assert(result);
}

void test_math_utils() {
    using namespace MathUtils;
    assert(gcd(12, 15) == 3);
    assert(lcm(12, 15) == 60);
    assert(is_prime(5) == true);
    assert(is_prime(4) == false);
}

void test_file_utils() {
    using namespace FileUtils;
    const std::string test_file = "test.txt";
    write_file(test_file, "Hello, World!");
    assert(read_file(test_file) == "Hello, World!");
}

void test_time_utils() {
    using namespace TimeUtils;
    Timer timer;
    timer.reset();
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 使用 sleep_for 進行簡單的等待
    assert(timer.elapsed() >= 0.1); // 檢查計時器是否記錄了至少 0.1 秒
}

int main() {
    test_string_utils();
    test_math_utils();
    test_file_utils();
    test_time_utils();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}