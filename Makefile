

CFILES  = push_swap.c sa_pa_ra_rra.c sb_pb_rb_rrb.c ss_rr_rrr.c push_swap_utils.c

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
	@./push_swap 1 2 3 4 5 6 7 8 9