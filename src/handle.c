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

#include "arm.h"
#include "gicv2.h"
#include "print.h"
#include "timer.h"

struct regs {
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

void handle_except(struct regs *regs) {
  print("x0: %lx\n", regs->x0);
  print("x1: %lx\n", regs->x1);
  print("x2: %lx\n", regs->x2);
  print("x3: %lx\n", regs->x3);
  print("x4: %lx\n", regs->x4);
  print("x5: %lx\n", regs->x5);
  print("x6: %lx\n", regs->x6);
  print("x7: %lx\n", regs->x7);
  print("x8: %lx\n", regs->x8);
  print("x9: %lx\n", regs->x9);
  print("x10: %lx\n", regs->x10);
  print("x11: %lx\n", regs->x11);
  print("x12: %lx\n", regs->x12);
  print("x13: %lx\n", regs->x13);
  print("x14: %lx\n", regs->x14);
  print("x15: %lx\n", regs->x15);
  print("x16: %lx\n", regs->x16);
  print("x17: %lx\n", regs->x17);
  print("x18: %lx\n", regs->x18);
  print("x19: %lx\n", regs->x19);
  print("x20: %lx\n", regs->x20);
  print("x21: %lx\n", regs->x21);
  print("x22: %lx\n", regs->x22);
  print("x23: %lx\n", regs->x23);
  print("x24: %lx\n", regs->x24);
  print("x25: %lx\n", regs->x25);
  print("x26: %lx\n", regs->x26);
  print("x27: %lx\n", regs->x27);
  print("x28: %lx\n", regs->x28);
  print("x29: %lx\n", regs->x29);
  print("x30: %lx\n", regs->x30);

  halt_forever();
}

void handle_irq(struct regs *regs) {
  (void)regs;

  uint32_t iar = gic_iar();
  switch (iar) {
    case TIMER_IRQ:
      print("Timer tick\n");
      timer_set();
      gic_eoi(iar);
      break;
    default:
      panic("Unknown IRQ\n");
      break;
  }
}
