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

#include "asmacros.h"

.macro save_regs
  stp x30, xzr, [sp, #-16]!
  stp x28, x29, [sp, #-16]!
  stp x26, x27, [sp, #-16]!
  stp x24, x25, [sp, #-16]!
  stp x22, x23, [sp, #-16]!
  stp x20, x21, [sp, #-16]!
  stp x18, x19, [sp, #-16]!
  stp x16, x17, [sp, #-16]!
  stp x14, x15, [sp, #-16]!
  stp x12, x13, [sp, #-16]!
  stp x10, x11, [sp, #-16]!
  stp x8, x9, [sp, #-16]!
  stp x6, x7, [sp, #-16]!
  stp x4, x5, [sp, #-16]!
  stp x2, x3, [sp, #-16]!
  stp x0, x1, [sp, #-16]!
.endm

.macro restore_regs
  ldp x0, x1, [sp], #16
  ldp x2, x3, [sp], #16
  ldp x4, x5, [sp], #16
  ldp x6, x7, [sp], #16
  ldp x8, x9, [sp], #16
  ldp x10, x11, [sp], #16
  ldp x12, x13, [sp], #16
  ldp x14, x15, [sp], #16
  ldp x16, x17, [sp], #16
  ldp x18, x19, [sp], #16
  ldp x20, x21, [sp], #16
  ldp x22, x23, [sp], #16
  ldp x24, x25, [sp], #16
  ldp x26, x27, [sp], #16
  ldp x28, x29, [sp], #16
  ldp x30, xzr, [sp], #16
.endm

// The alignment of the vector table is 0x800, and the alignment of each entry
// is 0x80.
.global vec_table
.align 11
vec_table:
  b .
  .align 7
  b .
  .align 7
  b .
  .align 7
  b .

  .align 7
  b _handle_sync
  .align 7
  b _handle_irq
  .align 7
  b .
  .align 7
  b .

  .align 7
  b .
  .align 7
  b .
  .align 7
  b .
  .align 7
  b .

  .align 7
  b .
  .align 7
  b .
  .align 7
  b .
  .align 7
  b .

START_PRIV_FUNC(_handle_sync)
  save_regs

  mov x0, sp
  bl handle_sync

  restore_regs

  eret
END_FUNC(_handle_sync)

START_PRIV_FUNC(_handle_irq)
  save_regs

  mov x0, sp
  bl handle_irq

  restore_regs

  eret
END_FUNC(_handle_irq)
