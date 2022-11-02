#include <stddef.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"
#include "sem.h"
#include "private.h"

struct semaphore {
	/* TODO Phase 3 */
	int state;
	int lock;
	queue_t q;
};

sem_t sem_create(size_t count)
{
	/* TODO Phase 3 */
	sem_t sem=malloc(sizeof(struct semaphore));

	sem->state=count;
}

int sem_destroy(sem_t sem)
{
	/* TODO Phase 3 */
	free(sem);
}

int sem_down(sem_t sem)
{
	/* TODO Phase 3 */
	spinlock_lock(sem->lock);
	while(sem->state==0){
		/*Block self*/
	}
	sem->state-=1;
	spinlock_unlock(sem->lock);
}

int sem_up(sem_t sem)
{
	/* TODO Phase 3 */
	spinlock_lock(sem->lock);
	sem->state+=1;
	spinlock_unlock(sem->lock);
}

