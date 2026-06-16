I've developed a customized version of Fenwick's Tree, a Segment Tree data structure tailored for efficient range queries. The code includes a streamlined approach, featuring a flexible mapping system for seamless adaptation to different operations such as sum, min, max, gcd, and xor.

It's worth noting that while both the segment tree and the lazy propagation tree share the same time complexity, the segment tree excels in individual point updates, whereas the lazy propagation tree is notably superior in handling range updates efficiently. The primary objective of this implementation is to provide a versatile data structure capable of managing diverse range queries and updates with optimal performance.

Time Complexities:
- Build: *O(n)*
- Query: *O(log n)*
- Update: *O(log n)*
