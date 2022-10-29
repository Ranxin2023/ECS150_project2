#include <assert.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "private.h"
#include "uthread.h"

/* Tread Control Block*/
struct uthread_tcb {
	/* TODO Phase 2 */
	int state; // running, ready, blocked, etc
	void *stack;
	uthread_ctx_t；
};


struct uthread_tcb *uthread_current(void)
{
	/* TODO Phase 2/4 */
	struct uthread_tcb *t = malloc(sizeof(struct uthread_tcb));

	if (t) {
	    t->state = 0;
	    t->stack = NULL;
	    return t;
	    }
	return NULL;

}

void uthread_yield(void)
{
	/*
	 * uthread_yield - Yield execution
	 *
	 * This function is to be called from the currently active and running thread in
	 * order to yield for other threads to execute.
	 */
}

void uthread_exit(void)
{
	/*
	 * uthread_exit - Exit from currently running thread
	 *
	 * This function is to be called from the currently active and running thread in
	 * order to finish its execution.
	 *
	 * This function shall never return.
	 */
}

int uthread_create(uthread_func_t func, void *arg)
{
	/*
	 * uthread_create - Create a new thread
	 * @func: Function to be executed by the thread
	 * @arg: Argument to be passed to the thread
	 *
	 * This function creates a new thread running the function @func to which
	 * argument @arg is passed.
	 *
	 * Return: 0 in case of success, -1 in case of failure (e.g., memory allocation,
	 * context creation).
	 */
}

int uthread_run(bool preemp, uthread_func_t func, void *arg)
{
	/*
	 * uthread_run - Run the multithreading library
	 * @preempt: Preemption enable
	 * @func: Function of the first thread to start
	 * @arg: Argument to be passed to the first thread
	 *
	 * This function should only be called by the process' original execution
	 * thread. It starts the multithreading scheduling library, and becomes the
	 * "idle" thread. It returns once all the threads have finished running.
	 *
	 * If @preempt is `true`, then preemptive scheduling is enabled.
	 *
	 * Return: 0 in case of success, -1 in case of failure (e.g., memory allocation,
	 * context creation).
	 */
}

void uthread_block(void)
{
	/* TODO Phase 4 */
}

void uthread_unblock(struct uthread_tcb *uthread)
{
	/* TODO Phase 4 */
}

void hello(void *arg)
{
	(void)arg;

	printf("Hello world!\n");
}

int main(void)
{
	uthread_run(false, hello, NULL);

	return 0;
}

