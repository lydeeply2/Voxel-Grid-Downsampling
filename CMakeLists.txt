# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(pcd_filter)

# 设置 Boost 查找新策略（CMP0167）
if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

# 查找 Boost（filesystem, system）
find_package(Boost 1.71 REQUIRED COMPONENTS filesystem system)

# 查找 PCL，并确保包含 io, io_stl, common, surface 以及 filters
find_package(PCL 1.10 REQUIRED COMPONENTS common io io_stl surface filters)

# 查找 Assimp
find_package(Assimp REQUIRED)

# 包含头文件目录
include_directories(
    ${PCL_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    ${ASSIMP_INCLUDE_DIRS}
)

# 编译期定义（PCL 可能会提供一些宏）
add_definitions(${PCL_DEFINITIONS})

# 指定源文件并生成可执行文件
add_executable(voxelgrid src/voxelgrid.cpp)

# 链接库：PCL、Assimp、Boost
target_link_libraries(voxelgrid
    ${PCL_LIBRARIES}
    ${ASSIMP_LIBRARIES}
    ${Boost_LIBRARIES}
)
