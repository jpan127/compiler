

set(command "C:/Program Files/CMake/bin/cmake.exe;-DCMAKE_SH=CMAKE_SH-NOTFOUND;-DCMAKE_BUILD_TYPE=Release;-DANTLR4CPP_JAR_LOCATION=C:/Users/JP/Desktop/compiler/antlr/antlr4-4.7.2-SNAPSHOT-complete.jar;-DBUILD_SHARED_LIBS=ON;-BUILD_TESTS=OFF;-DCMAKE_INSTALL_PREFIX:PATH=C:/Users/JP/Desktop/compiler/antlr/externals/antlr4cpp;-DCMAKE_SOURCE_DIR:PATH=C:/Users/JP/Desktop/compiler/antlr/externals/antlr4cpp/src/antlr4cpp/runtime/Cpp;C:/Users/JP/Desktop/compiler/antlr/externals/antlr4cpp/src/antlr4cpp/runtime/Cpp")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "C:/Users/JP/Desktop/compiler/antlr/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-out.log"
  ERROR_FILE "C:/Users/JP/Desktop/compiler/antlr/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  C:/Users/JP/Desktop/compiler/antlr/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "antlr4cpp configure command succeeded.  See also C:/Users/JP/Desktop/compiler/antlr/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-*.log")
  message(STATUS "${msg}")
endif()
