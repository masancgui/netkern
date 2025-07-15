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
  .align 7
  b .
  .align 7
  b .

.global load_vec_table
.type load_vec_table, %function
load_vec_table:
  adr x0, vec_table
  msr vbar_el1, x0
  ret
