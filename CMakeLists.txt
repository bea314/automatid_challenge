# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

set(EXTRA_COMPONENT_DIRS "$ENV{IDF_PATH}/components/esp_aws_iot/libraries/coreMQTT"
						 "$ENV{IDF_PATH}/components/esp_aws_iot/libraries/Device-Shadow-for-AWS-IoT-embedded-sdk"
						 "$ENV{IDF_PATH}/components/esp_aws_iot/libraries/coreJSON"
						 "$ENV{IDF_PATH}/components/esp_aws_iot/libraries/backoffAlgorithm"
						 "$ENV{IDF_PATH}/components/esp_aws_iot/libraries/common/posix_compat"
   )

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(main)

target_add_binary_data(${CMAKE_PROJECT_NAME}.elf "./certs/AmazonRootCA1.pem" TEXT)
target_add_binary_data(${CMAKE_PROJECT_NAME}.elf "./certs/certificate.pem.crt" TEXT)
target_add_binary_data(${CMAKE_PROJECT_NAME}.elf "./certs/private.pem.key" TEXT)