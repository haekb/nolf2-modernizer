project(ClientRes CXX)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "../Shared/ClientResShared.h"
    "ClientRes.h"
    "main.cpp"
    "resource.h"
)
source_group("" FILES ${no_group_source_files})

set(Localized_Files__DE
#    "Lang/DE/credits.txt"
#    "Lang/DE/intro.txt"
)
source_group("Localized Files\\DE" FILES ${Localized_Files__DE})

set(Localized_Files__EN
#    "Lang/EN/credits.txt"
#    "Lang/EN/intro.txt"
)
source_group("Localized Files\\EN" FILES ${Localized_Files__EN})

set(Localized_Files__ES
#    "Lang/ES/credits.txt"
#    "Lang/ES/intro.txt"
)
source_group("Localized Files\\ES" FILES ${Localized_Files__ES})

set(Localized_Files__FR
#    "Lang/FR/credits.txt"
#    "Lang/FR/intro.txt"
)
source_group("Localized Files\\FR" FILES ${Localized_Files__FR})

set(Localized_Files__IT
#    "Lang/IT/credits.txt"
#    "Lang/IT/intro.txt"
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
    TARGET_NAME_DEBUG MFC DLL   "CRes"
    TARGET_NAME_DEBUG           "CRes"
    TARGET_NAME_FINAL DE        "CRes"
    TARGET_NAME_FINAL ES        "CRes"
    TARGET_NAME_FINAL FR        "CRes"
    TARGET_NAME_FINAL IT        "CRes"
    TARGET_NAME_FINAL MFC DLL   "CRes"
    TARGET_NAME_FINAL           "CRes"
    TARGET_NAME_RELEASE MFC DLL "CRes"
    TARGET_NAME_RELEASE         "CRes"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../built/debug/ClientRes/TO2"
    OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../built/debug/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../../built/FinalDE/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../../built/FinalES/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../../built/FinalFR/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../../built/FinalIT/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../built/FinalES/ClientRes/TO2"
    OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/ClientRes/TO2"
    OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Release/ClientRes/TO2"
    OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Release/ClientRes/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/debug/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/debug/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/FinalDE/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/FinalES/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/FinalFR/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/FinalIT/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/FinalES/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/Final/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/Release/ClientRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../../built/Release/ClientRes/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_NAME_DEBUG MFC DLL   "CRes"
    ARCHIVE_OUTPUT_NAME_DEBUG           "CRes"
    ARCHIVE_OUTPUT_NAME_FINAL DE        "CRes"
    ARCHIVE_OUTPUT_NAME_FINAL ES        "CRes"
    ARCHIVE_OUTPUT_NAME_FINAL FR        "CRes"
    ARCHIVE_OUTPUT_NAME_FINAL IT        "CRes"
    ARCHIVE_OUTPUT_NAME_FINAL MFC DLL   "CRes"
    ARCHIVE_OUTPUT_NAME_FINAL           "CRes"
    ARCHIVE_OUTPUT_NAME_RELEASE MFC DLL "CRes"
    ARCHIVE_OUTPUT_NAME_RELEASE         "CRes"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/DE"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/ES"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/FR"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/IT"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/ES"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN"
    ">"
    "$<$<CONFIG:Release>:"
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
    "$<$<CONFIG:Debug MFC DLL>:"
        "WIN32;"
        "_DEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:Debug>:"
        "WIN32;"
        "_DEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:Final DE>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Final ES>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Final FR>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Final IT>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Final>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:Release>:"
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
        $<$<CONFIG:Debug MFC DLL>:
            /Gm;
            /Od;
            /MDd;
            /Gy;
            /W3
        >
        $<$<CONFIG:Debug>:
            /Gm;
            /Od;
            /MDd;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final DE>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final ES>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final FR>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final IT>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final MFC DLL>:
            /O2;
            /GF;
            /MT;
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
        $<$<CONFIG:Release MFC DLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:Release>:
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
        $<$<CONFIG:Debug MFC DLL>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Debug>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Final DE>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final ES>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final FR>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final IT>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final MFC DLL>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release MFC DLL>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release>:
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
    COMMAND   $<CONFIG:Debug MFC DLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    COMMAND           $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
)

################################################################################
# Dependencies
################################################################################
set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "$<$<CONFIG:Debug MFC DLL>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Debug>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final DE>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final ES>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final FR>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final IT>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Release>:"
        "odbc32;"
        "odbccp32"
    ">"
)
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

