# CMakeList.txt : CMake project for Chapter4, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Look for boost installation
find_package(Boost 1.65 COMPONENTS filesystem iostreams)
find_package(Threads REQUIRED)

if(Boost_FOUND)
	add_executable (mapreduce_primecheck "Exercise23.cpp")
	target_include_directories (mapreduce_primecheck PUBLIC mapreduce/include ${Boost_INCLUDE_DIRS})
	set_property (TARGET mapreduce_primecheck PROPERTY CXX_STANDARD 14)
	target_link_libraries (mapreduce_primecheck Boost::filesystem Boost::iostreams Threads::Threads)
else()
	message("Boost libraries not found! Please install them and try to build again")
endif()
