find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(${TEST} ${TEST_SRC} ${LIB_SRC} ${LIB_SRC})
target_link_libraries(${TEST} ${EXTERNAL_LIBS} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(boostUnitTestsRun ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST})

if (CMAKE_CONFIGURATION_TYPES)
    add_custom_target(${CHECK} COMMAND ${CMAKE_CTEST_COMMAND}
            --force-new-ctest-process --output-on-failure
            --build-config "$<CONFIGURATION>"
            DEPENDS ${TEST})
else ()
    add_custom_target(${CHECK} COMMAND ${CMAKE_CTEST_COMMAND}
            --force-new-ctest-process --output-on-failure
            DEPENDS ${TEST})
endif ()