/*  test_driver.h
 *
 *  COPYRIGHT (c) 1989-2010.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#ifndef __TEST_DRIVER_h
#define __TEST_DRIVER_h

#ifdef __cplusplus
extern "C" {
#endif

#define HEART_BEAT_DRIVER_TABLE_ENTRY \
  { heartBeatDriver_initialize, heartBeatDriver_open, heartBeatDriver_close, heartBeatDriver_read, \
    heartBeatDriver_write, heartBeatDriver_control }

rtems_device_driver heartBeatDriver_initialize(
  rtems_device_major_number,
  rtems_device_minor_number,
  void *
);

rtems_device_driver heartBeatDriver_open(
  rtems_device_major_number,
  rtems_device_minor_number,
  void *
);

rtems_device_driver heartBeatDriver_close(
  rtems_device_major_number,
  rtems_device_minor_number,
  void *
);

rtems_device_driver heartBeatDriver_read(
  rtems_device_major_number,
  rtems_device_minor_number,
  void *
);

rtems_device_driver heartBeatDriver_write(
  rtems_device_major_number,
  rtems_device_minor_number,
  void *
);

rtems_device_driver heartBeatDriver_control(
  rtems_device_major_number,
  rtems_device_minor_number,
  void *
);

#ifdef __cplusplus
}
#endif

#endif
/* end of include file */
