
# ###########################################################################
# User specific settings
# ###########################################################################
include("${AREG_BASE}/areg/CMakeLists.txt")
include("${AREG_BASE}/extend/CMakeLists.txt")
include("${AREG_BASE}/mcrouter/CMakeLists.txt")
include("${AREG_BASE}/logger/CMakeLists.txt")
include("${AREG_BASE}/logobserver/CMakeLists.txt")

# build areg library
if(AREG_BINARY MATCHES "shared")
    # Shared Library
    add_library(areg SHARED ${areg_SRC})
    target_compile_definitions(areg PRIVATE EXP_AREG_DLL _USRDLL)
    if (NOT ${AREG_DEVELOP_ENV} MATCHES "Win32")
        target_compile_options(areg PRIVATE "-Bdynamic")
    endif()
    set_property(TARGET areg PROPERTY LIBRARY_OUTPUT_DIRECTORY ${AREG_OUTPUT_BIN})

else(AREG_BINARY MATCHES "shared")

    # Static Library
    add_library(areg STATIC ${areg_SRC})
    target_compile_definitions(areg PRIVATE EXP_AREG_LIB _LIB)
    if (NOT ${AREG_DEVELOP_ENV} MATCHES "Win32")
        target_compile_options(areg PRIVATE "-Bstatic")
    endif()
    set_property(TARGET areg PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${AREG_OUTPUT_LIB})

endif()

if (NOT ${AREG_DEVELOP_ENV} MATCHES "Win32")
    target_compile_options(areg PRIVATE -fPIC)
endif()

# Linker options
target_link_libraries(areg PRIVATE ${AREG_LDFLAGS})

# Library configuration
set_target_properties(areg PROPERTIES CXX_STANDARD ${AREG_CXX_STANDARD} CXX_STANDARD_REQUIRED ON )

# build areg extended static library
addStaticLib(areg-extend "${extend_SRC}")

# build log observer API library
if (AREG_LOGOBSERVER_LIB MATCHES "shared")

    # build log observer API shared library
    addSharedLib(logobserverapi "${logobserverapi_SRC}")

    if (NOT ${AREG_DEVELOP_ENV} MATCHES "Win32")
        target_compile_options(logobserverapi PRIVATE -fPIC)
    endif()

    # log observer API shared library
    target_compile_definitions(logobserverapi PRIVATE EXP_LOGOBSERVER_DLL)

    # add MSVC linker option
    if (MSVC)
        target_link_options(logobserverapi PRIVATE "/DEF:${logobserverapi_RESOURCE}/logobserver.def")
    endif()

else(AREG_LOGOBSERVER_LIB MATCHES "shared")
    # build log observer API static library
    addStaticLib(logobserverapi "${logobserverapi_SRC}")

    if (NOT ${AREG_DEVELOP_ENV} MATCHES "Win32")
        target_compile_options(logobserverapi PRIVATE -fPIC)
    endif()
    # log observer API static library
    target_compile_definitions(logobserverapi PRIVATE EXP_LOGOBSERVER_LIB)

endif(AREG_LOGOBSERVER_LIB MATCHES "shared")

# build mcrouter executable
addExecutable(mcrouter "${mcrouter_SRC}")

# build logger executable
addExecutable(logger "${logger_SRC}")

# build log observer console application
addExecutableEx(logobserver "${logobserverapp_SRC}" logobserverapi)
if (AREG_LOGOBSERVER_LIB MATCHES "shared")
    target_compile_definitions(logobserver PRIVATE IMP_LOGOBSERVER_DLL)
else(AREG_LOGOBSERVER_LIB MATCHES "shared")
    target_compile_definitions(logobserver PRIVATE IMP_LOGOBSERVER_LIB)
endif(AREG_LOGOBSERVER_LIB MATCHES "shared")

# copying log and router init files to 'bin/config'
file(MAKE_DIRECTORY ${AREG_OUTPUT_BIN}/config)
file(COPY ${AREG_BASE}/areg/resources/areg.init DESTINATION ${AREG_OUTPUT_BIN}/config)

if("${AREG_DEVELOP_ENV}" STREQUAL "Win32")
    add_custom_command(TARGET mcrouter
                       POST_BUILD
                       COMMAND cmd /c "${mcrouter_RESOURCE}/mcrouter_post_build.bat" "${mcrouter_RESOURCE}" "${AREG_OUTPUT_BIN}")

    add_custom_command(TARGET logger
                       POST_BUILD
                       COMMAND cmd /c "${logger_RESOURCE}/logger_post_build.bat" "${logger_RESOURCE}" "${AREG_OUTPUT_BIN}")
endif()
