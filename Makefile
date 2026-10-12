################################################################################
#                                     COLORS                                   #
################################################################################

DEFAULT			= \033[0m
RED				= \033[1;31m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
MAGENTA			= \033[1;35m
CYAN			= \033[1;36m
WHITE			= \033[1;37m

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME =			fractol
CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
AR =			ar rcs
RM =			rm -f

################################################################################
#                                PROGRAM'S SOURCES                             #
################################################################################

# Directory paths
SRC =			./srcs/
OBJ =			./objs/
MYLIB_DIR =		./my_lib/
MLX_DIR =		/home/yaabdall/sgoinfre/mlx/
INCLUDES =		./includes/ ./my_lib/includes/ /home/yaabdall/sgoinfre/mlx/


# Libraries
MYLIB =			-L $(MYLIB_DIR) -l:my_lib.a
MLX =			-L $(MLX_DIR) -l:libmlx.a -lXext -lX11 -lm

# Source files
SRCS =			$(SRC)init_fractal.c \
				$(SRC)init_data.c \
				$(SRC)hud.c \
				$(SRC)drawing.c \
				$(SRC)compute_fractals.c \
				$(SRC)event_handlers.c \
				$(SRC)user_controls.c \
				$(SRC)utils.c \
				$(SRC)main.c

# Converts source file paths to object file paths
OBJS =			$(patsubst $(SRC)%, $(OBJ)%, $(SRCS:.c=.o))

################################################################################
#                                     RULES                                    #
################################################################################

# Rule for compiling source files into object files
$(OBJ)%.o:		$(SRC)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@ $(foreach dir,$(INCLUDES),-I$(dir))

# Rule for creating the executable
$(NAME):		$(OBJS)
				@make all --no-print-directory -C $(MYLIB_DIR)
				@echo "$(WHITE)Building $(YELLOW)mlx $(CYAN)library $(DEFAULT)..."
				@make all --no-print-directory -C $(MLX_DIR)
				@echo "$(GREEN)Done $(DEFAULT)✔️"
				@echo "$(WHITE)Linking $(YELLOW)$(NAME) $(CYAN)executable $(DEFAULT)..."
				@$(CC) $(CFLAGS) $(OBJS) $(MYLIB) $(MLX) -o $(NAME)
				@echo "$(GREEN)Done $(DEFAULT)✔️"

# Default rule
all:			$(NAME)

# Bonus rule
bonus:			all

# Rule for cleaning up object files
clean:
				@make clean --no-print-directory -C $(MYLIB_DIR)
				@echo "$(RED)Deleting $(CYAN)project object files $(DEFAULT)..."
				@$(RM) -r $(OBJ)
				@echo "$(GREEN)Done $(DEFAULT)✔️"

# Full clean rule (objects files, executable and libraries)
fclean:
				@make fclean --no-print-directory -C $(MYLIB_DIR)
				@echo "$(RED)Deleting $(CYAN)project object files $(DEFAULT)..."
				@$(RM) -r $(OBJ)
				@echo "$(GREEN)Done $(DEFAULT)✔️"
				@echo "$(RED)Deleting $(YELLOW)$(NAME) $(CYAN)executable $(DEFAULT)..."
				@$(RM) $(NAME)
				@echo "$(GREEN)Done $(DEFAULT)✔️"

# Rebuild rule
re:				fclean all

# Rule to ensure that these targets are always executed as intended, even if there are files with the same name
.PHONY:			all bonus clean fclean re
