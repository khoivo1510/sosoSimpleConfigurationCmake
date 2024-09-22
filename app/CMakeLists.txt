set(APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cc")

add_executable(${EXECUTABLE_NAME} ${APP_SOURCES})

target_include_directories(${EXECUTABLE_NAME} PUBLIC ${CMAKE_BINARY_DIR}/configured_files/include/)
