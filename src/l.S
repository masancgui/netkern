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

.section .text.entry

.global _kernel_entry
.type _kernel_entry, %function
_kernel_entry:
  // Set up the stack.
  ldr x0, =__stack_top
  mov sp, x0

  // Clear the BSS section.
  ldr x0, =__bss_start
  ldr x1, =__bss_size
  cbz x1, 2f
1:
  str xzr, [x0], #8
  sub x1, x1, #1
  cbnz x1, 1b

2:
  bl kernel_entry

3:
  wfi
  b 3b
