# Computer Networks Concepts Prep (for HFT / Deep Systems Interviews)

> These topics reflect what HFTs and strong system companies expect:
> not just definitions, but deep understanding, packet-level mechanics,
> performance behaviors, trade-offs, and real-world implementation reasoning.

## Features / Requirements:

- [ ] **Network Fundamentals & Architecture**
    - **Why Important**: Baseline mental model for packet flow, hierarchy, encapsulation, and debugging.
    - [ ] OSI vs TCP/IP models
    - [ ] Encapsulation/Decapsulation
    - [ ] MTU, MSS, fragmentation
    - [ ] IPv4 vs IPv6 basics
    - [ ] Subnets, masks, prefixes
    - [ ] ARP / NDP

- [ ] **Transport Layer (Deep Focus — heavily asked in HFTs)**
    - **Why Important**: Most interviews drill into TCP mechanics, reliability, congestion control, and latency — essential for systems and trading communication.
    - [ ] TCP handshake & teardown (SYN/SYN-ACK/ACK, FIN/ACK)
    - [ ] TCP reliability: sequence numbers, ACKs, sliding window
    - [ ] Retransmission timeout (RTO), RTT, exponential backoff
    - [ ] Flow control (rwnd)
    - [ ] Congestion control: slow start, congestion avoidance, fast retransmit/recovery
    - [ ] Nagle’s Algorithm, delayed ACKs, silly window syndrome
    - [ ] TCP vs UDP trade-offs
    - [ ] QUIC basics
    - [ ] Common real-world optimizations (TCP_NODELAY, buffer tuning)

- [ ] **Network Layer (IP, Routing, Forwarding)**
    - **Why Important**: Tests understanding of packet forwarding, routing logic, TTL, fragmentation, and real-world internet behavior.
    - [ ] IP addressing and CIDR
    - [ ] Routing algorithms: Distance Vector, Link State
    - [ ] Routing protocols: OSPF, BGP (basics)
    - [ ] NAT & port translation
    - [ ] TTL, ICMP, traceroute
    - [ ] IP fragmentation and reassembly
    - [ ] DHCP, DNS request flow

- [ ] **Data Link Layer (Ethernet, Switching, MAC)**
    - **Why Important**: High-performance systems often require understanding switching delays, MAC learning, collisions, LAN behavior.
    - [ ] Ethernet frames
    - [ ] MAC addressing & ARP table
    - [ ] Switch vs hub behavior
    - [ ] VLANs, STP (basics)
    - [ ] CSMA/CD (conceptual, legacy but asked)
    - [ ] Error detection (CRC)

- [ ] **Application Layer (Real-World Protocol Mechanics)**
    - **Why Important**: Many interviews test HTTP, DNS, gRPC, and REST because real systems depend on them; HFTs ask about DNS latency & caching.
    - [ ] HTTP/1.1 vs HTTP/2 vs HTTP/3
    - [ ] Connection reuse & pipelining
    - [ ] DNS lookup flow + caching
    - [ ] TLS handshake basics
    - [ ] REST vs RPC vs gRPC trade-offs
    - [ ] Common headers & semantics (Host, Keep-Alive, Content-Length)

- [ ] **Sockets & Low-Level Networking (Coding Interviews)**
    - **Why Important**: Shows ability to build real systems; HFTs may ask about kernel buffers, blocking vs non-blocking I/O, epoll/select.
    - [ ] TCP socket lifecycle (bind → listen → accept → read/write)
    - [ ] UDP sockets
    - [ ] Blocking vs non-blocking sockets
    - [ ] epoll/select/poll differences
    - [ ] send/recv vs sendto/recvfrom
    - [ ] Kernel socket buffers & backpressure
    - [ ] Zero-copy optimizations (sendfile, mmap)

- [ ] **Latency, Throughput & Performance**
    - **Why Important**: HFTs obsess over microsecond-level decisions; systems companies test trade-offs and performance tuning.
    - [ ] Bandwidth-delay product
    - [ ] RTT vs throughput
    - [ ] Bufferbloat
    - [ ] Jitter & packet reordering
    - [ ] Congestion vs flow control impact
    - [ ] Tail latency and p99/p999 effects

- [ ] **Packet-Level Debugging & Tools**
    - **Why Important**: Deep engineers must understand what's actually happening on the wire.
    - [ ] tcpdump, Wireshark filters
    - [ ] Inspecting SYN/ACK/FIN packets
    - [ ] Debugging DNS, ARP, retransmissions
    - [ ] Understanding common failure patterns (duplicate ACKs, RSTs)

- [ ] **Network Security Basics**
    - **Why Important**: Interviews often check understanding of secure communication, attacks on transport protocols, and TLS internals.
    - [ ] TLS handshake
    - [ ] MITM, replay attacks
    - [ ] SYN flood, UDP amplification, DDoS patterns
    - [ ] Firewall basics (stateful/stateless)
    - [ ] Authentication & certificates

- [ ] **Distributed Systems Interaction (Lightweight)**
    - **Why Important**: Many companies combine networking + distributed systems questions.
    - [ ] Heartbeats & failure detection
    - [ ] Timeouts & retries
    - [ ] Idempotency
    - [ ] Load balancing (L4 vs L7)
    - [ ] Service discovery, DNS-SRV
