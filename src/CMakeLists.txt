configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/config.h)

set(zeit_SRCS
    aboutdialog.cpp
    alarmdialog.cpp
    basedialog.cpp
    baseeditdialog.cpp
    commanddialog.cpp
    commands.cpp
    main.cpp
    mainwindow.cpp
    taskdialog.cpp
    timerdialog.cpp
    variabledialog.cpp
)
set(zeit_FRMS
    alarmdialog.ui
    commanddialog.ui
    mainwindow.ui
    taskdialog.ui
    timerdialog.ui
    variabledialog.ui
)
set(zeit_RSRCS ../zeit.qrc)

#translations
SET(TRANSLATION
    ../translations/ru_RU.ts
)
find_package(Qt5LinguistTools REQUIRED)
qt5_add_translation(QM_FILES ${TRANSLATION})

set(qt_LIBS Qt5::Core Qt5::Gui Qt5::Widgets)

qt5_wrap_ui(zeit_FORMS_HEADERS ${zeit_FRMS})
qt5_add_resources(zeit_RESOURCES_RCC ${zeit_RSRCS})
add_executable(zeit ${zeit_SRCS} ${zeit_HEADERS_MOC} ${zeit_FORMS_HEADERS}
                    ${QM_FILES} ${zeit_RESOURCES_RCC})
target_include_directories(zeit PRIVATE ${Qt5Core_INCLUDE_DIRS}
                           ${Qt5Widgets_INCLUDE_DIRS}
                           ${CMAKE_CURRENT_SOURCE_DIR}/../crontablib
                           ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(zeit crontab ${qt_LIBS})
target_compile_features(zeit PRIVATE cxx_lambdas cxx_nullptr cxx_unicode_literals)

install(TARGETS zeit RUNTIME DESTINATION bin)
install(FILES ${QM_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/zeit/translations)
