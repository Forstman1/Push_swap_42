

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
	@./push_swap 2 4 20 6 50 90 12 87 75 45 74 98 100 71 93 29 7 95 27 68 47 5 81 49 82 88 99 51 73 77 14 80 31 67 24