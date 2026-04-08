/*
 * Copyright (c) 2026, National Federation for Research in Advanced Computation (NFRAC)
 *
 * This file is part of the Garuda Programming Language.
 *
 * Garuda is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * Garuda is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 * https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * Author: Er. P. Rohit V. Acharya
 */
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 128 // 512 bytes

typedef struct priority_queue_i32
{
  int array[CAPACITY];
  int size;
} pq_i32;

void offer_i32_heap(int value, pq_i32 **heap_ref, int heap_order)
{
  int current = (*heap_ref)->size;
  if (current >= CAPACITY)
    return;
  (*heap_ref)->array[current] = value;
  // Bubble-Up
  if (heap_order == 0) // Min-Heap
  {
    while (current > 0 && (*heap_ref)->array[current] < (*heap_ref)->array[(current - 1) / 2])
    {
      int temp = (*heap_ref)->array[current];
      int parent = (current - 1) / 2;
      (*heap_ref)->array[current] = (*heap_ref)->array[parent];
      (*heap_ref)->array[parent] = temp;
      current = parent;
    }
  }
  else // Max-Heap
  {
    while (current > 0 && (*heap_ref)->array[current] > (*heap_ref)->array[(current - 1) / 2])
    {
      int temp = (*heap_ref)->array[current];
      int parent = (current - 1) / 2;
      (*heap_ref)->array[current] = (*heap_ref)->array[parent];
      (*heap_ref)->array[parent] = temp;
      current = parent;
    }
  }
  (*heap_ref)->size++;
}

int poll_i32_heap(pq_i32 **heap_ref, int heap_order)
{
  if ((*heap_ref)->size == 0)
    return -1;

  int root = (*heap_ref)->array[0];

  (*heap_ref)->array[0] = (*heap_ref)->array[(*heap_ref)->size - 1];
  (*heap_ref)->size--;

  // Bubble down
  int index = 0;
  while (1)
  {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int target = index;

    if (heap_order == 0) // Min-heap
    {
      if (left < (*heap_ref)->size && (*heap_ref)->array[left] < (*heap_ref)->array[target])
        target = left;
      if (right < (*heap_ref)->size && (*heap_ref)->array[right] < (*heap_ref)->array[target])
        target = right;
    }
    else // Max-heap
    {
      if (left < (*heap_ref)->size && (*heap_ref)->array[left] > (*heap_ref)->array[target])
        target = left;
      if (right < (*heap_ref)->size && (*heap_ref)->array[right] > (*heap_ref)->array[target])
        target = right;
    }

    if (target == index)
      break;

    int temp = (*heap_ref)->array[index];
    (*heap_ref)->array[index] = (*heap_ref)->array[target];
    (*heap_ref)->array[target] = temp;

    index = target;
  }

  return root;
}
// void main()
// {
//   // PriorityQueue-API
//   // heap_pq<int> m = new heap_pq<MAX>()
//   pq_i32 *m = (pq_i32 *)malloc(sizeof(pq_i32));
//   int m_heap_order = 1;
//   m->size = 0;
//   // HEAP-Order: 0 is MIN,
//   // HEAP-Order: 1 is MAX

//   // m.offer(1)
//   offer_i32_heap(1, &m, m_heap_order);
//   // m.offer(3)
//   offer_i32_heap(3, &m, m_heap_order);
//   // m.offer(2)
//   offer_i32_heap(2, &m, m_heap_order);
//   // m.offer(7)
//   offer_i32_heap(7, &m, m_heap_order);
//   // m.offer(6)
//   offer_i32_heap(6, &m, m_heap_order);
//   // e = m.poll()
//   int e = poll_i32_heap(&m, m_heap_order);
//   printf("%d\n--\n", e);

//   // m.offer(16)
//   offer_i32_heap(16, &m, m_heap_order);
//   while ((e = poll_i32_heap(&m, m_heap_order)) != -1)
//   {
//     printf("%d\n", e);
//   }
// }