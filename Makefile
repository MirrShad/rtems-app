#
#  RTEMS_MAKEFILE_PATH is typically set in an environment variable
#

PGM=${ARCH}/delay.exe

# optional managers required
MANAGERS=all

# C source names
CSRCS = init.c
COBJS = $(CSRCS:%.c=${ARCH}/%.o)

include /home/andy/RTEMSspace/development/rtems/src/seer-rtems-stm32f4xx/arm-rtems4.11/seerstm32f4/Makefile.inc
include /home/andy/RTEMSspace/development/rtems/src/seer-rtems-stm32f4xx/make/custom/seerstm32f4.cfg
include /home/andy/RTEMSspace/development/rtems/src/seer-rtems-stm32f4xx/make/leaf.cfg

OBJS= $(COBJS) $(CXXOBJS) $(ASOBJS)

all:    ${ARCH} $(PGM)

$(PGM): $(OBJS)
	$(make-exe)
