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

#include "gic.h"

#include <stdint.h>

#include "timer.h"
#include "types.h"

// Thanks to this blog
// https://lowenware.com/blog/aarch64-gic-and-timer-interrupt/

#define GICD_BASE UL(0x8000000)
#define GICD_CTLR 0x0000
#define GICD_ISENABLER 0x0100

#define GICC_BASE UL(0x8010000)
#define GICC_CTLR 0x0000
#define GICC_PMR 0x0004

void gic_init(void) {
  // Enable the distributor and CPU interface.
  *(volatile uint32_t *)(GICD_BASE + GICD_CTLR) = 1;
  *(volatile uint32_t *)(GICC_BASE + GICC_CTLR) = 1;

  // Set the lowest priority.
  *(volatile uint32_t *)(GICC_BASE + GICC_PMR) = 0xff;

  // TODO: select the correct set-enable register.
  *(volatile uint32_t *)(GICD_BASE + GICD_ISENABLER) = 1 << TIMER_IRQ;
}
