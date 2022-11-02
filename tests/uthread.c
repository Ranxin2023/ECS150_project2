#include <assert.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "private.h"
#include "uthread.h"
#include "queue.h"

#define RUNNING 0
#define READY 1		/* ready to schedule */
#define BLOCKED 2 	/* waiting to join */
#define EXIT 3		/* thread is dead */

queue_t q;
struct uthread_tcb *idle;

/*
 * Tread Control Block*
 * uthread_tcb - Internal representation of threads called TCB (Thread Control
 * Block)
 */
struct uthread_tcb {
	/* TODO Phase 2 */

	int state; /* running, ready, blocked, exit */
	void *stack;
	uthread_ctx_t *uctx; /* typedef ucontext_t uthread_ctx_t */
	
};

/*
 * uthread_current - Get currently running thread
 *
 * Return: Pointer to current thread's TCB
 */
struct uthread_tcb *uthread_current(void)
{
	/* TODO Phase 2/4 */
	struct uthread_tcb *idle = malloc(sizeof(struct uthread_tcb));

	return idle;
}

// void uthread_yield(void) // context switch, enqueue/dequeue
// {
// 	/*
// 	 * uthread_yield - Yield execution
// 	 *
// 	 * This function is to be called from the currently active and running thread in
// 	 * order to yield for other threads to execute.
// 	 */
// }

// void uthread_exit(void)
// {
// 	/*
// 	 * uthread_exit - Exit from currently running thread
// 	 *
// 	 * This function is to be called from the currently active and running thread in
// 	 * order to finish its execution.
// 	 *
// 	 * This function shall never return.
// 	 */
// }

int uthread_create(uthread_func_t func, void *arg) // init
{
	 // * uthread_create - Create a new thread
	 // * @func: Function to be executed by the thread
	 // * @arg: Argument to be passed to the thread
	 // *
	 // * This function creates a new thread running the function @func to which
	 // * argument @arg is passed.
	 // *
	 // * Return: 0 in case of success, -1 in case of failure (e.g., memory allocation,
	 // * context creation).
	struct uthread_tcb *new_thread = malloc(sizeof(struct uthread_tcb));
	new_thread->stack = uthread_ctx_alloc_stack;
	uthread_ctx_init(new_thread->uctx, new_thread->stack, func, arg);


	 return 0;
}

int uthread_run(bool preemp, uthread_func_t func, void *arg) // create obj, create, enqueue
{
	
	 // * uthread_run - Run the multithreading library
	 // * @preempt: Preemption enable
	 // * @func: Function of the first thread to start
	 // * @arg: Argument to be passed to the first thread
	 // *
	 // * This function should only be called by the process' original execution
	 // * thread. It starts the multithreading scheduling library, and becomes the
	 // * "idle" thread. It returns once all the threads have finished running.
	 // *
	 // * If @preempt is `true`, then preemptive scheduling is enabled.
	 // *
	 // * Return: 0 in case of success, -1 in case of failure (e.g., memory allocation,
	 // * context creation).
	 

	if (preemp) {
		printf("testing: preemptive scheduling is enabled.\n");
	}

	q = queue_create();
	
	idle = uthread_current();
	uthread_create(func, arg);
	while(q) {

	}

	


	return 0;
}


// void uthread_block(void)
// {
// 	/* TODO Phase 4 */
// }

// void uthread_unblock(struct uthread_tcb *uthread)
// {
// 	/* TODO Phase 4 */
// }

// Testing
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

