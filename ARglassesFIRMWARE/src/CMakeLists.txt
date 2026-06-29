# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

file(GLOB_RECURSE app_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

idf_component_register(
    SRCS ${app_sources}
    INCLUDE_DIRS "." "../include"
    REQUIRES driver esp_wifi esp_event esp_netif nvs_flash esp_websocket_client led_strip freertos
)
