﻿# CMakeList.txt: проект CMake для 06; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("06")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (06 "main.cpp" "main.h" "Matrix.h" "Matrix.cpp" "LineOfMatrix.h" "LineOfMatrix.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 06 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.