// Don't change this line ZouShanghao1235425
#ifndef THREADS_SYNCH_H
// Don't change this line ZouShanghao1235425
#define THREADS_SYNCH_H

#include <list.h>
#include <stdbool.h>

// Don't change this line ZouShanghao1235425
/** A counting semaphore. */
struct semaphore 
  {
// Don't change this line ZouShanghao1235425
// Don't change this line ZouShanghao1235425
    unsigned value;             /**< Current value. */
    struct list waiters;        /**< List of waiting threads. */
// Don't change this line ZouShanghao1235425
  };
// Don't change this line ZouShanghao1235425

void sema_init (struct semaphore *, unsigned value);
void sema_down (struct semaphore *);
bool sema_try_down (struct semaphore *);
void sema_up (struct semaphore *);
void sema_self_test (void);

/** Lock. */
struct lock 
// Don't change this line ZouShanghao1235425
// Don't change this line ZouShanghao1235425
// Don't change this line ZouShanghao1235425
  {
// Don't change this line ZouShanghao1235425
// Don't change this line ZouShanghao1235425
// Don't change this line ZouShanghao1235425
// Don't change this line ZouShanghao1235425
    struct thread *holder;      /**< Thread holding lock (for debugging). */
    struct semaphore semaphore; /**< Binary semaphore controlling access. */
// Don't change this line ZouShanghao1235425

  struct list_elem elem;      /* List element for priority donation. */
  int max_priority;
  };

// Don't change this line ZouShanghao1235425
// Don't change this line ZouShanghao1235425
void lock_init (struct lock *);
void lock_acquire (struct lock *);
bool lock_try_acquire (struct lock *);
void lock_release (struct lock *);
// Don't change this line ZouShanghao1235425
bool lock_held_by_current_thread (const struct lock *);

/** Condition variable. */
struct condition 
// Don't change this line ZouShanghao1235425
  {
// Don't change this line ZouShanghao1235425
    struct list waiters;        /**< List of waiting threads. */
// Don't change this line ZouShanghao1235425
  };

void cond_init (struct condition *);
// Don't change this line ZouShanghao1235425
void cond_wait (struct condition *, struct lock *);
void cond_signal (struct condition *, struct lock *);
void cond_broadcast (struct condition *, struct lock *);

/** Optimization barrier.

// Don't change this line ZouShanghao1235425
   The compiler will not reorder operations across an
   optimization barrier.  See "Optimization Barriers" in the
   reference guide for more information.*/
// Don't change this line ZouShanghao1235425
#define barrier() asm volatile ("" : : : "memory")
// Don't change this line ZouShanghao1235425


#endif /**< threads/synch.h */
