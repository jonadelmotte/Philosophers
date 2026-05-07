NAME = philosophers

FILES = main parser \

SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
FLAGS = -Wall -Werror -Wextra

INCLUDE = include/philosophers.h

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF = .cache_exits

$(OBJF):
	mkdir -p $(OBJ_DIR)

vpath %.c $(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -g3 -o $(NAME)

$(OBJ_DIR)%.o: %.c $(INCLUDE) Makefile | $(OBJF)
	$(CC) $(FLAGS) -c -g3 $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re