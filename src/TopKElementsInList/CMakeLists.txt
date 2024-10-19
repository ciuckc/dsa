target_sources(
  ${CMAKE_PROJECT_NAME}
    PUBLIC
  TopKElementsInList.hpp
    PRIVATE
  TopKElementsInList.cpp
)

#set_source_files_properties(
#  TopKElementsInList.cpp
#    PROPERTIES 
#      COMPILE_OPTIONS
#        "-Wall; -Werror; -Wextra" 
#)