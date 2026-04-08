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

typedef struct priority_queue_f64
{
  double array[CAPACITY];
  int size;
} pq_f64;

void offer_f64_heap(double value, pq_f64 **heap_ref, int heap_order)
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
      double temp = (*heap_ref)->array[current];
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
      double temp = (*heap_ref)->array[current];
      int parent = (current - 1) / 2;
      (*heap_ref)->array[current] = (*heap_ref)->array[parent];
      (*heap_ref)->array[parent] = temp;
      current = parent;
    }
  }
  (*heap_ref)->size++;
}

double poll_f64_heap(pq_f64 **heap_ref, int heap_order)
{
  if ((*heap_ref)->size == 0)
    return -1;

  double root = (*heap_ref)->array[0];

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

    double temp = (*heap_ref)->array[index];
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
//   pq_f64 *m2 = (pq_f64 *)malloc(sizeof(pq_f64));
//   int m2_heap_order = 1;
//   m2->size = 0;
//   // HEAP-Order: 0 is MIN,
//   // HEAP-Order: 1 is MAX

//   // m.offer(1)
//   offer_f64_heap(1.23, &m2, m2_heap_order);
//   // m.offer(3)
//   offer_f64_heap(3.423, &m2, m2_heap_order);
//   // m.offer(2)
//   offer_f64_heap(3.23, &m2, m2_heap_order);
//   // m.offer(7)
//   offer_f64_heap(8.23, &m2, m2_heap_order);
//   // m.offer(6)
//   offer_f64_heap(6.23, &m2, m2_heap_order);
//   // e = m.poll()
//   double F = poll_f64_heap(&m2, m2_heap_order);
//   printf("%.10f\n--\n", F);

//   // m.offer(16)
//   offer_f64_heap(16.97, &m2, m2_heap_order);
//   while ((F = poll_f64_heap(&m2, m2_heap_order)) != -1)
//   {
//     printf("%.10f\n", F);
//   }
// }