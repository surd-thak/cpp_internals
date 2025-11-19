
# 📝 Notes on Solutions to Race Conditions

Race conditions occur when multiple threads/processes access shared data concurrently and the final outcome depends on the ordering of operations. Below are different classical approaches to solving race conditions, along with explanations and comments based on operating-systems concepts and hardware/software mechanisms.

---

## ## 1. Naive Lock Using a Shared Integer (Unsafe)

```cpp
int lock = 0; //shared lock 
//A plain int cannot act as a lock safely in multithreaded code.
```

* A simple integer flag (`0` = unlocked, `1` = locked) *seems* like it could control access.
* However, **reading and writing an int is not atomic**, so multiple threads may:

  * See `lock == 0` at the same time.
  * Enter the critical section simultaneously.
* This leads to classic lost updates (e.g., both read the same value of `x`, increment independently).

**Why it fails:**
Because the test (`while(lock != 0)`) and the set (`lock = 1`) are separate instructions, a context switch between them reintroduces the race condition.

---

## ## 2. Turn-Based Locking (Strict Alternation)

```cpp
int turn = 0;
// Using a shared turn variable to implement turn-based access for threads
```

* Only the thread whose ID matches `turn` may enter its critical section.
* After finishing, it gives turn to the other thread.

### Pros

* Avoids simultaneous entry.
* Simple and starvation-free (both threads alternate reliably).

### Cons

* **Not practical** in real systems:

  * A thread must wait for its turn even if the other thread is not interested in entering the critical section.
  * Scalability: works only for two threads.

---

## ## 3. Peterson’s Solution (Software Solution For Two Threads)

```cpp
//petersons solution --> locks+turns
//decouple dependency on a single variable --> context switch doesnt affect shared resource
//only valid for two processes
//busy wait is inefficient
```

* Uses two shared arrays/variables:

  * `interested[i]` — expresses desire to enter the critical section.
  * `turn` — resolves conflict when both want to enter.
* Ensures **mutual exclusion**, **bounded waiting**, and **progress**.

### Pros

* Works in software, no special hardware instructions needed.
* Completely correct **if memory writes are atomic and ordering is preserved**.

### Cons

* Assumes strict memory ordering (not always true on modern weakly-ordered CPUs).
* Busy waits (spinlocks) waste CPU cycles.
* Only works for **two threads**.

---

## ## 4. Hardware Solution: TSL (Test-and-Set Lock)

```cpp
//tsl instruction -- hardware solution
//TSL (Test-and-Set Lock) atomically reads a memory location and sets it to 1,
//ensuring the check and the set operation are performed as a single, indivisible operation,
//preventing race conditions.
//not user level
```

### Explanation

* `TSL` (Test-and-Set Lock) or the modern `xchg`, `cmpxchg`, `atomic_flag`, etc., are **atomic hardware instructions**.
* They **read a lock variable and set it in a single uninterruptible operation**.
* Prevents threads from observing an inconsistent state and guarantees safe locking.

### Pros

* Efficient at CPU level.
* Works for any number of threads.
* Foundation of many OS-level synchronization primitives.

### Cons

* Still uses **busy waiting** (spinlocks).
* Not available directly in user-level code on all architectures (OS encapsulates them).

---

## ## 5. Sleep and Wakeup (Signaling Mechanism)

```cpp
//signalling --> sleep and wakeup system calls --> to avoid busy wait
//priority inversions problem 
```

### Explanation

* To avoid wasting CPU cycles during busy waiting, OS kernels provide:

  * `sleep()` — block the calling thread until some condition occurs.
  * `wakeup()` — signal a sleeping thread to resume.
* Used by semaphores, condition variables, monitors, and many modern synchronization abstractions.

### Pros

* Eliminates CPU wastage from spinlocks.
* Allows threads to be scheduled fairly.

### Cons

* **Priority inversion** can occur:

  * A low-priority thread holding a lock blocks a high-priority thread.
  * A medium-priority thread preempts the low-priority one, delaying the high-priority thread even more.
  * Real systems solve this using **priority inheritance protocols**.

---

# Summary Table

| Solution               | Type         | Mutual Exclusion | Scalability | Notes                                        |
| ---------------------- | ------------ | ---------------- | ----------- | -------------------------------------------- |
| Shared integer lock    | ❌ Incorrect  | ❌ No             | Poor        | Non-atomic                                   |
| Strict alternation     | Software     | ✔ Yes            | ❌ 2 only    | Forces alternation                           |
| Peterson’s algorithm   | Software     | ✔ Yes            | ❌ 2 only    | Requires strict memory ordering              |
| TSL / atomic ops       | Hardware     | ✔ Yes            | ✔ Good      | Still busy-waits                             |
| Sleep/Wakeup signaling | OS mechanism | ✔ Yes            | ✔ Good      | Avoids busy wait; risk of priority inversion |

---

