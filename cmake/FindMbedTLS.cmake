# - Try to find MbedTLS
# set(MBEDTLS_LIBRARY mbedtls)
# set(MBEDTLS_INCLUDE_DIRS ${MBEDTLS_SOURCE_DIR}/include)

Message( STATUS "MBEDTLS_PREFIX: ${MBEDTLS_PREFIX}")
Message( STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
Message( STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

find_path(MBEDTLS_INCLUDE_DIRS
    NAMES mbedtls/build_info.h psa/crypto.h
    HINTS ${MBEDTLS_PREFIX}/include/
        ${CMAKE_SOURCE_DIR}/../mbedtls/include/
        ${CMAKE_BINARY_DIR}/../mbedtls/include/
        ../mbedtls/include/ )

set(MBEDTLS_HINTS ${MBEDTLS_PREFIX}/build/library 
    ${CMAKE_BINARY_DIR}/../mbedtls/build/library
    ../mbedtls/build/library ../mbedtls/library)

find_library(MBEDTLS_LIBRARY mbedtls HINTS ${MBEDTLS_HINTS})
find_library(MBEDTLS_CRYPTO mbedcrypto HINTS ${MBEDTLS_HINTS})
find_library(MBEDTLS_X509 mbedx509 HINTS ${MBEDTLS_HINTS})
set(MBEDTLS_LIBRARIES  ${MBEDTLS_LIBRARY} ${MBEDTLS_X509} ${MBEDTLS_CRYPTO} )

mark_as_advanced(MBEDTLS_LIBRARY MBEDTLS_INCLUDE_DIRS)
