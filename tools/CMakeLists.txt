
SET(APP_NAME   qt_zipper_ui)
add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} LINK_PUBLIC ${PROJECT_NAME})
target_include_directories(${APP_NAME} PUBLIC include)
