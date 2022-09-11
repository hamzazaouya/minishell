RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
BLUE := \033[0;34m

NAME = minishell
#SIG  = `stty -echoctl`
HEADER = minishell.h
SOURCES = minishell.c lexer/lexer.c lexer/token.c lexer/string.c lexer/expand.c  \
			aid_funcs/funcs1.c aid_funcs/free.c aid_funcs/error.c  aid_funcs/function_use_libft.c\
			parsing/parce.c parsing/parce_free.c parsing/herdoc.c parsing/open_redire.c parsing/cmds.c \
			builtins/cd.c builtins/echo.c builtins/env.c builtins/exit.c \
			builtins/pwd.c builtins/unset.c builtins/export.c \
			env/initial_env.c signal/signal.c \
			execution/exec.c
SRC_PATH = src
OBJ_PATH  = obj
LIB_PATH = include/libft
LIB = $(LIB_PATH)/libft.a
READLINE_DIR = ~/goinfre/.brew/opt/readline/
.PHONY:	all clean fclean re bonus

CC = cc
#CFLAGS = -Wall -Wextra -Werror 

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))


all : $(OBJ_PATH) $(NAME)
	@echo "$(BLUE)\n        :::   :::   ::::::::::: ::::    ::: ::::::::::: ::::::::  :::    ::: :::::::::: :::        :::  \n      :+:+: :+:+:      :+:     :+:+:   :+:     :+:    :+:    :+: :+:    :+: :+:        :+:        :+:   \n    +:+ +:+:+ +:+     +:+     :+:+:+  +:+     +:+    +:+        +:+    +:+ +:+        +:+        +:+    \n   +#+  +:+  +#+     +#+     +#+ +:+ +#+     +#+    +#++:++#++ +#++:++#++ +#++:++#   +#+        +#+     \n  +#+       +#+     +#+     +#+  +#+#+#     +#+           +#+ +#+    +#+ +#+        +#+        +#+      \n #+#       #+#     #+#     #+#   #+#+#     #+#    #+#    #+# #+#    #+# #+#        #+#        #+#       \n###       ### ########### ###    #### ########### ########  ###    ### ########## ########## ##########$(WHITE)\n\n\t\t$(RED)By$(WHITE):\n\t\t\t$(GREEN)Larbi Benalla $(WHITE)($(RED)Lmzoudi$(WHITE)) : $(BLUE)https://github.com/lbenalla $(WHITE)\n\t\t\t$(GREEN)Hamza Zaouya\t$(WHITE)($(RED)Mr_Y$(WHITE))  : $(BLUE)https://github.com/hamzazaouya$(WHITE)\n"

$(LIB):
	@cd $(LIB_PATH) && make && make clean

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(SIG) -lreadline -I $(READLINE_DIR)include -L $(READLINE_DIR)lib $(LIB) $(OBJS) -o  $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c include/$(HEADER)
	@$(CC) -I $(READLINE_DIR)include  -c -o  $@ $<

$(OBJ_PATH):
	@mkdir obj
	@mkdir obj/parsing/
	@mkdir obj/lexer
	@mkdir obj/aid_funcs
	@mkdir obj/builtins
	@mkdir obj/env
	@mkdir obj/signal
	@mkdir obj/execution

clean:
	rm -fr $(OBJS)
	rm -fr $(OBJ_PATH)

fclean: clean
	@cd $(LIB_PATH) && make fclean
	rm -f $(NAME)
	rm -fr $(OBJ_PATH)
re : fclean all
