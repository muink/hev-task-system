/*
 ============================================================================
 Name        : hev-task-io-reactor-kqueue.h
 Author      : Heiher <r@hev.cc>
 Copyright   : Copyright (c) 2018 everyone.
 Description : I/O Reactor KQueue
 ============================================================================
 */

#ifndef __HEV_TASK_IO_REACTOR_KQUEUE_H__
#define __HEV_TASK_IO_REACTOR_KQUEUE_H__

#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>

typedef struct kevent HevTaskIOReactorSetupEvent;
typedef struct kevent HevTaskIOReactorWaitEvent;

enum _HevTaskIOReactorEvents
{
    HEV_TASK_IO_REACTOR_EV_RO = EVFILT_READ,
    HEV_TASK_IO_REACTOR_EV_WO = EVFILT_WRITE,
    HEV_TASK_IO_REACTOR_EV_RW = EVFILT_READ | EVFILT_WRITE,
};

enum _HevTaskIOReactorOperation
{
    HEV_TASK_IO_REACTOR_OP_ADD = EV_ADD,
    HEV_TASK_IO_REACTOR_OP_MOD = EV_ADD,
    HEV_TASK_IO_REACTOR_OP_DEL = EV_DELETE,
};

static inline int
hev_task_io_reactor_get_oneshot (void)
{
    return 1;
}

static inline void
hev_task_io_reactor_setup_event_set (HevTaskIOReactorSetupEvent *event, int fd,
                                     HevTaskIOReactorOperation op,
                                     unsigned int events, void *data)
{
    EV_SET (event, fd, events, op | EV_ONESHOT, 0, 0, data);
}

static inline unsigned int
hev_task_io_reactor_wait_event_get_events (HevTaskIOReactorWaitEvent *event)
{
    return event->filter;
}

static inline void *
hev_task_io_reactor_wait_event_get_data (HevTaskIOReactorWaitEvent *event)
{
    return event->udata;
}

#endif /* __HEV_TASK_IO_REACTOR_KQUEUE_H__ */
