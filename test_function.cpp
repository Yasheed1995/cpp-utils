#include "FileUtils.h"
#include "MathUtils.h"
#include "StringUtils.h"
#include "TimeUtils.h"
#include "GraphUtils.h"
#include "SearchingUtils.h"
#include "SortingUtils.h"
#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>

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
  std::this_thread::sleep_for(
      std::chrono::milliseconds(100)); // 使用 sleep_for 進行簡單的等待
  assert(timer.elapsed() >= 0.1); // 檢查計時器是否記錄了至少 0.1 秒
}


void test_sorting_utils() {
  std::vector<int> arr = {5, 2, 9, 1, 5, 6};
  SortingUtils::bubble_sort(arr);
  std::cout << "Bubble Sort: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  arr = {5, 2, 9, 1, 5, 6};
  SortingUtils::quick_sort(arr, 0, arr.size() - 1);
  std::cout << "Quick Sort: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

void test_searching_utils() {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int target = 5;
  int index = SearchingUtils::binary_search(arr, target);
  std::cout << "Binary Search: Found " << target << " at index " << index
            << std::endl;
}

void test_graph_utils() {
  GraphUtils::Graph graph = {{1, 2}, {0, 3, 4}, {0, 4},
                             {1, 5}, {1, 2, 5}, {3, 4}};

  std::vector<int> bfs_result = GraphUtils::bfs(graph, 0);
  std::cout << "BFS: ";
  for (int node : bfs_result) {
    std::cout << node << " ";
  }
  std::cout << std::endl;

  std::vector<int> dfs_result = GraphUtils::dfs(graph, 0);
  std::cout << "DFS: ";
  for (int node : dfs_result) {
    std::cout << node << " ";
  }
  std::cout << std::endl;
}

int main() {
  test_string_utils();
  test_math_utils();
  test_file_utils();
  test_time_utils();
  test_sorting_utils();
  test_searching_utils();
  test_graph_utils();
  std::cout << "All tests passed!" << std::endl;
  return 0;
}