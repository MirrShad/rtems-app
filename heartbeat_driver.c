/*  heartBeatDriver_initialize
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems.h>
#include "heartbeat_driver.h"
#include <rtems/libio.h>
#include <rtems/devnull.h>
#include <stdio.h>
#include "led.h"
#include <bsp.h>
#include <string.h>
/* 
 * The test driver routines are mostly derived from the null driver routines.
 */
uint32_t   TEST_major;
static char initialized;

/*  testDriver_initialize
 *
 *  This routine is the test device driver init routine.
 *
 *  Input parameters:
 *    major - device major number
 *    minor - device minor number
 *    pargp - pointer to parameter block
 *
 *  Output parameters:
 *    rval       - RTEMS_SUCCESSFUL
 */
rtems_device_driver heartBeatDriver_initialize(
  rtems_device_major_number major,
  rtems_device_minor_number minor __attribute__((unused)),
  void *pargp __attribute__((unused))
)
{
  rtems_device_driver status;

  if ( !initialized ) {
    initialized = 1;

    status = rtems_io_register_name(
      "/dev/test",
      major,
      (rtems_device_minor_number) 0
    );

    if (status != RTEMS_SUCCESSFUL)
      rtems_fatal_error_occurred(status);

    TEST_major = major;
  }

  return RTEMS_SUCCESSFUL;
}

/*  testDriver_open
 *
 *  This routine is the test device driver open routine.
 *
 *  Input parameters:
 *    major - device major number
 *    minor - device minor number
 *    pargb - pointer to open parameter block
 *
 *  Output parameters:
 *    rval       - RTEMS_SUCCESSFUL
 */
rtems_device_driver heartBeatDriver_open(
  rtems_device_major_number major __attribute__((unused)),
  rtems_device_minor_number minor __attribute__((unused)),
  void *pargp __attribute__((unused))
)
{
  puts("test Driver open\r\n");
  return RTEMS_SUCCESSFUL;
}

/*  testDriver_close
 *
 *  This routine is the test device driver close routine.
 *
 *  Input parameters:
 *    major - device major number
 *    minor - device minor number
 *    pargb - pointer to close parameter block
 *
 *  Output parameters:
 *    rval       - RTEMS_SUCCESSFUL
 */
rtems_device_driver heartBeatDriver_close(
  rtems_device_major_number major __attribute__((unused)),
  rtems_device_minor_number minor __attribute__((unused)),
  void *pargp __attribute__((unused))
)
{
  return RTEMS_SUCCESSFUL;
}

/*  testDriver_read
 *
 *  This routine is the test device driver read routine.
 *
 *  Input parameters:
 *    major - device major number
 *    minor - device minor number
 *    pargp - pointer to read parameter block
 *
 *  Output parameters:
 *    rval       - RTEMS_SUCCESSFUL
 */
rtems_device_driver heartBeatDriver_read(
  rtems_device_major_number major __attribute__((unused)),
  rtems_device_minor_number minor __attribute__((unused)),
  void *pargp
)
{
/*
  rtems_libio_rw_args_t *rw_args = (rtems_libio_rw_args_t *) pargp;

  if ( rw_args ) {
    if( rw_args->count == 5 )
    {
      LED_OFF();
      rw_args->bytes_moved = 0;
    }
    else {
      rw_args->bytes_moved = 0;
      return RTEMS_NOT_IMPLEMENTED;
    }
  }
*/
  return RTEMS_SUCCESSFUL;
}

/*  testDriver_write
 *
 *  This routine is the test device driver write routine.
 *
 *  Input parameters:
 *    major - device major number
 *    minor - device minor number
 *    pargp - pointer to write parameter block
 *
 *  Output parameters:
 *    rval       - RTEMS_SUCCESSFUL
 */
rtems_device_driver heartBeatDriver_write(
  rtems_device_major_number major __attribute__((unused)),
  rtems_device_minor_number minor __attribute__((unused)),
  void *pargp
)
{
  rtems_libio_rw_args_t *rw_args = (rtems_libio_rw_args_t *) pargp;

  if ( rw_args ) {
    if( rw_args->count == 5 )
    {
      if(0 == strcmp(rw_args->buffer,"on")) //puts("write equals data\r\n");
        LED_ON();
      if(0 == strcmp(rw_args->buffer,"off")) //puts("write equals data\r\n");
        LED_OFF();
      return null_write( 0, 0, pargp );
    }
    else {
      rw_args->bytes_moved = 0;
      return RTEMS_NOT_IMPLEMENTED;
    }
  }

  return RTEMS_SUCCESSFUL;
}

/*  testDriver_control
 *
 *  This routine is the test device driver control routine.
 *
 *  Input parameters:
 *    major - device major number
 *    minor - device minor number
 *    pargp - pointer to cntrl parameter block
 *
 *  Output parameters:
 *    rval       - RTEMS_SUCCESSFUL
 */

rtems_device_driver heartBeatDriver_control(
  rtems_device_major_number major __attribute__((unused)),
  rtems_device_minor_number minor __attribute__((unused)),
  void *pargp __attribute__((unused))
)
{
  return RTEMS_NOT_IMPLEMENTED;
}
