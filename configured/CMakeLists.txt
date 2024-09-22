# Read the JSON file.
file(READ ${CMAKE_CURRENT_SOURCE_DIR}/${APPLICATION_CONFIG_FILE}.json JSON_STRING)

sbeParseJson(config JSON_STRING)

# Now you can use parsed variables.
foreach(var ${config})
    message("${var} = ${${var}}")
    set("${var}" "${${var}}" CACHE STRING "Variable from application.json" FORCE)
endforeach()

# When you are done, clean parsed variables
sbeClearJson(config)

configure_file(
    "config.h.in" "${CMAKE_BINARY_DIR}/configured_files/include/config.h.tmp"
    ESCAPE_QUOTES)

execute_process(
    COMMAND
    ${CMAKE_COMMAND} -E compare_files
        ${CMAKE_BINARY_DIR}/configured_files/include/config.h.tmp
        ${CMAKE_BINARY_DIR}/configured_files/include/config.h
    RESULT_VARIABLE
        CONFIG_NEED_CHANGE

    OUTPUT_QUIET
    ERROR_QUIET
)

if(CONFIG_NEED_CHANGE)
    execute_process(
        COMMAND
        ${CMAKE_COMMAND} -E copy
            ${CMAKE_BINARY_DIR}/configured_files/include/config.h.tmp
            ${CMAKE_BINARY_DIR}/configured_files/include/config.h
    )
endif()
