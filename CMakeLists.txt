cmake_minimum_required ( VERSION 3.31.6 )

message ( "Starting compiling vk_interface..." )

set ( CMAKE_CXX_STANDARD 23 )

project( vk_interface
	VERSION 0.0.1
	LANGUAGES CXX )

set ( LIBRARY_OUTPUT_PATH /home/eugene/FILES/Programming/Real\ Engine\ extended\ dev/Real\ Engine\ v0.0.0.1\ dev/bin/lib )# paste your project directory

find_package(Vulkan REQUIRED)
find_package(glfw3 3.4 REQUIRED)

include_directories( ../ )

add_library( ${PROJECT_NAME} SHARED run.cpp createInstance.cpp createSurface.cpp pickPhysicalDevice.cpp createLogicalDevice.cpp terminate.cpp vkUtils/vkUtils.cpp )
set_target_properties( ${PROJECT_NAME} PROPERTIES
	PREFIX ""
	OUTPUT_NAME "vk_interface"
	SUFFIX ".so"
)

add_library( vk::vk_interface ALIAS ${PROJECT_NAME} )
target_link_libraries( ${PROJECT_NAME} PRIVATE Vulkan::Vulkan )
target_link_libraries( ${PROJECT_NAME} PUBLIC glfw )


add_library( ${PROJECT_NAME}_static STATIC run.cpp createInstance.cpp createSurface.cpp pickPhysicalDevice.cpp createLogicalDevice.cpp terminate.cpp vkUtils/vkUtils.cpp )
set_target_properties( ${PROJECT_NAME}_static PROPERTIES
	PREFIX "static_"
	OUTPUT_NAME "vk_interface"
	SUFFIX ".a"
)
add_library( vk::static_vk_interface ALIAS ${PROJECT_NAME}_static )
target_link_libraries( ${PROJECT_NAME}_static PRIVATE Vulkan::Vulkan )
target_link_libraries( ${PROJECT_NAME}_static PUBLIC glfw )
