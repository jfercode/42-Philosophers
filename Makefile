# Static library name
NAME = build/philo.a

# Compiler and rules
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -pthread

# Directories
SRC_DIR = source
OBJ_DIR = build/obj

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Color macros
RESET    := \033[0m
GREEN    := \033[1;32m
CYAN     := \033[1;36m
YELLOW   := \033[1;33m
RED      := \033[1;31m
BLUE     := \033[1;34m
MAGENTA  := \033[1;35m
WHITE    := \033[1;97m
GRAY     := \033[0;37m
BRIGHT_RED := \033[1;91m

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)CREATING STATIC LIBRARY $@$(RESET)"
	ar rcs $@ $^
	@echo "\$(CYAN)COMPILING AND GENERATE THE EXECUTABLE...$(RESET)"
	$(CC) $(CFLAGS) -o philo $(OBJ_DIR)/main.o $(NAME)

# Rule to compile .c files into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)COMPILING $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files and executables
clean:
		@echo "$(RED)CLEANING OBJECT FILES AND EXECUTABLES...$(RESET)" 
		rm -rf $(OBJ_DIR)
		rm -f ./philo
		@echo "$(GREEN)CLEANING DONE.$(RESET)"

# Rule for full clean
fclean:	clean
		@echo "$(RED)DELETING FILES $(NAME)...$(RESET)"
		rm -f $(NAME)		
		@echo "$(GREEN)ALL CLEANED UP.$(RESET)" 

# Rule to rebuild the project
re:		fclean all
		@echo "$(BLUE)PROJECT REBUILD.$(RESET)"		

# Phony rules
.PHONY:	all clean fclean re