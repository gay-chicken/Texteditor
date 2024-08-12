# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Texteditor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Texteditor_autogen.dir\\ParseCache.txt"
  "Texteditor_autogen"
  )
endif()
