include(CMakeForceCompiler)

set(CMAKE_SYSTEM_NAME Generic)

CMAKE_FORCE_C_COMPILER(arm-rtems4.11-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(arm-rtems4.11-g++ GNU)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
set(CMAKE_ASM_COMPILER arm-rtems4.11-as)
set(CMAKE_OBJCOPY arm-rtems4.11-objcopy)
set(CMAKE_LINKER arm-rtems4.11-ld)
set(CMAKE_C_FLAGS "--pipe -B/home/andy/RTEMSspace/development/rtems/src/seer-rtems-stm32f4xx/arm-rtems4.11/seerstm32f4/lib/ -specs bsp_specs -qrtems -Wall -O0 -g -march=armv7-m -mthumb")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_executable(delay init.c test_driver.c)
