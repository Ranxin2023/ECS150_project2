#include <stddef.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"
#include "sem.h"
#include "private.h"


/*
 * sem_t - Semaphore type
 *
 * A semaphore is a way to control access to a common resource by multiple
 * threads. Such resource has an internal count, meaning that it can only be
 * shared a certain number of times. When a thread successfully takes the
 * resource, the count is decreased. When the resource is not available,
 * following threads are blocked until the resource becomes available again.
 */

struct semaphore {
	/* TODO Phase 3 */
	int state;
	int lock;
	queue_t q;
};


/*
 * sem_create - Create semaphore
 * @count: Semaphore count
 *
 * Allocate and initialize a semaphore of internal count @count.
 *
 * Return: Pointer to initialized semaphore. NULL in case of failure when
 * allocating the new semaphore.
 */
sem_t sem_create(size_t count)
{
	/* TODO Phase 3 */
	sem_t sem=malloc(sizeof(struct semaphore));
	if(!sem)return NULL;
	sem->state=count;
	return sem;
}

/*
 * sem_down - Take a semaphore
 * @sem: Semaphore to take
 *
 * Take a resource from semaphore @sem.
 *
 * Taking an unavailable semaphore will cause the caller thread to be blocked
 * until the semaphore becomes available.
 *
 * Return: -1 if @sem is NULL. 0 if semaphore was successfully taken.
 */

int sem_destroy(sem_t sem)
{
	/* TODO Phase 3 */
	if(!sem)return -1;
	free(sem);
	return 0;
}

/*
 * sem_down - Take a semaphore
 * @sem: Semaphore to take
 *
 * Take a resource from semaphore @sem.
 *
 * Taking an unavailable semaphore will cause the caller thread to be blocked
 * until the semaphore becomes available.
 *
 * Return: -1 if @sem is NULL. 0 if semaphore was successfully taken.
 */

int sem_down(sem_t sem)
{
	/* TODO Phase 3 */
	if(!sem)return -1;
	spinlock_lock(sem);
	while(sem->state==0){
		/*Block self*/
		
	}
	sem->state-=1;
	spinlock_unlock(sem);
	return 0;
}

/*
 * sem_up - Release a semaphore
 * @sem: Semaphore to release
 *
 * Release a resource to semaphore @sem.
 *
 * If the waiting list associated to @sem is not empty, releasing a resource
 * also causes the first thread (i.e. the oldest) in the waiting list to be
 * unblocked.
 *
 * Return: -1 if @sem is NULL. 0 if semaphore was successfully released.
 */

int sem_up(sem_t sem)
{
	/* TODO Phase 3 */
	if(!sem)return -1;
	spinlock_lock(sem);
	sem->state+=1;
	spinlock_unlock(sem);
	return 0;
}

