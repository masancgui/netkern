/*
 * Copyright (C) 2025 masancgui
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "physmem.h"

#include <stddef.h>
#include <stdint.h>

#include "arm.h"
#include "print.h"

struct node {
  struct node *next;
};

extern char __end[];
static struct node *list;

void physmem_free(void *page) {
  struct node *node = page;
  node->next = list;
  list = node;
}

void *physmem_alloc(void) {
  if (list == NULL) {
    panic("Exhausted memory\n");
  }

  void *ptr = list;
  list = list->next;
  return ptr;
}

void physmem_init(void) {
  uintptr_t addr = (uintptr_t)__end - HIGHER_HALF;
  for (; addr < PHYS_END; addr += PAGE_SIZE) {
    physmem_free((void *)addr);
  }
}
