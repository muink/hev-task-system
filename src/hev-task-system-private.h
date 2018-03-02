/*
 ============================================================================
 Name        : hev-task-system-private.h
 Author      : Heiher <r@hev.cc>
 Copyright   : Copyright (c) 2017 everyone.
 Description :
 ============================================================================
 */

#ifndef __HEV_TASK_SYSTEM_PRIVATE_H__
#define __HEV_TASK_SYSTEM_PRIVATE_H__

#include <setjmp.h>

#include "hev-task.h"
#include "hev-task-private.h"
#include "hev-task-system.h"

#define HEV_TASK_RUN_SCHEDULER	HEV_TASK_YIELD_COUNT

typedef struct _HevTaskSystemContext HevTaskSystemContext;

struct _HevTaskSystemContext
{
	int epoll_fd;
	unsigned int total_task_count;

	HevTask *current_task;
	HevTask *running_tasks;
	HevTask *running_tasks_tail;

	jmp_buf kernel_context;
};

void hev_task_system_schedule (HevTaskYieldType type);
void hev_task_system_wakeup_task (HevTask *task);
void hev_task_system_run_new_task (HevTask *task);
void hev_task_system_kill_current_task (void);

HevTaskSystemContext * hev_task_system_get_context (void);

#endif /* __HEV_TASK_SYSTEM_PRIVATE_H__ */

