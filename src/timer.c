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

#include "timer.h"

#include <stdint.h>

void timer_init(void) {
  uint64_t freq;
  asm volatile("mrs %0, cntfrq_el0" : "=r"(freq));
  asm volatile("msr cntp_tval_el0, %0" : : "r"(freq));

  // Enable the timer.
  asm volatile("msr cntp_ctl_el0, %0" : : "r"(1));
}
