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

#ifndef NETKERN_MISC_H_
#define NETKERN_MISC_H_

#ifdef __ASSEMBLER__
#define UL(x) x
#else
#define UL(x) x##UL
#endif

#define TCR_T0SZ_48BIT (UL(16) << 0)
#define TCR_TG0_4KIB (UL(0) << 14)
#define TCR_T1SZ_48BIT (UL(16) << 16)
#define TCR_TG1_4KIB (UL(2) << 30)

#define TCR_VALUE \
  (TCR_TG1_4KIB | TCR_T1SZ_48BIT | TCR_TG0_4KIB | TCR_T0SZ_48BIT)

#define PTE_VALID (UL(1) << 0)
#define PTE_BLOCK (UL(0) << 1)
#define PTE_TABLE (UL(1) << 1)
#define PTE_ACCESS (UL(1) << 10)

#define PTE_TABLE_FLAGS (PTE_TABLE | PTE_VALID)
#define PTE_BLOCK_FLAGS(idx) (PTE_ACCESS | ((idx) << 2) | PTE_BLOCK | PTE_VALID)

#define SCTLR_MMU_ENABLE (UL(1) << 0)

#endif
