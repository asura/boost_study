# C++規格
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(third_party/Catch2)

add_executable(
  Tester_cpp11
  Tester.cpp
  functionTest.cpp
)

target_link_libraries(
  Tester_cpp11
  Catch2::Catch2
)
