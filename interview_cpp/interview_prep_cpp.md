# C++ Internals & Advanced Concepts Prep 
(for HFT / Systems / C++ SWE New Grad Roles)

> These topics reflect what high-end C++ interviews expect:
> deep knowledge of memory, object model, STL internals, undefined behavior,
> performance implications, templates, concurrency, and compiler mechanics.
> Not surface-level syntax.

## Features / Requirements:

- [ ] **C++ Object Model & Memory Layout**
    - **Why Important**: HFTs test understanding of what the compiler actually generates; crucial for performance and correctness.
    - [ ] Object layout (POD vs non-POD)
    - [ ] Memory representation of classes
    - [ ] vtable, vptr layout
    - [ ] Empty base optimization (EBO)
    - [ ] sizeof() behavior
    - [ ] Alignment, padding
    - [ ] Type punning & strict aliasing rules

- [ ] **Value Categories, References & Move Semantics**
    - **Why Important**: A major differentiator; companies expect mastery of rvalue/lvalue mechanics and when moves occur.
    - [ ] lvalues, rvalues, xvalues, prvalues
    - [ ] rvalue references (T&&)
    - [ ] universal/forwarding references
    - [ ] move constructor, move assignment
    - [ ] copy elision (and guaranteed elision in C++17)
    - [ ] std::move vs std::forward
    - [ ] Perfect forwarding

- [ ] **Memory Management & Resource Handling**
    - **Why Important**: HFTs care about predictable memory usage, latency, and eliminating leaks.
    - [ ] Stack vs heap allocation
    - [ ] malloc/new differences
    - [ ] Placement new
    - [ ] Memory leaks / double frees / use-after-free
    - [ ] RAII principles
    - [ ] Smart pointers: unique_ptr, shared_ptr, weak_ptr
    - [ ] Custom deleters
    - [ ] Allocators & arena allocators

- [ ] **STL Internals (Extremely Important)**
    - **Why Important**: Deep STL understanding demonstrates mastery of performance, complexity, and memory behavior.
    - [ ] std::vector memory model (capacity, growth strategy)
    - [ ] std::string SSO (small-string optimization)
    - [ ] std::unordered_map hashing, buckets, load factor
    - [ ] std::map / std::set as red-black trees
    - [ ] Iterators: invalidation rules
    - [ ] std::optional, std::variant behavior
    - [ ] std::thread, atomics, futures basics
    - [ ] Container complexity guarantees

- [ ] **Templates & Generic Programming**
    - **Why Important**: HFTs love testing template understanding; demonstrates ability to read/write high-performance abstractions.
    - [ ] Function templates / class templates
    - [ ] Template specialization (partial, full)
    - [ ] SFINAE basics
    - [ ] Concepts (C++20)
    - [ ] CRTP (curiously recurring template pattern)
    - [ ] constexpr and compile-time computation
    - [ ] Variadic templates

- [ ] **Compiler Behavior & Code Generation**
    - **Why Important**: Understanding what the compiler does helps reason about performance and UB.
    - [ ] Inlining
    - [ ] Linker basics (ODR, symbol resolution)
    - [ ] Name mangling
    - [ ] Compiler optimizations (loop unrolling, RVO, devirtualization)
    - [ ] UB consequences & optimizer assumptions
    - [ ] constexpr vs inline vs static

- [ ] **Concurrency, Atomics & Memory Model**
    - **Why Important**: Modern C++ roles require deep concurrency reasoning, not just using std::thread.
    - [ ] std::atomic basics, atomic types
    - [ ] Memory ordering: relaxed, acquire-release, seq_cst
    - [ ] Data races vs race conditions
    - [ ] Mutexes, locks, lock_guard, unique_lock
    - [ ] Condition variables
    - [ ] Lock-free & wait-free concepts
    - [ ] false sharing & cache line alignment

- [ ] **Error Handling & Exceptions**
    - **Why Important**: Many trading firms require “no exceptions”, but understanding the model is still tested.
    - [ ] Stack unwinding behavior
    - [ ] noexcept vs throw
    - [ ] Exception safety levels
    - [ ] Error codes vs exceptions
    - [ ] RAII exception safety

- [ ] **C++ Undefined Behavior (UB)**
    - **Why Important**: HFT interviews LOVE UB reasoning questions (iterator invalidation, lifetime issues, etc.).
    - [ ] Dangling references/pointers
    - [ ] Iterator invalidation rules
    - [ ] Signed integer overflow (UB!)
    - [ ] Strict aliasing violation
    - [ ] Out-of-bounds access
    - [ ] Use-after-free
    - [ ] Double delete

- [ ] **Low-Level Performance & Optimization**
    - **Why Important**: Critical for latency-sensitive roles like HFT or real-time systems.
    - [ ] CPU caching behavior (L1/L2/L3)
    - [ ] Branch prediction
    - [ ] Cache-friendly data structures
    - [ ] False sharing
    - [ ] Avoiding unnecessary allocations
    - [ ] Micro-optimizing hotspots
    - [ ] Benchmarking & profiling tools

- [ ] **Build Systems & Tooling**
    - **Why Important**: Shows practical engineering ability, not just language theory.
    - [ ] CMake basics
    - [ ] Compiler flags (O2/O3, -march=native, sanitizers)
    - [ ] AddressSanitizer, UBSan, TSan
    - [ ] GDB basics
    - [ ] static vs shared libraries

- [ ] **Modern C++ Features (C++11 → C++20/23)**
    - **Why Important**: Companies expect familiarity with C++14/17 at least, and ability to use modern idioms.
    - [ ] auto, range-based loops
    - [ ] lambda captures
    - [ ] constexpr if
    - [ ] structured bindings
    - [ ] std::optional, std::variant, std::any
    - [ ] spans (C++20)
    - [ ] coroutines (high-level)
