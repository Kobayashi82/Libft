# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:40:56 by vzurera-          #+#    #+#              #
#    Updated: 2026/03/11 18:58:25 by vzurera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ──────────── #
# ── COLORS ── #
# ──────────── #

NC    				= \033[0m
RED     			= \033[0;31m
GREEN   			= \033[0;32m
YELLOW  			= \033[0;33m
BLUE    			= \033[0;34m
MAGENTA 			= \033[0;35m
CYAN    			= \033[0;36m
WHITE   			= \033[0;37m
INV_RED  			= \033[7;31m
INV_GREEN	  		= \033[7;32m
INV_YELLOW  		= \033[7;33m
INV_BLUE  			= \033[7;34m
INV_MAGENTA			= \033[7;35m
INV_CYAN			= \033[7;36m
INV_WHITE			= \033[7;37m
BG_CYAN				= \033[40m
FG_YELLOW			= \033[89m
COUNTER 			= 0

# ────────── #
# ── NAME ── #
# ────────── #

NAME		= libft

# ─────────── #
# ── FLAGS ── #
# ─────────── #

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

# ───────────────── #
# ── DIRECTORIES ── #
# ───────────────── #

INC_DIR		= inc/
BLD_DIR		= build/
OBJ_DIR		= $(BLD_DIR)obj/
SRC_DIR		= src/
LIB_DIR		= lib/
TARGET		= $(LIB_DIR)$(NAME).a

# ─────────── #
# ── FILES ── #
# ─────────── #

SRCS		= ft_abs.c			\
			  ft_atoi.c			\
			  ft_atol.c			\
			  ft_atol_base.c	\
			  ft_bzero.c		\
			  ft_calloc.c		\
			  ft_dprintf.c		\
			  ft_isalnum.c		\
			  ft_isalpha.c		\
			  ft_isascii.c		\
			  ft_isdigit.c		\
			  ft_isprint.c		\
			  ft_isspace.c		\
			  ft_itoa.c			\
			  ft_lstadd_back.c	\
			  ft_lstadd_front.c	\
			  ft_lstclear.c		\
			  ft_lstdelone.c	\
			  ft_lstiter.c		\
			  ft_lstlast.c		\
			  ft_lstmap.c		\
			  ft_lstnew.c		\
			  ft_lstsize.c		\
			  ft_max.c			\
			  ft_memchr.c		\
			  ft_memcmp.c		\
			  ft_memcpy.c		\
			  ft_memmove.c		\
			  ft_memset.c		\
			  ft_min.c			\
			  ft_printf.c		\
			  ft_putchar_fd.c	\
			  ft_putendl_fd.c	\
			  ft_putnbr_fd.c	\
			  ft_putstr_fd.c	\
			  ft_realloc.c		\
			  ft_replace.c		\
			  ft_split.c		\
			  ft_strcat.c		\
			  ft_strchr.c		\
			  ft_strcmp.c		\
			  ft_strcpy.c		\
			  ft_strdup.c		\
			  ft_striteri.c		\
			  ft_strjoin.c		\
			  ft_strlcat.c		\
			  ft_strlcpy.c		\
			  ft_strlen.c		\
			  ft_strmapi.c		\
			  ft_strncat.c		\
			  ft_strncmp.c		\
			  ft_strncpy.c		\
			  ft_strndup.c		\
			  ft_strnstr.c		\
			  ft_strrchr.c		\
			  ft_strstr.c		\
			  ft_strtrim.c		\
			  ft_substr.c		\
			  ft_tolower.c		\
			  ft_toupper.c		\
			  get_next_line.c

# ───────────────────────────────────────────────────────────── #
# ─────────────────────────── RULES ─────────────────────────── #
# ───────────────────────────────────────────────────────────── #

all: _show_title
$(TARGET): _show_title

SRC_PATHS	= $(addprefix $(SRC_DIR), $(SRCS))
OBJS		= $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS		= $(OBJS:.o=.d)
-include $(DEPS)

_compile: $(OBJS)
	@$(MAKE) -s _hide_cursor
#	Create folder
	@mkdir -p $(BLD_DIR) $(LIB_DIR)

#	Compile
	@printf "\r%50s\r\t$(CYAN)Compiling... $(YELLOW)$(NAME).a$(NC)"
	@ar rcs $(TARGET) $(OBJS)
	@printf "\r%50s\r\t$(CYAN)Compiled    $(GREEN)✓ $(YELLOW)$(NAME).a$(NC)\n"

	@$(MAKE) -s _progress; printf "\n"
	@$(MAKE) -s _show_cursor

# ───────────── #
# ── OBJECTS ── #
# ───────────── #

-include $(DEPS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MAKE) -s _hide_cursor
#	Create folder
	@mkdir -p $(@D)

#	Compile objects
	@filename=$$(basename $<); filename=$${filename%.*}; \
	BAR=$$(printf "/ — \\ |" | cut -d" " -f$$(($(COUNTER) % 4 + 1))); \
	printf "\r%50s\r\t$(CYAN)Compiling... $(GREEN)$$BAR $(YELLOW)$$filename$(NC)"; \
	$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))
	@$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -o $@ -c $<

# ───────────────── #
# ── EXTRA RULES ── #
# ───────────────── #

_show_title:
	@$(MAKE) -s _hide_cursor
	@$(MAKE) -s _title

#	Check if source exists and needs recompiling
	@if  [ ! -n "$(TARGET)" ] || [ ! -n "$(SRCS)" ] || [ ! -d "$(SRC_DIR)" ]; then \
        printf "\t$(CYAN)Source files don't exist$(NC)"; \
		printf "\n\t$(WHITE)───────────────────────────$(NC)"; \
		$(MAKE) -s _progress; printf "\n" \
		$(MAKE) -s _show_cursor; \
	elif [ -f "$(TARGET)" ] && \
		[ -z "$$(find $(SRC_PATHS) -newer "$(TARGET)" 2>/dev/null; find $(INC_DIR) -name '*.h' -newer "$(TARGET)" 2>/dev/null)" ] && \
		[ $$(find $(OBJS) 2>/dev/null | wc -l) -eq $$(echo "$(OBJS)" | wc -w) ]; then \
		printf "\t$(GREEN)✓ $(YELLOW)$(NAME)$(CYAN) is up to date$(NC)"; \
		printf "\n\t$(WHITE)───────────────────────────$(NC)"; \
		$(MAKE) -s _progress; printf "\n" \
		$(MAKE) -s _show_cursor; \
	else \
		printf "\n\t$(WHITE)───────────────────────────$(NC)\033[1A\r"; \
		$(MAKE) -s _compile; \
	fi
	@$(MAKE) -s _show_cursor

# ───────────────────────────────────────────────────────────── #
# ───────────────────────── RE - CLEAN ─────────────────────────#
# ───────────────────────────────────────────────────────────── #

# ───────────── #
# ── RE-MAKE ── #
# ───────────── #

re:
	@$(MAKE) -s _hide_cursor
	@$(MAKE) -s _title

#	Check if source exists and needs recompiling
	@if  [ ! -n "$(TARGET)" ] || [ ! -n "$(SRCS)" ] || [ ! -d "$(SRC_DIR)" ]; then \
        printf "\t$(CYAN)Source files don't exist$(NC)"; \
		printf "\n\t$(WHITE)───────────────────────────$(NC)"; \
		$(MAKE) -s _progress; \
		$(MAKE) -s _show_cursor; \
	fi

#	Delete objects
	@$(MAKE) -s _delete_objects
	@if [ -f $(TARGET) ]; then \
		printf "\t$(CYAN)Deleting... $(YELLOW)$(NAME).a$(NC)"; \
		rm -f $(TARGET); \
	fi
	@printf "\r%50s\r\t$(CYAN)Deleted     $(GREEN)✓ $(YELLOW)$(NAME).a$(NC)\n"
	@$(MAKE) -s _progress; printf "\n"
	@-find $(BLD_DIR) $(LIB_DIR) -type d -empty -delete >/dev/null 2>&1 || true
	@printf "\t$(WHITE)───────────────────────────\n$(NC)"
	@printf "\033[1A\033[1A\r"

#	Compile
	@$(MAKE) -s _compile

# ─────────── #
# ── CLEAN ── #
# ─────────── #

clean:
	@$(MAKE) -s _hide_cursor
	@$(MAKE) -s _title

	@$(MAKE) -s _delete_objects
	@printf "\r%50s\r\t$(CYAN)Deleted     $(GREEN)✓ $(YELLOW)objects$(NC)\n"

	@$(MAKE) -s _progress; printf "\n"
	@-find $(BLD_DIR) -type d -empty -delete >/dev/null 2>&1 || true
	@$(MAKE) -s _show_cursor

# ──────────── #
# ── FCLEAN ── #
# ──────────── #

fclean:
	@$(MAKE) -s _hide_cursor
	@$(MAKE) -s _title

	@$(MAKE) -s _delete_objects
	@if [ -f $(TARGET) ]; then \
		printf "\t$(CYAN)Deleting... $(YELLOW)$(NAME).a$(NC)"; \
		rm -f $(TARGET); \
	fi
	@printf "\r%50s\r\t$(CYAN)Deleted     $(GREEN)✓ $(YELLOW)$(NAME).a$(NC)\n"
	@find $(BLD_DIR) $(LIB_DIR) -type d -empty -delete >/dev/null 2>&1 || true

	@$(MAKE) -s _progress; printf "\n"
	@$(MAKE) -s _show_cursor

# ──────────── #
# ─── TEST ─── #
# ──────────── #

test: $(TARGET)
	@$(CC) src/main.c $(TARGET) -o test

# ───────────────────────────────────────────────────────────── #
# ───────────────────────── FUNCTIONS ───────────────────────── #
# ───────────────────────────────────────────────────────────── #

# ─────────── #
# ── TITLE ── #
# ─────────── #

_title:
	@clear
	@printf "\n$(NC)\t$(INV_CYAN) $(BG_CYAN)$(FG_YELLOW)★$(INV_CYAN) $(BG_CYAN)$(FG_YELLOW)★$(INV_CYAN) $(BG_CYAN)$(FG_YELLOW)★\
	$(INV_CYAN)     $(NC)$(INV_CYAN)$(shell echo $(NAME) | tr a-z A-Z | tr '_' ' ')$(INV_CYAN)     \
	$(BG_CYAN)$(FG_YELLOW)★$(INV_CYAN) $(BG_CYAN)$(FG_YELLOW)★$(INV_CYAN) $(BG_CYAN)$(FG_YELLOW)★$(INV_CYAN) $(NC)\n"
	@printf "\t$(WHITE)───────────────────────────\n$(NC)"

# ───────────── #
# ── CURSORS ── #
# ───────────── #

_hide_cursor:
	@printf "\e[?25l"

_show_cursor:
	@printf "\e[?25h"

# ──────────────────── #
# ── DELETE OBJECTS ── #
# ──────────────────── #

_delete_objects:
	@printf "\n\t$(WHITE)───────────────────────────$(NC)\033[1A\r"
	@if [ -n "$(shell find $(OBJ_DIR) -type f -name '*.o' 2>/dev/null)" ]; then \
		COUNTER=0; \
		find $(OBJ_DIR) -type f -name '*.o' | while read -r file; do \
			BAR=$$(printf "/ — \\ |" | cut -d" " -f$$((COUNTER % 4 + 1))); \
			filename=$$(basename $$file); \
			srcpath=$$(find $(SRC_DIR) -type f -name "$${filename%.o}.*" 2>/dev/null); \
			if [ -n "$$srcpath" ]; then \
				rm -f $$file $$(dirname $$file)/$${filename%.o}.d; \
				filename=$${filename%.*}; \
				printf "\r%50s\r\t$(CYAN)Deleting... $(GREEN)$$BAR $(YELLOW)$$filename$(NC)"; sleep 0.05; \
				COUNTER=$$((COUNTER+1)); \
			fi; \
		done; \
	fi; printf "\r%50s\r"
	@-find $(BLD_DIR) -type d -empty -delete >/dev/null 2>&1 || true

wipe:
	@rm -rf $(BLD_DIR)
	@rm -rf $(LIB_DIR)

# ─────────────────── #
# ── PROGRESS LINE ── #
# ─────────────────── #

_progress:
	@total=27; printf "\r\t"; for i in $$(seq 1 $$total); do printf "$(RED)─"; sleep 0.01; done; printf "$(NC)"
	@total=27; printf "\r\t"; for i in $$(seq 1 $$total); do printf "─"; sleep 0.01; done; printf "\n$(NC)"

# ─────────── #
# ── PHONY ── #
# ─────────── #

.PHONY: all clean fclean re wipe _show_title _title _hide_cursor _show_cursor _delete_objects _progress test
