cmake_minimum_required(VERSION 3.12)
project(MODEL_TME1 C)

set(CMAKE_C_STANDARD 11)

add_executable(MODEL_TME1 model_tme1.c)
target_link_libraries(MODEL_TME1 gmp)