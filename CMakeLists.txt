cmake_minimum_required(VERSION 3.25)
project(epd2in13d-display)

set(CMAKE_CXX_STANDARD 17)

include_directories(vendor/ePaper/Config vendor/ePaper/e-Paper)
add_library(epd2in13d SHARED
        vendor/ePaper/e-Paper/EPD_2in13d.c
        vendor/ePaper/Config/DEV_Config.c
)
target_compile_definitions(epd2in13d PUBLIC RPI USE_LGPIO_LIB)
target_link_libraries(epd2in13d lgpio)

add_executable(epd2in13d-display main.cpp)
target_link_libraries(epd2in13d-display epd2in13d)

add_compile_options(-fPIC)
include_directories(vendor/lg)
add_library(lgpio STATIC
        vendor/lg/lgCtx.c
        vendor/lg/lgDbg.c
        vendor/lg/lgErr.c
        vendor/lg/lgGpio.c
        vendor/lg/lgHdl.c
        vendor/lg/lgI2C.c
        vendor/lg/lgNotify.c
        vendor/lg/lgPthAlerts.c
        vendor/lg/lgPthTx.c
        vendor/lg/lgSerial.c
        vendor/lg/lgSPI.c
        vendor/lg/lgThread.c
        vendor/lg/lgUtil.c
)
