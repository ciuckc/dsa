add_executable(${CMAKE_PROJECT_NAME}
  main.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(BinaryArray)
add_subdirectory(TopKElementsInList)
add_subdirectory(PriorityQueue)
add_subdirectory(Algorithm)
add_subdirectory(CreateNewCopyList)

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
  CreateNewCopyList
)
