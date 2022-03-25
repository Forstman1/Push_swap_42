

CFILES  = push_swap.c sa_pa_ra_rra.c sb_pb_rb_rrb.c ss_rr_rrr.c \
			push_swap_utils.c sorting.c sorting_utils.c sorting_optimazed.c \
			sa_pa_ra_rra_opt.c sb_pb_rb_rrb_opt.c pushtostackb.c \
			pushtostackb_utils.c parsing.c push_swap_utils2.c othercases.c other_utils.c

OFILES	= $(CFILES:.c=.o)

CBONUS = checker/parsing_bonus.c checker/sa_pa_ra_rra_bonus.c checker/sb_pb_rb_rrb_bonus.c checker_utils.c checker/moves_utils.c checker/ss_rr_rrr_bonus.c

OBONUS = $(CBONUS:.c=.o)

BONUS_NAME = checker_bonus

FLAGS = -Wall -Werror -Wextra
CC	= gcc
INT	= push_swap.h
NAME = push_swap.a

all : $(NAME)

$(NAME) : $(OFILES) push_swap.c
	make -C libft
	@ar -rc $(NAME) $(OFILES) libft/libft.a
	@$(CC) $(FLAGS) push_swap.c push_swap.a libft/libft.a -o push_swap -g

%.o:%.c
	@$(CC) -o $@ -c $<
	@echo "$@ been created"


clean:
	@rm -f $(OFILES)

fclean:	clean
	@rm -f  $(NAME) $(OBONUS) 

re: fclean all

bonus: $(OBONUS) checker/checker.h checker_bonus.c
	@make -C libft
	@$(CC) $(FLAGS) checker_bonus.c $(OBONUS) libft/libft.a -o $(BONUS_NAME)

execute: $(NAME) push_swap.c
	@./push_swap 999093108 676157134 -12839455 -1308176269 1607225920