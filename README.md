# Garuda HLDS – Low Level Libraries (C Runtime)

Garuda HLDS (High-Level Data Structures) is powered by a **Low-Level Library (LL-Lib)** implemented in **C**, forming the foundational runtime layer for core data structures.

This project focuses on building efficient, memory-controlled, and reusable data structures that serve as the backbone for Garuda’s high-level abstractions.

---

## Overview

Garuda follows a layered architecture:

### Low-Level Layer (LL-Lib)
Implemented in **C**, responsible for:
- Core data structure implementation
- Memory management
- Performance optimization

### High-Level Layer (HLDS)
Exposed within Garuda as abstract data structures, built on top of the LL-Lib.

---

## Supported Data Structures

The LL-Lib provides implementations for:

- List, AnyList
- Dictionary, AnyDictionary
- Set  
- String  
- Priority Queue  
- Heap (Min Heap and Max Heap)  

---

## Design Philosophy

- Performance-focused with minimal overhead  
- Modular and extensible architecture  
- Generic design using low-level abstractions  
- Built to support a Garuda programming language runtime  

