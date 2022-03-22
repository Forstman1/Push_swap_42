

CFILES  = push_swap.c sa_pa_ra_rra.c sb_pb_rb_rrb.c ss_rr_rrr.c \
			push_swap_utils.c sorting.c sorting_utils.c sorting_optimazed.c \
			sa_pa_ra_rra_opt.c sb_pb_rb_rrb_opt.c pushtostackb.c \
			pushtostackb_utils.c parsing.c push_swap_utils2.c

OFILES	= $(CFILES:.c=.o)

CBONUS = checker/parsing_bonus.c checker/sa_pa_ra_rra_bonus.c checker/sb_pb_rb_rrb_bonus.c checker_utils.c checker/moves_utils.c checker/ss_rr_rrr_bonus.c

OBONUS = $(CBONUS:.c=.o)

CC	= gcc
INT	= push_swap.h
NAME = push_swap.a

all : $(NAME)

$(NAME) : $(OFILES) push_swap.c
	make -C libft
	@ar -rc $(NAME) $(OFILES) libft/libft.a
	@$(CC) push_swap.c push_swap.a libft/libft.a -o push_swap

%.o:%.c
	@$(CC) -o $@ -c $<
	@echo "$@ been created"


clean:
	@rm -f $(OFILES)

fclean:	clean
	@rm -f  $(NAME) $(OBONUS)

re: fclean all

bonus: $(OBONUS) checker_bonus.c
	@make -C libft
	@$(CC) checker_bonus.c $(OBONUS) checker/checker.h libft/libft.a

execute: $(NAME) push_swap.c
	@./push_swap -1121591983 -1928934132 1068561763 -196721848 2047683031