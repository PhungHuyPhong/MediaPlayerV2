# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appMediaPlayerV2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appMediaPlayerV2_autogen.dir/ParseCache.txt"
  "QMLModules/CMakeFiles/QMLModules_autogen.dir/AutogenUsed.txt"
  "QMLModules/CMakeFiles/QMLModules_autogen.dir/ParseCache.txt"
  "QMLModules/CMakeFiles/QMLModulesplugin_autogen.dir/AutogenUsed.txt"
  "QMLModules/CMakeFiles/QMLModulesplugin_autogen.dir/ParseCache.txt"
  "QMLModules/CMakeFiles/QMLModulesplugin_init_autogen.dir/AutogenUsed.txt"
  "QMLModules/CMakeFiles/QMLModulesplugin_init_autogen.dir/ParseCache.txt"
  "QMLModules/QMLModules_autogen"
  "QMLModules/QMLModulesplugin_autogen"
  "QMLModules/QMLModulesplugin_init_autogen"
  "appMediaPlayerV2_autogen"
  )
endif()
