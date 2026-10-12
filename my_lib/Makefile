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

NAME =			my_lib.a
CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
AR =			ar rcs
RM =			rm -f

################################################################################
#                                PROGRAM'S SOURCES                             #
################################################################################

# Directory paths
LIBFT =			./srcs/libft/
FT_PRINTF =		./srcs/ft_printf/
GNL =			./srcs/get_next_line/
SRC =			./srcs/
OBJ =			./objs/
INCLUDES =		./includes/

# Source files
SRCS =	       	$(LIBFT)ft_ftoa.c \
				$(LIBFT)ft_atof.c \
				$(LIBFT)ft_strchr.c \
        	    $(LIBFT)ft_split.c \
        	    $(LIBFT)ft_strtrim.c \
        	    $(LIBFT)ft_bzero.c \
        	    $(LIBFT)ft_strnstr.c \
        	    $(LIBFT)ft_strmapi.c \
        	    $(LIBFT)ft_isprint.c \
        	    $(LIBFT)ft_atoi.c \
        	    $(LIBFT)ft_strdup.c \
        	    $(LIBFT)ft_tolower.c \
        	    $(LIBFT)ft_toupper.c \
        	    $(LIBFT)ft_substr.c \
        	    $(LIBFT)ft_striteri.c \
        	    $(LIBFT)ft_memchr.c \
        	    $(LIBFT)ft_putnbr_fd.c \
        	    $(LIBFT)ft_strlcpy.c \
        	    $(LIBFT)ft_itoa.c \
        	    $(LIBFT)ft_memset.c \
        	    $(LIBFT)ft_calloc.c \
        	    $(LIBFT)ft_strlen.c \
        	    $(LIBFT)ft_putchar_fd.c \
        	    $(LIBFT)ft_isascii.c \
        	    $(LIBFT)ft_strlcat.c \
        	    $(LIBFT)ft_putendl_fd.c \
        	    $(LIBFT)ft_memcmp.c \
        	    $(LIBFT)ft_isdigit.c \
        	    $(LIBFT)ft_strrchr.c \
        	    $(LIBFT)ft_putstr_fd.c \
        	    $(LIBFT)ft_isalpha.c \
        	    $(LIBFT)ft_strncmp.c \
        	    $(LIBFT)ft_isalnum.c \
        	    $(LIBFT)ft_memcpy.c \
        	    $(LIBFT)ft_memmove.c \
        	    $(LIBFT)ft_strjoin.c \
				$(LIBFT)ft_lstadd_back_bonus.c \
        	    $(LIBFT)ft_lstsize_bonus.c \
				$(LIBFT)ft_lstlast_bonus.c \
				$(LIBFT)ft_lstiter_bonus.c \
				$(LIBFT)ft_lstmap_bonus.c \
        	    $(LIBFT)ft_lstnew_bonus.c \
				$(LIBFT)ft_lstadd_front_bonus.c \
        	    $(LIBFT)ft_lstdelone_bonus.c \
				$(LIBFT)ft_lstclear_bonus.c \
        	    $(FT_PRINTF)ft_printf.c \
				$(FT_PRINTF)ft_nbrlen.c \
        	    $(FT_PRINTF)ft_printhex.c \
        	    $(FT_PRINTF)ft_check_format.c \
        	    $(FT_PRINTF)ft_printchar.c \
        	    $(FT_PRINTF)ft_itoa_m.c \
        	    $(FT_PRINTF)ft_printptr.c \
        	    $(FT_PRINTF)ft_xtoa.c \
        	    $(FT_PRINTF)ft_printint.c \
        	    $(FT_PRINTF)ft_putstr_fd_m.c \
        	    $(FT_PRINTF)ft_isflag.c \
        	    $(FT_PRINTF)ft_pad.c \
        	    $(FT_PRINTF)ft_flag_start.c \
        	    $(FT_PRINTF)ft_printstr.c \
        	    $(FT_PRINTF)ft_printuns.c \
        	    $(FT_PRINTF)ft_hexlen.c \
        	    $(FT_PRINTF)ft_istype.c \
        	    $(FT_PRINTF)ft_putchar_fd_m.c \
        	    $(FT_PRINTF)ft_utoa.c \
        	    $(FT_PRINTF)ft_isspec.c \
        	    $(FT_PRINTF)ft_isconv.c \
				$(GNL)get_next_line.c \
				$(GNL)get_next_line_utils.c \
    	        $(GNL)get_next_line_bonus.c \
    	        $(GNL)get_next_line_utils_bonus.c

# Converts source file paths to object file paths
OBJS = $(patsubst $(SRC)%, $(OBJ)%, $(SRCS:.c=.o))

################################################################################
#                                     RULES                                    #
################################################################################

# Rule for compiling source files into object files
$(OBJ)%.o:		$(SRC)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)


# Rule for creating the library
$(NAME):		$(OBJS)
				@echo "$(WHITE)Building $(YELLOW)$(NAME) $(CYAN)library $(DEFAULT)..."
				@$(AR) $(NAME) $(OBJS)
				@echo "$(GREEN)Done $(DEFAULT)✔️"

# Default rule
all:			$(NAME)

# Bonus rule
bonus:			all

# Rule for cleaning up object files
clean:
				@echo "$(RED)Deleting $(YELLOW)$(NAME) $(CYAN)object files $(DEFAULT)..."
				@$(RM) -r $(OBJ)
				@echo "$(GREEN)Done $(DEFAULT)✔️"

# Full clean rule (objects files and library)
fclean:			clean
				@echo "$(RED)Deleting $(YELLOW)$(NAME) $(CYAN)library $(DEFAULT)..."
				@$(RM) $(NAME)
				@echo "$(GREEN)Done $(DEFAULT)✔️"

# Rebuild rule
re:				fclean all

# Rule to ensure that these targets are always executed as intended, even if there are files with the same name
.PHONY:			all bonus clean fclean re