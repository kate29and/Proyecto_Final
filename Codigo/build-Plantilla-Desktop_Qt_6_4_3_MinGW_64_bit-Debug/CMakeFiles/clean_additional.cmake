# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Plantilla_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Plantilla_autogen.dir\\ParseCache.txt"
  "Plantilla_autogen"
  )
endif()
