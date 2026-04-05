# Garuda HLDS – Low Level API (C Runtime)

Garuda HLDS (High-Level Data Structures) is powered by a **Low-Level API (LL-API)** implemented in **C**, forming the foundational runtime layer for core data structures.

This project focuses on building efficient, memory-controlled, and reusable data structures that serve as the backbone for Garuda’s high-level abstractions.

---

## Overview

Garuda follows a layered architecture:

### Low-Level Layer (LL-API)
Implemented in **C**, responsible for:
- Core data structure implementation
- Memory management
- Performance optimization

### High-Level Layer (HLDS)
Exposed within Garuda as abstract data structures, built on top of the LL-API.

---

## Supported Data Structures

The LL-API provides implementations for:

- List  
- Dictionary  
- Set  
- String  
- Priority Queue  
- Heap (Min Heap and Max Heap)  

---

## Design Philosophy

- Performance-focused with minimal overhead  
- Modular and extensible architecture  
- Generic design using low-level abstractions  
- Built to support a programming language runtime  

