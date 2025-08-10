cmake_minimum_required(VERSION 3.16)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
        "$<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Debug,RelWithDebInfo>>:EditAndContinue>"
        "$<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Debug,RelWithDebInfo>>:ProgramDatabase>"
    )
endif()

project(
    hw5
    VERSION 0.0.1
    DESCRIPTION "hw5"
    LANGUAGES CXX
)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем все исходники
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Создаем исполняемый файл (название совпадает с именем проекта)
add_executable(hw5 ${SOURCES})

# Включаем заголовочные файлы fmt
find_package(fmt REQUIRED)
target_link_libraries(hw5 PRIVATE fmt::fmt)

# Указываем include-директории
target_include_directories(hw5 PUBLIC "${PROJECT_SOURCE_DIR}/include")

# Тип сборки по умолчанию
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()