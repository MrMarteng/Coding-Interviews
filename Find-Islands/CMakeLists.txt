cmake_minimum_required(VERSION 3.23)

# set the project name
project(FindIsland)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories("./_deps/googletest-src/googletest/include/gtest/")

# add the executable
add_executable(FindIsland.bin main.cpp findIsland.cpp)
target_link_libraries(FindIsland.bin gtest_main)
add_test(NAME Test COMMAND FindIsland.bin)