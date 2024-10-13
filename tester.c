/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 07:22:07 by mcutura           #+#    #+#             */
/*   Updated: 2024/08/29 22:08:52 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// libasm
extern size_t ft_strlen(char const *str);
extern char *ft_strcpy(char *dest, char const *src);
extern int ft_strcmp(char const *s1, char const *s2);
extern ssize_t ft_write(int fd, char const *buf, size_t count);
extern ssize_t ft_read(int fd, char *buf, size_t count);
extern char *ft_strdup(char const *s);

// testing
#include "test_cases.c"

#define CPY_BUFF 256
#define READ_BUF 256

int test_ft_strlen(void);
int test_ft_strcpy(void);
int test_ft_strcmp(void);
int test_ft_write(void);
int test_ft_read(void);
int test_ft_strdup(void);

int main(void) {
  int res;

  res = 0;
  res |= test_ft_strlen();
  res |= test_ft_strcpy();
  res |= test_ft_strcmp();
  res |= test_ft_write();
  res |= test_ft_read();
  res |= test_ft_strdup();
  printf("Test libasm: %s\n", res ? "FAILED" : "PASSED");
  return (res);
}

static inline int test(size_t a, size_t b, int n_test) {
  printf("[%s] Test %d\n", a == b ? "OK" : "KO", n_test);
  return (a != b);
}

int test_ft_strlen(void) {
  int i;
  int r;

  printf("Test ft_strlen\n");
  r = 0;
  i = 0;
  while (i < N_SAMPLES) {
    r |= test(ft_strlen(g_teststr[i]), strlen(g_teststr[i]), i);
    ++i;
  }
  return (r);
}

int test_ft_strcpy(void) {
  int i;
  int r;
  char dest1[CPY_BUFF];
  char dest2[CPY_BUFF];

  printf("Test ft_strcpy\n");
  r = 0;
  i = 0;
  while (i < N_SAMPLES) {
    r |= test((size_t)ft_strcpy(dest1, g_teststr[i]), (size_t)dest1, i);
    if (strcmp(dest1, strcpy(dest2, g_teststr[i]))) {
      r |= 1;
      printf("[KO] Test %d\n copy: %s\n expected: %s\n", i, dest1, dest2);
    }
    ++i;
  }
  return (r);
}

int test_ft_strcmp(void) {
  int r;
  int i;
  int t;

  printf("Test ft_strcmp\n");
  r = 0;
  i = -1;
  t = 0;
  while (++i < N_SAMPLES) {
    r |= test(ft_strcmp(g_teststr[i], g_teststr[i]),
              strcmp(g_teststr[i], g_teststr[i]), t++);
  }
  while (--i) {
    r |= test(ft_strcmp(g_teststr[i - 1], g_teststr[i]),
              strcmp(g_teststr[i - 1], g_teststr[i]), t++);
  }
  while (i < N_SAMPLES) {
    r |= test(ft_strcmp(g_teststr[i], g_teststr[N_SAMPLES - i - 1]),
              strcmp(g_teststr[i], g_teststr[N_SAMPLES - i - 1]), t++);
    ++i;
  }
  return (r);
}

int test_ft_write(void) {
  ssize_t std_result;
  ssize_t asm_result;
  int r;
  int i;
  int err;

  printf("Test ft_write\n");
  i = 0;
  r = 0;
  while (i < N_SAMPLES) {
    r |= test((size_t)ft_write(1, g_teststr[i], strlen(g_teststr[i])),
              (size_t)write(1, g_teststr[i], strlen(g_teststr[i])), i);
    ++i;
  }
  errno = 0;
  asm_result = ft_write(-1, g_teststr[1], strlen(g_teststr[1]));
  err = errno;
  errno = 0;
  std_result = write(-1, g_teststr[1], strlen(g_teststr[1]));
  if (err != errno) {
    printf("[KO] errno not correctly set\n");
    r |= 1;
  } else
    printf("[OK] Test errno\n");
  return (r);
}

int test_ft_read(void) {
  int r;
  int err;
  int fd = open("test.gdb", O_RDONLY);
  char buf1[READ_BUF];
  char buf2[READ_BUF];

  printf("Test ft_read\n");
  r = 0;
  ssize_t ft = ft_read(fd, buf1, READ_BUF);
  close(fd);
  fd = open("test.gdb", O_RDONLY);
  ssize_t og = read(fd, buf2, READ_BUF);
  if (memcmp(buf1, buf2, og)) {
    r |= 1;
    printf("[KO] wrong read\n");
  } else
    r |= test((size_t)ft, (size_t)og, 0);
  close(fd);
  errno = 0;
  ft_read(-1, buf1, READ_BUF);
  err = errno;
  errno = 0;
  read(-1, buf2, READ_BUF);
  if (err != errno) {
    printf("[KO] errno not correctly set\n errno: %d\n Expected: %d\n", err,
           errno);
    r |= 1;
  } else
    printf("[OK] Test errno\n");
  return (r);
}

int test_ft_strdup(void) {
  int i;
  int r;
  char *cpy;

  printf("Test ft_strdup\n");
  r = 0;
  i = 0;
  while (i < N_SAMPLES) {
    cpy = ft_strdup(g_teststr[i]);
    if (strcmp(g_teststr[i], cpy)) {
      r |= 1;
      printf("[KO] Test %d\n", i);
    } else
      printf("[OK] Test %d\n", i);
    free(cpy);
    ++i;
  }
  return (r);
}
