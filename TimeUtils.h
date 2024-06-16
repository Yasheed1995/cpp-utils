#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <chrono>

namespace TimeUtils {

class Timer {
public:
    Timer() : start_time_(std::chrono::high_resolution_clock::now()) {}

    void reset() {
        start_time_ = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const {
        return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start_time_).count();
    }

private:
    std::chrono::high_resolution_clock::time_point start_time_;
};

} // namespace TimeUtils

#endif // TIME_UTILS_H