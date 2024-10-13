# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 01:52:12 by mcutura           #+#    #+#              #
#    Updated: 2024/10/09 00:03:46 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libasm.a

SRCS := ft_strlen ft_write ft_read ft_strcpy ft_strcmp ft_strdup
BONUSSRC := ft_list_push_front ft_list_size ft_list_remove_if ft_list_sort
BONUSSRC += ft_atoi_base

TESTER := tester
BONUSTESTER := tester_bonus

AS := nasm
ASFLAGS := -f elf64

AR := ar
ARFLAGS := rcs

CC := cc
CFLAGS := -Wall -Wextra -Werror -ggdb3
LDFLAGS := -L. -lasm

# Colors
blk := \033[01;30m
red := \033[01;31m
grn := \033[01;32m
ylw := \033[01;33m
blu := \033[01;34m
mag := \033[01;35m
cyn := \033[01;36m
wht := \033[01;37m
clr := \033[00m

.PHONY: all bonus clean fclean re check check-mandatory check-bonus debug help

$(NAME): $(SRCS:%=%.o)
	$(AR) $(ARFLAGS) $(NAME) $(SRCS:%=%.o)

%.o: %.s
	$(AS) $(ASFLAGS) $^ -o $@

all: $(NAME) bonus	# Compile all targets
bonus: $(BONUSSRC:%=%.o)	# Compile and add bonus to the library
	$(AR) $(ARFLAGS) $(NAME) $(BONUSSRC:%=%.o)
clean:	# Remove compiled binary object files
	$(RM) $(SRCS:%=%.o) main.o $(BONUSSRC:%=%.o)
fclean: clean	# Remove all compiled binaries
	$(RM) $(NAME) $(TESTER) $(BONUSTESTER)
re: fclean all	# Re-compile all targets

check: check-mandatory check-bonus
	@echo "$(grn)[OK] All tests PASSED$(clr)"

check-mandatory: $(TESTER)	# Run automated tests on the target
	@(./$(TESTER) && echo "$(grn)[OK] Mandatory tests PASS$(clr)") \
	|| (echo "$(red)[KO] Test libasm FAIL$(clr)"; exit 1)
$(TESTER): $(NAME) $(TESTER).c
	$(CC) $(CFLAGS) $(TESTER).c -o $(TESTER) $(LDFLAGS)

check-bonus: $(BONUSTESTER)	# Run automated tests on bonus target
	@(./$(BONUSTESTER) && echo "$(grn)[OK] Bonus tests PASS$(clr)") \
	|| (echo "$(red)[KO] Test libasm bonus FAIL$(clr)"; exit 1)
$(BONUSTESTER): bonus $(BONUSTESTER).c
	$(CC) $(CFLAGS) $(BONUSTESTER).c -o $(BONUSTESTER) $(LDFLAGS)

debug: $(TESTER)	# Run tester in gdb
	@gdb --tui --command=test.gdb

help:	# Display this helpful message
	@awk 'BEGIN { \
	FS = ":.*#"; printf "Usage:\n\t$(cyn)make $(mag)<target> \
	$(clr)\n\nTargets:\n"; } \
	/^[a-zA-Z_0-9-]+:.*?#/ { \
	printf "$(mag)%-16s$(cyn)%s$(clr)\n", $$1, $$2 } ' \
	Makefile
