/*
 *  COPYRIGHT (c) 1989-2009.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#include <stdio.h>
#include <bsp.h>

#include "led.h"
#include <pthread.h>
#include <assert.h>

void * heart_beat(void * arg)
{
  struct timeval time;
  struct timespec timeout;
  bool led_on = true;

  gettimeofday(&time, NULL);
  timeout.tv_sec = time.tv_sec + 1;
  do{
    gettimeofday(&time, NULL);
    if(time.tv_sec - timeout.tv_sec >=1)
    {
      if(led_on) LED_ON();
      else LED_OFF();
      led_on = !led_on;
      timeout.tv_sec = time.tv_sec + 1;
    }
  }while(true);

  return NULL;
}


void *POSIX_Init() 
{
  rtems_status_code status;

  puts( "\n\n test start" );

  //LED_ON();
  pthread_t child;
  if ( pthread_create( &child, NULL, heart_beat, NULL ))
    perror("Error on pthread_create");
  printf("<main>: Wait for child thread...\n");
  if ( pthread_join( child, NULL ))
    perror("Error on pthread_join");
  return 0;
  
  status = rtems_task_delete( RTEMS_SELF );
}

/**************** START OF CONFIGURATION INFORMATION ****************/

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_MAXIMUM_POSIX_THREADS              10
#define CONFIGURE_MAXIMUM_POSIX_CONDITION_VARIABLES  10
#define CONFIGURE_MAXIMUM_POSIX_MUTEXES              10
#define CONFIGURE_POSIX_INIT_THREAD_TABLE
#define CONFIGURE_INIT

#define CONFIGURE_INIT_TASK_INITIAL_MODES (RTEMS_PREEMPT | RTEMS_TIMESLICE | RTEMS_TIMESLICE_MASK | RTEMS_NO_ASR | RTEMS_INTERRUPT_LEVEL(0))

#define CONFIGURE_MICROSECONDS_PER_TICK 1000
#define CONFIGURE_TICKS_PER_TIMESLICE 1000
#include <rtems/confdefs.h>

/****************  END OF CONFIGURATION INFORMATION  ****************/
