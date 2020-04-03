project(TO2EN CXX)

# Make MSVC detect this project as a C++, so that additional include directories work correctly.
set(no_group_source_files
    "../IgnoreMe.cpp"
)
source_group("" FILES ${no_group_source_files})

set(Localized_Files__EN
    "credits.txt"
    "intro.txt"
    "ClientRes.rc"
    "../../../Shared/Lang/EN/ClientResShared.rc"
)
source_group("Localized Files\\EN" FILES ${Localized_Files__EN})

set(ALL_FILES
    ${no_group_source_files}
    # ${Localized_Files__DE}
    ${Localized_Files__EN}
    # ${Localized_Files__ES}
    # ${Localized_Files__FR}
    # ${Localized_Files__IT}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG         "TO2EN"
    TARGET_NAME_DEBUGMFCDLL   "TO2EN"
    TARGET_NAME_FINAL         "TO2EN"
    TARGET_NAME_FINALDE       "TO2EN"
    TARGET_NAME_FINALES       "TO2EN"
    TARGET_NAME_FINALFR       "TO2EN"
    TARGET_NAME_FINALIT       "TO2EN"
    TARGET_NAME_RELEASE       "TO2EN"
    TARGET_NAME_RELEASEMFCDLL "TO2EN"
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
    ARCHIVE_OUTPUT_NAME_DEBUG         "TO2EN"
    ARCHIVE_OUTPUT_NAME_DEBUGMFCDLL   "TO2EN"
    ARCHIVE_OUTPUT_NAME_FINAL         "TO2EN"
    ARCHIVE_OUTPUT_NAME_FINALDE       "TO2EN"
    ARCHIVE_OUTPUT_NAME_FINALES       "TO2EN"
    ARCHIVE_OUTPUT_NAME_FINALFR       "TO2EN"
    ARCHIVE_OUTPUT_NAME_FINALIT       "TO2EN"
    ARCHIVE_OUTPUT_NAME_RELEASE       "TO2EN"
    ARCHIVE_OUTPUT_NAME_RELEASEMFCDLL "TO2EN"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Shared;"
        # These are two different directories actually...
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Shared/Lang/EN"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../Shared/Lang/EN"
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
# Dependencies
################################################################################
# target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")