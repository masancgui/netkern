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

#include "arm.h"
#include "gicv2.h"
#include "physmem.h"
#include "print.h"
#include "timer.h"

static void load_vec_table(void) {
  extern char vec_table[];
  write_vbar_el1((uint64_t)vec_table);
}

void kernel_entry(void) {
  load_vec_table();
  gic_init();

  // Unmask IRQ exceptions.
  asm volatile("msr daifclr, #2");

  physmem_init();
  print("Netkern entry\n");

  timer_init();

  halt_forever();
}
