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

#include "arm.h"
#include "gicv2.h"

void timer_init(void) {
  gic_enable(TIMER_IRQ);
  timer_set();

  // Enable the timer.
  write_cntp_ctl_el0(1);
}

void timer_set(void) {
  uint64_t freq = read_cntfrq_el0();
  write_cntp_tval_el0(freq);
}
