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

#ifndef NETKERN_ASMACROS_H_
#define NETKERN_ASMACROS_H_

#ifdef __ASSEMBLER__
// clang-format off
#define START_FUNC(name) \
  .global name;          \
  .type name, %function; \
  name:

#define START_PRIV_FUNC(name) \
  .type name, %function;      \
  name:

#define END_FUNC(name) \
  .size name, .-name
// clang-format on
#endif

#endif
