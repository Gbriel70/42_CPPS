#===========================================SETS=====================================#

NAME = FragTrap
COMPILER = c++
FLAGS = -Wall -Wextra -Werror

#===========================================COLORS=====================================#

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m

#===========================================SOURCES=====================================#

SRCS = $(wildcard *.cpp)
OBJ_DIR = object/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

#===========================================RULES=====================================#

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	@${COMPILER} $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@if [ -f $(NAME) ] && [ ! -n "$$(find $(OBJS) -newer $(NAME) 2>/dev/null)" ]; then \
        echo "$(YELLOW)$(NAME) has already been compiled$(YELLOW)"; \
    else \
        echo "$(GREEN)compiling $(NAME)$(YELLOW)"; \
        $(COMPILER) $(FLAGS) -o $(NAME) $(OBJS); \
        echo "$(GREEN)$(NAME) compiled successfully$(YELLOW)"; \
    fi

clean:
	@echo "$(RED)removing $(OBJS)$(YELLOW)"
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) removed successfully$(YELLOW)"

fclean: clean
	rm -f $(NAME)
	@echo "$(GREEN)$(NAME) removed successfully$(YELLOW)"


re: fclean all

.PHONY: all clean fclean re $(OBJ_DIR)