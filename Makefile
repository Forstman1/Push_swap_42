

CFILES  = push_swap.c sa_pa_ra_rra.c sb_pb_rb_rrb.c ss_rr_rrr.c push_swap_utils.c sorting.c sorting_utils.c sorting_optimazed.c sa_pa_ra_rra_opt.c sb_pb_rb_rrb_opt.c pushtostackb.c

OFILES	= $(CFILES:.c=.o)

CC	= gcc
INT	= push_swap.h
NAME = push_swap.a

all : $(NAME)

$(NAME) : $(OFILES) push_swap.c
	@ar -rc $(NAME) $(OFILES)
	@$(CC) push_swap.c push_swap.a -o push_swap

%.o:%.c
	@$(CC) -o $@ -c $<
	@echo "$@ been created"


clean:
	@rm -f $(OFILES)

fclean:	clean
	@rm -f  $(NAME) 

execute: $(NAME) push_swap.c
	@./push_swap 42 38 17 29 15 25 18 16 3 41 32 37 49 40 23 44 34 4 7 27 20 36 28 47 8 33 10 6 13 1 5 19 31 22 14 9 45 11 30 26 24 50 12 2 35 48 39 21 43 46