NAME = philo

FILES = main parser \

SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
FLAGS = -Wall -Werror -Wextra -pthread 

INCLUDE = include/philosophers.h

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF = .cache_exits

GREEN = \033[0;92m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0;39m

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@echo -e "$(BLUE)Obj directory created$(RESET)"

vpath %.c $(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -g3 -o $(NAME)
	@echo -e "$(GREEN)Philosophers compiled !!$(RESET)"

$(OBJ_DIR)%.o: %.c $(INCLUDE) Makefile | $(OBJF)
	@$(CC) $(FLAGS) -c -g3 $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo -e "$(YELLOW)Obj destroyed !!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(YELLOW)Executable destroyed !!$(RESET)"

re: fclean all

.PHONY: all clean fclean re