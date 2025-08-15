Advent of Modules – Classic Track

Day 17: FixedCapacitySet<T>

Paragraph:
You are tasked with building a set-like container that stores unique elements of type T without using the heap.
This container has a fixed capacity known at compile time, and must be entirely implemented using a static 
buffer or in-place storage — no new, malloc, std::vector, std::unordered_set, etc.

You must support:

Insertion of unique elements.

Query for containment (contains()).

Removal of elements.

Iteration over current elements.

You must not exceed the fixed storage limit. If an insert is attempted after the set is full, return false or signal failure.

Constraints:

You may assume T is trivially copyable and equality-comparable.

Capacity is fixed via a template parameter.

Internals must use a raw buffer, std::array, or similar — no heap allocation.

Insertion must be idempotent — adding an already-present value does nothing and returns false.
