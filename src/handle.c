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

#include <stdint.h>

#include "print.h"

struct frame {
  uint64_t x0;
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  uint64_t x13;
  uint64_t x14;
  uint64_t x15;
  uint64_t x16;
  uint64_t x17;
  uint64_t x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  uint64_t x26;
  uint64_t x27;
  uint64_t x28;
  uint64_t x29;
  uint64_t x30;
};

void handle_except(struct frame *frame) {
  print("x0: %lx\n", frame->x0);
  print("x1: %lx\n", frame->x1);
  print("x2: %lx\n", frame->x2);
  print("x3: %lx\n", frame->x3);
  print("x4: %lx\n", frame->x4);
  print("x5: %lx\n", frame->x5);
  print("x6: %lx\n", frame->x6);
  print("x7: %lx\n", frame->x7);
  print("x8: %lx\n", frame->x8);
  print("x9: %lx\n", frame->x9);
  print("x10: %lx\n", frame->x10);
  print("x11: %lx\n", frame->x11);
  print("x12: %lx\n", frame->x12);
  print("x13: %lx\n", frame->x13);
  print("x14: %lx\n", frame->x14);
  print("x15: %lx\n", frame->x15);
  print("x16: %lx\n", frame->x16);
  print("x17: %lx\n", frame->x17);
  print("x18: %lx\n", frame->x18);
  print("x19: %lx\n", frame->x19);
  print("x20: %lx\n", frame->x20);
  print("x21: %lx\n", frame->x21);
  print("x22: %lx\n", frame->x22);
  print("x23: %lx\n", frame->x23);
  print("x24: %lx\n", frame->x24);
  print("x25: %lx\n", frame->x25);
  print("x26: %lx\n", frame->x26);
  print("x27: %lx\n", frame->x27);
  print("x28: %lx\n", frame->x28);
  print("x29: %lx\n", frame->x29);
  print("x30: %lx\n", frame->x30);

  for (;;) {
    asm volatile("wfi");
  }
}
