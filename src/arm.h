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

#ifndef NETKERN_ARM_H_
#define NETKERN_ARM_H_

#include "types.h"

#define PHYS_START UL(0x40000000)
// It would be better to parse the device tree and get the memory node instead
// of hardcoding this.
#define PHYS_END (PHYS_START + 16 * 1024 * 1024)

#define PAGE_SIZE 4096

void halt_forever(void) __attribute__((noreturn));

#endif
