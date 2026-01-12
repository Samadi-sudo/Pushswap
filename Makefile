CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME_BONUS = checker

SRC =	ft_push_swap.c \
	parsing/parse.c \
	parsing/split.c \
	parsing/to_int.c \
	metodes/ft_push.c \
	metodes/ft_reverse_rotate.c \
	metodes/ft_rotate.c \
	metodes/ft_swap.c \
	Algo/indexing.c \
	Algo/algo_utils.c \
	Algo/baterfly.c \
	Algo/small_sort.c

SRC_BONUS = checker_bonus/checker.c \
			checker_bonus/checker_utils.c \
			parsing/parse.c \
			parsing/split.c \
			parsing/to_int.c \
			checker_bonus/metodes/ft_push_bonus.c \
			checker_bonus/metodes/ft_reverse_rotate_bonus.c \
			checker_bonus/metodes/ft_rotate_bonus.c \
			checker_bonus/metodes/ft_swap_bonus.c \
			checker_bonus/get_next_line/get_next_line_utils.c \
			checker_bonus/get_next_line/get_next_line.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
