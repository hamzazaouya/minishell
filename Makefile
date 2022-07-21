NAME = minishell
HEADER = minishell.h
SOURCES = main.c  lists/lst_new.c parsing/pars_str.c parsing/creat_cmds.c
SRC_PATH = src
OBJ_PATH  = objs
OBJ_PATH_B = objs_b
LIB_PATH = includes/libft
LIB = $(LIB_PATH)/libft.a
G_NEXT_L = $(G_NEXT_L_PATH)/libft.a
.PHONY:	all clean fclean re bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

OBJS_B = $(addprefix $(OBJ_PATH_B)/,$(SOURCES_B:.c=.o))
.PHONY:	all clean fclean re

all : $(OBJ_PATH) $(NAME)

$(LIB):
	@cd $(LIB_PATH) && make && make clean

$(G_NEXT_L):
	@cd $(G_NEXT_L_PATH) && make && make clean

$(NAME) : $(OBJS) $(LIB)
	$(CC)  $(OBJS) $(LIB) -o  $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c includes/$(HEADER)
	@$(CC)  -c -o  $@ $<

$(OBJ_PATH):
	@mkdir objs
	@mkdir objs/lists
	@mkdir objs/parsing

clean:
	rm -fr $(OBJS)
	rm -fr $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	rm -fr $(OBJ_PATH)
	@cd $(LIB_PATH) && make fclean
re : fclean all
