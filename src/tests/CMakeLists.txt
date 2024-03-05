cmake_minimum_required(VERSION 3.22)
project(gencrc_tests C)

add_executable(crc8_test crc8/test.c)
target_link_libraries(crc8_test PRIVATE gencrc)
add_test(NAME crc8_test COMMAND crc8_test)

add_executable(crc8_table_test crc8/table_test.c)
target_link_libraries(crc8_table_test PRIVATE gencrc)
add_test(NAME crc8_table_test COMMAND crc8_table_test)

add_executable(crc16_test crc16/test.c)
target_link_libraries(crc16_test PRIVATE gencrc)
add_test(NAME crc16_test COMMAND crc16_test)

add_executable(crc16_table_test crc16/table_test.c)
target_link_libraries(crc16_table_test PRIVATE gencrc)
add_test(NAME crc16_table_test COMMAND crc16_table_test)

add_executable(crc32_test crc32/test.c)
target_link_libraries(crc32_test PRIVATE gencrc)
add_test(NAME crc32_test COMMAND crc32_test)

add_executable(crc32_table_test crc32/table_test.c)
target_link_libraries(crc32_table_test PRIVATE gencrc)
add_test(NAME crc32_table_test COMMAND crc32_table_test)

