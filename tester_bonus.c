#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list {
  void *data;
  struct s_list *next;
} t_list;

// libasm bonus
extern void ft_list_push_front(t_list **list, t_list *new);
extern size_t ft_list_size(t_list *list);
extern void ft_list_remove_if(t_list **list, void *data_ref, int (*cmp)(),
                              void (*free_f)(void *));
extern void ft_list_sort(t_list **begin_list, int (*cmp)());
extern int ft_atoi_base(char *str, char *base);

void print_list(t_list *list) {
  size_t len;

  len = 0;
  printf("List contents: \n");
  while (list) {
    ++len;
    printf("[%zu]: %s\n", len, (char *)list->data);
    list = list->next;
  }
  printf("Size of list: %zu\n", len);
}

void free_list(void *ptr) {
  t_list **list = (t_list **)ptr;
  t_list *node;
  t_list *next;

  if (!list)
    return;
  next = *list;
  while (next) {
    node = next;
    next = node->next;
    free(node->data);
    free(node);
  }
  *list = NULL;
}

void ft_free(void *ptr) {
  free(ptr);
}

int ft_strcmp(char *str1, char *str2) {
  size_t i = 0;
  while (str1[i] == str2[i] && str1[i])
    ++i;
  return (str1[i] - str2[i]);
}

static const char *test1 = "Test sample string";
static const char *test2 = "Another sample string";
static const char *test3 = "Quick brown fox jumps over the lazy dog.";
static const char *test4 = "Pls remove this";
static const char *test5 = "Sudo remove this !!";

void populate_list(t_list **list) {
  t_list *node;

  node = malloc(sizeof(t_list));
  node->data = strdup(test1);
  node->next = NULL;
  ft_list_push_front(list, node);
  node = malloc(sizeof(t_list));
  node->data = strdup(test2);
  node->next = NULL;
  ft_list_push_front(list, node);
  node = malloc(sizeof(t_list));
  node->data = strdup(test3);
  node->next = NULL;
  ft_list_push_front(list, node);
  node = malloc(sizeof(t_list));
  node->data = strdup(test4);
  node->next = NULL;
  ft_list_push_front(list, node);
  node = malloc(sizeof(t_list));
  node->data = strdup(test5);
  node->next = NULL;
  ft_list_push_front(list, node);
}

void populate_list_rep(t_list **list) {
  t_list *node;

  node = malloc(sizeof(t_list));
  node->data = strdup(test1);
  node->next = NULL;
  ft_list_push_front(list, node);
  node = malloc(sizeof(t_list));
  node->data = strdup(test1);
  node->next = NULL;
  ft_list_push_front(list, node);
  node = malloc(sizeof(t_list));
  node->data = strdup(test1);
  node->next = NULL;
  ft_list_push_front(list, node);
  node = malloc(sizeof(t_list));
  node->data = strdup(test1);
  node->next = NULL;
  ft_list_push_front(list, node);
  node = malloc(sizeof(t_list));
  node->data = strdup(test1);
  node->next = NULL;
  ft_list_push_front(list, node);
}

int test_atoi_base(void) {
  static char *bin = "01";
  static char *oct = "01234567";
  static char *dec = "0123456789";
  static char *hex = "0123456789abcdef";
  // bad input
  static char *plus = "0123+";
  static char *space = "abc_ \\0/";
  static char *tab = "0123456\t";
  static char *single = "1";
  static char *empty = "";

  int res;

  if (ft_atoi_base("42", plus) || ft_atoi_base("42", space) \
    || ft_atoi_base("42", tab) || ft_atoi_base("42", single) \
    || ft_atoi_base("42", empty)) {
    printf("%s\n", "Failed ft_atoi_base with invalid base");
    return (1);
  }
  res = ft_atoi_base("101010", bin);
  printf("Bin: %d\n", res);
  res = ft_atoi_base("52", oct);
  printf("Oct: %d\n", res);
  res = ft_atoi_base("42", dec);
  printf("Dec: %d\n", res);
  res = ft_atoi_base("2a", hex);
  printf("Hex: %d\n", res);
  res = ft_atoi_base("", dec);
  printf("Empty: %d\n", res);
  res = ft_atoi_base("  --++-2a", hex);
  printf("Negative: %d\n", res);
  return (0);
}

int main(void) {
  t_list *list;

  list = NULL;
  if (ft_list_size(list)) {
    printf("%s\n", "Empty list size wrong.");
  }
  populate_list(&list);
  print_list(list);
  printf("List size: %zu | expected: %d\n", ft_list_size(list), 5);
  ft_list_remove_if(&list, (void *)test4, &ft_strcmp, &ft_free);
  print_list(list);
  printf("List size: %zu | expected: %d\n", ft_list_size(list), 4);
  ft_list_remove_if(&list, (void *)test5, &ft_strcmp, &ft_free);
  print_list(list);
  printf("List size: %zu | expected: %d\n", ft_list_size(list), 3);
  ft_list_remove_if(&list, (void *)test1, &ft_strcmp, &ft_free);
  print_list(list);
  printf("List size: %zu | expected: %d\n", ft_list_size(list), 2);
  ft_list_remove_if(&list, (void *)test2, &ft_strcmp, &ft_free);
  print_list(list);
  printf("List size: %zu | expected: %d\n", ft_list_size(list), 1);
  ft_list_remove_if(&list, (void *)test3, &ft_strcmp, &ft_free);
  print_list(list);
  printf("List size: %zu | expected: %d\n", ft_list_size(list), 0);
  free_list(&list);
  list = NULL;
  if (ft_list_size(list))
    printf("%s\n", "Empty list size wrong");
  populate_list_rep(&list);
  print_list(list);
  printf("List size: %zu | expected: %d\n", ft_list_size(list), 5);
  ft_list_remove_if(&list, (void *)test2, &ft_strcmp, &ft_free);
  printf("List size: %zu | expected: %d\n", ft_list_size(list), 5);
  ft_list_remove_if(&list, (void *)test1, &ft_strcmp, &ft_free);
  printf("List size: %zu | expected: %d\n", ft_list_size(list), 0);
  free_list(&list);
  list = NULL;
  populate_list(&list);
  print_list(list);
  ft_list_sort(&list, &ft_strcmp);
  print_list(list);
  free_list(&list);
  list = NULL;
  if (test_atoi_base())
    return (1);
  return (0);
}
