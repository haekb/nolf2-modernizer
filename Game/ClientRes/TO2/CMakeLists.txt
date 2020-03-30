project(ClientRes CXX)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "../Shared/ClientResShared.h"
    "ClientRes.h"
    "main.cpp"
    #"resource.h"
)
source_group("" FILES ${no_group_source_files})

set(Localized_Files__DE
    "Lang/DE/credits.txt"
    "Lang/DE/intro.txt"
    "Lang/DE/ClientRes.rc"
)
source_group("Localized Files\\DE" FILES ${Localized_Files__DE})

set(Localized_Files__EN
    "Lang/EN/credits.txt"
    "Lang/EN/intro.txt"
    "Lang/EN/ClientRes.rc"
)
source_group("Localized Files\\EN" FILES ${Localized_Files__EN})

set(Localized_Files__ES
    "Lang/ES/credits.txt"
    "Lang/ES/intro.txt"
    "Lang/ES/ClientRes.rc"
)
source_group("Localized Files\\ES" FILES ${Localized_Files__ES})

set(Localized_Files__FR
    "Lang/FR/credits.txt"
    "Lang/FR/intro.txt"
    "Lang/FR/ClientRes.rc"
)
source_group("Localized Files\\FR" FILES ${Localized_Files__FR})

set(Localized_Files__IT
    "Lang/IT/credits.txt"
    "Lang/IT/intro.txt"
    "Lang/IT/ClientRes.rc"
)
source_group("Localized Files\\IT" FILES ${Localized_Files__IT})

set(ALL_FILES
    ${no_group_source_files}
    ${Localized_Files__DE}
    ${Localized_Files__EN}
    ${Localized_Files__ES}
    ${Localized_Files__FR}
    ${Localized_Files__IT}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG         "CRes"
    TARGET_NAME_DEBUGMFCDLL   "CRes"
    TARGET_NAME_FINAL         "CRes"
    TARGET_NAME_FINALDE       "CRes"
    TARGET_NAME_FINALES       "CRes"
    TARGET_NAME_FINALFR       "CRes"
    TARGET_NAME_FINALIT       "CRes"
    TARGET_NAME_RELEASE       "CRes"
    TARGET_NAME_RELEASEMFCDLL "CRes"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/../../built/debug/ClientRes/TO2"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../built/debug/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/FinalDE/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/FinalES/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/FinalFR/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/FinalIT/ClientRes/TO2"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Release/ClientRes/TO2"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Release/ClientRes/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/debug/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/debug/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/Final/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/FinalDE/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/FinalES/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/FinalFR/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/FinalIT/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/Release/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/Release/ClientRes/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_NAME_DEBUG         "CRes"
    ARCHIVE_OUTPUT_NAME_DEBUGMFCDLL   "CRes"
    ARCHIVE_OUTPUT_NAME_FINAL         "CRes"
    ARCHIVE_OUTPUT_NAME_FINALDE       "CRes"
    ARCHIVE_OUTPUT_NAME_FINALES       "CRes"
    ARCHIVE_OUTPUT_NAME_FINALFR       "CRes"
    ARCHIVE_OUTPUT_NAME_FINALIT       "CRes"
    ARCHIVE_OUTPUT_NAME_RELEASE       "CRes"
    ARCHIVE_OUTPUT_NAME_RELEASEMFCDLL "CRes"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/DE"
    ">"
    "$<$<CONFIG:FinalES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/ES"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/FR"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/IT"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN"
    ">"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "WIN32;"
        "_DEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "WIN32;"
        "_DEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:Final>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalES>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Release>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS"
    ">"
)

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /Gm;
            /Od;
            /MDd;
            /Gy;
            /W3
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Gm;
            /Od;
            /MDd;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalMFCDLL>:
            ${DEFAULT_CXX_RUNTIME_LIBRARY}
        >
        $<$<CONFIG:Release>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:ReleaseMFCDLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:Template>:
            ${DEFAULT_CXX_RUNTIME_LIBRARY}
        >
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:DebugMFCDLL>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Final>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalDE>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalES>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalFR>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalIT>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalMFCDLL>:
            /DEBUG:FULL
        >
        $<$<CONFIG:Release>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:ReleaseMFCDLL>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Template>:
            /DEBUG:FULL
        >
    )
endif()

################################################################################
# Post build events
################################################################################
add_custom_command_if(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMANDS
    COMMAND         $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    COMMAND   $<CONFIG:DebugMFCDLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
)

################################################################################
# Dependencies
################################################################################
set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "$<$<CONFIG:Debug>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalES>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Release>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "odbc32;"
        "odbccp32"
    ">"
)
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

