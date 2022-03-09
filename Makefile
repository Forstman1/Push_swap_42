

CFILES  = push_swap.c sa_pa_ra_rra.c sb_pb_rb_rrb.c ss_rr_rrr.c push_swap_utils.c sorting.c sorting_utils.c

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
	@./push_swap 65 13 19 20 34 27 70 38 33 61 32 51 57 15 50 48 28 66 69 18 21 39 42 31 55 11 22 26 46 17 56 16 35 23 10 25 36 58 12 44 45 29 64 52 37 67 53 49 63 30 62 54 14 24 59 47 40 68 60 41 43