find_package(GTest REQUIRED)

add_executable(vector_tests
        main.cc
        intersection.cc
        vector_basics.cc
)

target_link_libraries(vector_tests PRIVATE
        vector_lib
        GTest::gtest_main
        Threads::Threads
)

target_include_directories(vector_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_test(NAME vector_tests COMMAND vector_tests)
