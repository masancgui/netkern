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
#include "mmu.h"

START_FUNC(_boot_stub)
  // Clear the boot page tables.
  ldr x0, =__boot_pt_l0
  mov x1, #4096
  bl memzero64

  ldr x0, =__boot_pt_l1
  mov x1, #4096
  bl memzero64

  // Index 0 for device memory.
  // Index 1 for normal memory.
  mov x0, #0x000000000000ff00
  msr mair_el1, x0

  ldr x0, =TCR_VALUE
  msr tcr_el1, x0

  ldr x0, =__boot_pt_l0
  ldr x1, =__boot_pt_l1

  ldr x2, =PTE_TABLE_FLAGS
  orr x2, x1, x2
  str x2, [x0]

  // Map 0x00000000-0x3fffffff as device memory.
  ldr x2, =PTE_BLOCK_FLAGS(0)
  str x2, [x1]

  // Map 0x40000000-0x80000000 as normal memory.
  ldr x2, =0x40000000
  ldr x3, =PTE_BLOCK_FLAGS(1)
  orr x2, x2, x3
  str x2, [x1, #8]

  // Allow access from lower and higher half.
  msr ttbr0_el1, x0
  msr ttbr1_el1, x0

  mrs x2, sctlr_el1
  orr x2, x2, SCTLR_MMU_ENABLE
  msr sctlr_el1, x2

  // Sync.
  isb

  ldr x0, =_kernel_entry
  br x0
END_FUNC(_boot_stub)

START_FUNC(_kernel_entry)
  // Set up the stack.
  ldr x0, =__stack_top
  mov sp, x0

  // Clear the BSS section.
  ldr x0, =__bss_start
  ldr x1, =__bss_size
  bl memzero64

  // And jump into C code.
  bl kernel_entry

1:
  wfi
  b 1b
END_FUNC(_kernel_entry)

START_PRIV_FUNC(memzero64)
  cbz x1, 2f
1:
  str xzr, [x0], #8
  sub x1, x1, #8
  cbnz x1, 1b

2:
  ret
END_FUNC(memzero64)
