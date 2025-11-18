# Database Systems Concepts Prep (for SWE / HFT / System Companies — New Grad)

> These DBMS topics are chosen because top system companies and HFTs expect
> understanding beyond SQL syntax — focusing on indexing, transactions,
> consistency, normalization reasoning, and storage internals.

## Features / Requirements:

- [ ] **Database Models & Architecture**
    - **Why Important**: Provides the foundation for understanding how modern DB systems store and retrieve data.
    - [ ] Relational vs NoSQL data models
    - [ ] Client–server vs embedded DB architecture
    - [ ] Logical vs physical schema
    - [ ] How queries flow inside a DB engine (parse → plan → execute)

- [ ] **SQL (Queries, Joins, Subqueries)**
    - **Why Important**: SQL skills are expected; interviews may probe tricky join semantics and query reasoning, not memorized syntax.
    - [ ] SELECT, UPDATE, DELETE, INSERT semantics
    - [ ] Joins: inner, left, right, full, cross
    - [ ] GROUP BY, HAVING, window functions (basic)
    - [ ] Subqueries vs JOIN equivalents
    - [ ] Query rewriting for efficiency

- [ ] **Indexes (Heavily Tested)**
    - **Why Important**: Understanding index behavior shows system-level intuition — crucial for performance reasoning questions.
    - [ ] B+ Tree indexes
    - [ ] Hash indexes
    - [ ] Clustered vs non-clustered indexes
    - [ ] Composite indexes & prefix rules
    - [ ] Covering index
    - [ ] Index selectivity & cardinality
    - [ ] Index maintenance costs (writes becoming slower)

- [ ] **Transactions & ACID**
    - **Why Important**: Real interviews focus on race conditions, correctness, and consistency guarantees.
    - [ ] Atomicity, Consistency, Isolation, Durability
    - [ ] Transaction lifecycle
    - [ ] Commit vs rollback
    - [ ] WAL (Write-Ahead Logging) basics
    - [ ] Crash recovery concepts

- [ ] **Isolation Levels (Beyond Surface Level)**
    - **Why Important**: A *major* differentiator in interviews — often asked in system design + backend rounds.
    - [ ] Read Uncommitted
    - [ ] Read Committed
    - [ ] Repeatable Read
    - [ ] Serializable
    - [ ] Phenomena: dirty reads, non-repeatable reads, phantom reads
    - [ ] Snapshot isolation (MVCC)

- [ ] **Concurrency Control (Locks & MVCC)**
    - **Why Important**: Tests understanding of correctness under concurrent access, a key concept for HFT + backend work.
    - [ ] Shared vs exclusive locks
    - [ ] Lock escalation
    - [ ] Two-phase locking (2PL)
    - [ ] Optimistic vs pessimistic concurrency control
    - [ ] MVCC (multi-version concurrency control) internals
    - [ ] Deadlocks & deadlock detection

- [ ] **Query Optimization & Execution**
    - **Why Important**: Shows ability to reason about performance; companies expect more than “use an index”.
    - [ ] Query execution plan
    - [ ] Cost-based optimization
    - [ ] Join algorithms: nested loop, hash join, merge join
    - [ ] Cardinality estimation
    - [ ] Sorting algorithms (external sort, temp files)
    - [ ] Materialization vs pipelining

- [ ] **Normalization & Schema Design**
    - **Why Important**: Interviews test ability to design correct & efficient schemas; demonstrates reasoning and trade-offs.
    - [ ] 1NF, 2NF, 3NF, BCNF
    - [ ] Functional dependencies
    - [ ] Denormalization trade-offs
    - [ ] ER modeling
    - [ ] Choosing primary keys vs surrogate keys

- [ ] **Storage, Files, and Buffer Management**
    - **Why Important**: Shows deeper understanding of how databases actually interact with disk/memory.
    - [ ] Pages, extents, blocks
    - [ ] Heap files vs sorted files
    - [ ] Buffer pool basics
    - [ ] Dirty pages & checkpoints
    - [ ] Page replacement strategies (LRU, CLOCK)

- [ ] **Distributed Databases (Basic but Valued)**
    - **Why Important**: Modern systems use sharding, replication, consistency — even new grads are expected to know fundamentals.
    - [ ] Horizontal vs vertical scaling
    - [ ] Replication: leader–follower, multi-leader
    - [ ] Sharding strategies
    - [ ] CAP theorem intuition
    - [ ] Eventual consistency
    - [ ] Consistent hashing (high-level)

- [ ] **NoSQL Databases (Interview-Level Knowledge)**
    - **Why Important**: Demonstrates flexibility and architecture understanding for production systems.
    - [ ] Key-value stores (Redis)
    - [ ] Document stores (MongoDB)
    - [ ] Column stores (Cassandra)
    - [ ] Graph databases (Neo4j)
    - [ ] When to choose NoSQL vs SQL

- [ ] **Database Reliability & High Availability**
    - **Why Important**: Real systems must survive failures; interviews often include these scenarios.
    - [ ] Automatic failover
    - [ ] Replication lag
    - [ ] Read/write quorums
    - [ ] Backup strategies
    - [ ] Point-in-time recovery

