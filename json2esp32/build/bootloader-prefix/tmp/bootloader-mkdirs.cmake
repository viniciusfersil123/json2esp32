# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/vinicius/esp/esp-idf/components/bootloader/subproject"
  "/home/vinicius/Projects/json2esp32/json2esp32/build/bootloader"
  "/home/vinicius/Projects/json2esp32/json2esp32/build/bootloader-prefix"
  "/home/vinicius/Projects/json2esp32/json2esp32/build/bootloader-prefix/tmp"
  "/home/vinicius/Projects/json2esp32/json2esp32/build/bootloader-prefix/src/bootloader-stamp"
  "/home/vinicius/Projects/json2esp32/json2esp32/build/bootloader-prefix/src"
  "/home/vinicius/Projects/json2esp32/json2esp32/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/vinicius/Projects/json2esp32/json2esp32/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/vinicius/Projects/json2esp32/json2esp32/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
