cmake_minimum_required(VERSION 3.19)
project(SistemaBancoQt LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_resources(App_RESOURCES desenv.qrc)

qt_add_executable(SistemaBancoQt
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    pessoa.cpp pessoa.hpp
    banco.cpp banco.hpp banco_dados.cpp banco_dados.hpp
    dialogconta.h dialogconta.cpp dialogconta.ui
    dialogcadastro.h dialogcadastro.cpp dialogcadastro.ui
    dialogsobre.h dialogsobre.cpp dialogsobre.ui


    ${App_RESOURCES}
)

target_link_libraries(SistemaBancoQt
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS SistemaBancoQt
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET SistemaBancoQt
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

