INCLUDE (FindPackageHandleStandardArgs)

FIND_PATH (JSONCPP_ROOT_DIR
        NAMES json/json.h include/json/json.h
        PATHS ENV JSONCPP_ROOT_DIR
        DOC "jsoncpp root directory")

# Re-use the previous path:
FIND_PATH (JSONCPP_INCLUDE_DIR
        NAMES json/json.h
        HINTS ${JSONCPP_ROOT_DIR}
        PATH_SUFFIXES include
        DOC "jsoncpp include directory")

# TUT
FIND_LIBRARY (JSONCPP_LIBRARY_RELEASE
        NAMES jsoncpp
        HINTS ${JSONCPP_ROOT_DIR}
        PATH_SUFFIXES lib
        DOC "jsoncpp release library")

IF (NOT DEFINED JSONCPP_LIBRARIES)
    IF (JSONCPP_LIBRARY_RELEASE)
        SET (JSONCPP_LIBRARY ${JSONCPP_LIBRARY_RELEASE} CACHE DOC
                "jsoncpp library")
    ENDIF (JSONCPP_LIBRARY_RELEASE)
ENDIF (NOT DEFINED JSONCPP_LIBRARIES)

message("jsoncpp include dir: ${JSONCPP_INCLUDE_DIR}")
IF (JSONCPP_INCLUDE_DIR)
    SET (_JSONCPP_VERSION_HEADER ${JSONCPP_INCLUDE_DIR}/json/version.h)

    IF (EXISTS ${_JSONCPP_VERSION_HEADER})
        message("jsoncpp version header: ${_JSONCPP_VERSION_HEADER}")
        FILE (STRINGS ${_JSONCPP_VERSION_HEADER} _JSONCPP_VERSION_TMP)


        STRING (REGEX REPLACE
                ".*define JSONCPP_VERSION_MAJOR[ \t]+([0-9\\.]+)(.*)" "\\1" JSONCPP_VERSION_MAJOR
                ${_JSONCPP_VERSION_TMP})

        STRING (REGEX REPLACE
                ".*define JSONCPP_VERSION_MINOR[ \t]+([0-9\\.]+)(.*)" "\\1" JSONCPP_VERSION_MINOR
                ${_JSONCPP_VERSION_TMP})

        STRING (REGEX REPLACE
                ".*define JSONCPP_VERSION_PATCH[ \t]+([0-9\\.]+)(.*)" "\\1" JSONCPP_VERSION_PATCH
                ${_JSONCPP_VERSION_TMP})

        SET (JSONCPP_VERSION_COUNT 3)
        SET (JSONCPP_VERSION
                ${JSONCPP_VERSION_MAJOR}.${JSONCPP_VERSION_MINOR}.${JSONCPP_VERSION_PATCH})
    ENDIF (EXISTS ${_JSONCPP_VERSION_HEADER})
ENDIF (JSONCPP_INCLUDE_DIR)

SET (JSONCPP_INCLUDE_DIRS ${JSONCPP_INCLUDE_DIR})
SET (JSONCPP_LIBRARIES ${JSONCPP_LIBRARY})

MARK_AS_ADVANCED (JSONCPP_ROOT_DIR JSONCPP_INCLUDE_DIR JSONCPP_LIBRARY
        JSONCPP_LIBRARY_DEBUG JSONCPP_LIBRARY_RELEASE)

FIND_PACKAGE_HANDLE_STANDARD_ARGS (jsoncpp REQUIRED_VARS JSONCPP_ROOT_DIR
        JSONCPP_INCLUDE_DIR JSONCPP_LIBRARY VERSION_VAR JSONCPP_VERSION)