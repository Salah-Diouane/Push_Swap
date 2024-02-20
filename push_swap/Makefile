NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/push_swap.c \
	  mandatory/moves_1.c \
	  mandatory/moves_2.c \
	  mandatory/moves_3.c \
	  mandatory/parsing.c \
	  mandatory/parsing_utils1.c \
	  mandatory/parsing_utils2.c \
	  mandatory/parsing_utils3.c \
	  mandatory/parsing_utils4.c \
	  mandatory/is_sorted.c \
	  mandatory/sort_five.c \
	  mandatory/sort_three.c \
	  mandatory/ft_index.c \
	  mandatory/set_moves.c \
	  mandatory/set_moves_utils.c \
	  mandatory/sort_all.c \
	  mandatory/sort_all_utils.c \
	  mandatory/moves_types.c \

SRC_BONUS = bonus/push_swap_bonus.c \
			bonus/push_swap_bonus_utils.c \
	  		bonus/moves_1_bonus.c \
	  		bonus/moves_2_bonus.c \
	  		bonus/moves_3_bonus.c \
	  		bonus/parsing_bonus.c \
	  		bonus/parsing_utils1_bonus.c \
	  		bonus/parsing_utils2_bonus.c \
	  		bonus/parsing_utils3_bonus.c \
	  		bonus/parsing_utils4_bonus.c \
	  		bonus/get_next_line.c \
	  		bonus/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS) 
	@$(CC) $(OBJ_BONUS) -o $(NAME_BONUS)

all: $(NAME)

%.o : %.c mandatory/push_swap.h bonus/push_swap_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@ rm -rf $(NAME) $(NAME_BONUS)

re: fclean all
