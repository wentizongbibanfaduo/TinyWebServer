cmake_minimum_required(VERSION 3.10)

project(server LANGUAGES C CXX)
set(
  source_files
  main.cpp
  ./timer/lst_timer.cpp
  ./http/http_conn.cpp
  ./log/log.cpp
  ./CGImysql/sql_connection_pool.cpp  
  webserver.cpp 
  config.cpp)
add_compile_options(-O2)
add_executable(server ${source_files})
target_link_libraries(server pthread mysqlclient)
install(TARGETS server DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

