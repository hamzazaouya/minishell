NAME = minishell
HEADER = minishell.h
SOURCES = minishell.c lexer/lexer.c lexer/token.c lexer/string.c lexer/expand.c  \
			aid_funcs/funcs1.c aid_funcs/free.c aid_funcs/error.c  aid_funcs/function_use_libft.c\
			parsing/parce.c parsing/parce_free.c \
			builtins/cd.c builtins/echo.c builtins/env.c builtins/exit.c \
			builtins/pwd.c builtins/unset.c builtins/export.c \
			env/initial_env.c 
SRC_PATH = src
OBJ_PATH  = obj
LIB = include/libft.a
.PHONY:	all clean fclean re bonus

CC = cc
#CFLAGS = -Wall -Wextra -Werror 

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))


all : $(OBJ_PATH) $(NAME)

$(NAME) : $(OBJS) 
	$(CC) -lreadline $(LIB) $(OBJS) -o  $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c include/$(HEADER)
	@$(CC)  -c -o  $@ $<

$(OBJ_PATH):
	@mkdir obj
	@mkdir obj/parsing/
	@mkdir obj/lexer
	@mkdir obj/aid_funcs
	@mkdir obj/builtins
	@mkdir obj/env

clean:
	rm -fr $(OBJS)
	rm -fr $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	rm -fr $(OBJ_PATH)
re : fclean all
