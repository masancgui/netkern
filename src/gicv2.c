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

#include "gicv2.h"

#include <stdint.h>

#include "types.h"

// Thanks to this blog
// https://lowenware.com/blog/aarch64-gic-and-timer-interrupt/

#define GICD_BASE UL(0x8000000)
#define GICD_CTLR 0x0000
#define GICD_ISENABLER 0x0100

#define GICD_CTLR_ENABLE (U(1) << 0)

#define GICC_BASE UL(0x8010000)
#define GICC_CTLR 0x0000
#define GICC_PMR 0x0004
#define GICC_IAR 0x000c
#define GICC_EOIR 0x0010

#define GICC_CTLR_ENABLE (U(1) << 0)
#define GICC_IAR_MASK 0x3ff

void gic_init(void) {
  // Enable the distributor and CPU interface.
  *(volatile uint32_t *)(GICD_BASE + GICD_CTLR) = GICD_CTLR_ENABLE;
  *(volatile uint32_t *)(GICC_BASE + GICC_CTLR) = GICC_CTLR_ENABLE;

  // Set the lowest priority.
  *(volatile uint32_t *)(GICC_BASE + GICC_PMR) = 0xff;
}

void gic_enable(uint32_t id) {
  volatile uint32_t *regs = (volatile uint32_t *)(GICD_BASE + GICD_ISENABLER);
  regs[id / 32] = 1U << (id % 32);
}

uint32_t gic_iar(void) {
  return *(volatile uint32_t *)(GICC_BASE + GICC_IAR) & GICC_IAR_MASK;
}

void gic_eoi(uint32_t id) {
  *(volatile uint32_t *)(GICC_BASE + GICC_EOIR) = id;
}
