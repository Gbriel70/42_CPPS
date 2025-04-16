#===========================================SETS=====================================#

NAME = Account
COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

#===========================================COLORS=====================================#

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m

#===========================================SOURCES=====================================#

SRC_FILES = $(wildcard *.cpp)
OBJ_DIR = object
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

#===========================================RULES=====================================#

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)$(YELLOW)"
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully$(YELLOW)"

clean:
	@echo "$(RED)Cleaning object files$(YELLOW)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing binary $(NAME)$(YELLOW)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
