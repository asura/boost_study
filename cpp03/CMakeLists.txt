# C++規格
set(CMAKE_CXX_STANDARD 98)

include_directories(
 ${PROJECT_SOURCE_DIR}/cpp03/third_party/Catch2/single_include
)

add_executable(
  Tester_cpp03
  Tester.cpp
  functionTest.cpp
)
