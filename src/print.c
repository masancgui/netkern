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

#include "print.h"

#include <stdarg.h>
#include <stdbool.h>

// The longest representation of an integer is a long in binary.
#define BUF_SIZE (sizeof(long) * 8)

static volatile char *uart = (volatile char *)0x9000000;

static void uart_putchar(char c) {
  *uart = c;
}

static void print_number(long value, bool sign, int radix) {
  unsigned long u;
  if (sign && value < 0) {
    uart_putchar('-');
    u = -value;
  } else {
    u = value;
  }

  int i = 0;
  char buf[BUF_SIZE];

  if (u == 0) {
    buf[i++] = '0';
  } else {
    while (u > 0) {
      buf[i++] = "0123456789abcdef"[u % radix];
      u /= radix;
    }
  }

  while (i > 0) {
    i--;
    uart_putchar(buf[i]);
  }
}

static void print_str(const char *str) {
  while (*str) {
    uart_putchar(*str);
    str++;
  }
}

static void vprint(const char *fmt, va_list args) {
  while (*fmt) {
    if (*fmt == '%') {
      fmt++;

      bool is_long = false;
      if (*fmt == 'l') {
        fmt++;
        is_long = true;
      }

      switch (*fmt) {
        case '%':
          uart_putchar('%');
          break;
        case 'd':
          if (is_long) {
            print_number(va_arg(args, long), true, 10);
          } else {
            print_number(va_arg(args, int), true, 10);
          }
          break;
        case 'x':
          if (is_long) {
            print_number(va_arg(args, unsigned long), false, 16);
          } else {
            print_number(va_arg(args, unsigned int), false, 16);
          }
          break;
        case 's':
          print_str(va_arg(args, char *));
          break;
        default:
          uart_putchar('%');
          if (*fmt) {
            uart_putchar(*fmt);
          }
          break;
      }
    } else {
      uart_putchar(*fmt);
    }

    fmt++;
  }
}

void print(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  vprint(fmt, args);

  va_end(args);
}
