add_executable(${CMAKE_PROJECT_NAME}
  main.cpp)

add_subdirectory(BinaryArray)
add_subdirectory(TopKElementsInList)
add_subdirectory(PriorityQueue)
add_subdirectory(Algorithm)

target_compile_options(
  ${CMAKE_PROJECT_NAME}
  PUBLIC -Wall -Werror -Wextra -Wconversion
)

target_include_directories(
  ${CMAKE_PROJECT_NAME}
  PRIVATE
  BinaryArray
  TopKElementsInList
  Algorithm
  PriorityQueue
)
