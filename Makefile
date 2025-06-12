# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 21:17:42 by igyuveni          #+#    #+#              #
#    Updated: 2024/12/15 00:00:00 by igyuveni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = libft.a

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
TESTDIR = tests

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)
AR = ar rcs
RM = rm -f

# Source files using wildcard for automatic detection
STRING_SRCS =	$(wildcard $(SRCDIR)/string/*.c)
MEMORY_SRCS =	$(wildcard $(SRCDIR)/memory/*.c)
CHAR_SRCS =		$(wildcard $(SRCDIR)/character/*.c)
CONV_SRCS =		$(wildcard $(SRCDIR)/conversion/*.c)
OUTPUT_SRCS =	$(wildcard $(SRCDIR)/output/*.c)
LIST_SRCS =		$(wildcard $(SRCDIR)/list/*.c)
PRINTF_SRCS =	$(wildcard $(SRCDIR)/printf/*.c)
GNL_SRCS =		$(wildcard $(SRCDIR)/get_next_line/*.c)
UTILS_SRCS =	$(wildcard $(SRCDIR)/utils/*.c)

# All source files (automatically includes all .c files in subdirectories)
SRCS = $(STRING_SRCS) $(MEMORY_SRCS) $(CHAR_SRCS) $(CONV_SRCS) $(OUTPUT_SRCS) \
       $(LIST_SRCS) $(PRINTF_SRCS) $(GNL_SRCS) $(UTILS_SRCS)

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Colors for pretty output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Progress tracking
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

# Rules
all: header progress_start $(NAME) footer

header:
	@echo "$(BLUE)╔══════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BLUE)║$(RESET)                    $(PURPLE)📚 LIBFT COMPILATION$(RESET)                    $(BLUE)║$(RESET)"
	@echo "$(BLUE)╚══════════════════════════════════════════════════════════════╝$(RESET)"
	@echo "$(CYAN)🚀 Compiling $(TOTAL_FILES) source files across 8 categories...$(RESET)"
	@echo ""

progress_start:
	@echo "$(YELLOW)Progress:$(RESET)"

$(NAME): $(OBJS)
	@printf "\r$(GREEN)🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩$(RESET) $(GREEN)[100%%] ✨ All files compiled!$(RESET)\n"
	@echo ""
	@echo "$(GREEN)📦 Creating library $(NAME)...$(RESET)"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✅ Library $(NAME) created successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@$(eval PROGRESS=$(shell echo "$(CURRENT_FILE)*100/$(TOTAL_FILES)" | bc))
	@$(eval FILLED=$(shell echo "$(PROGRESS)/10" | bc))
	@$(eval EMPTY=$(shell echo "10-$(FILLED)" | bc))
	@$(eval CATEGORY=$(shell echo $< | cut -d'/' -f2))
	@$(eval FILENAME=$(notdir $<))
	@printf "\r$(GREEN)"
	@for i in $$(seq 1 $(FILLED)); do printf "🟩"; done
	@printf "$(WHITE)"
	@for i in $$(seq 1 $(EMPTY)); do printf "⬜"; done
	@printf "$(RESET) $(CYAN)[$(PROGRESS)%%]$(RESET) $(YELLOW)$(CATEGORY)$(RESET)/$(PURPLE)$(FILENAME)$(RESET)     "
	@$(CC) $(CFLAGS) -c $< -o $@

footer:
	@echo ""
	@echo "$(GREEN)🎉 Compilation completed successfully!$(RESET)"
	@echo "$(BLUE)📊 Total: $(TOTAL_FILES) files compiled | Library: $(NAME) ready$(RESET)"
	@echo "$(PURPLE)═══════════════════════════════════════════════════════════════$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/string $(OBJDIR)/memory $(OBJDIR)/character
	@mkdir -p $(OBJDIR)/conversion $(OBJDIR)/output $(OBJDIR)/list
	@mkdir -p $(OBJDIR)/printf $(OBJDIR)/get_next_line $(OBJDIR)/utils

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJDIR)
	@echo "$(YELLOW)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)Removing library...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(RED)✓ Library removed!$(RESET)"

re: fclean all

# Test compilation and execution
test: $(NAME)
	@echo ""
	@echo "$(BLUE)🧪 Compiling comprehensive test suite...$(RESET)"
	@$(CC) $(CFLAGS) -L. -lft $(TESTDIR)/test.c -o libft_test
	@echo "$(GREEN)🚀 Running comprehensive tests...$(RESET)"
	@echo ""
	@./libft_test
	@echo ""
	@echo "$(BLUE)🧹 Cleaning up test executable...$(RESET)"
	@rm -f libft_test

# Show project structure
show:
	@echo "$(PURPLE)Project Structure:$(RESET)"
	@tree -I '__pycache__|*.pyc|*.o|*.a' || ls -la

# Help
help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Build the complete libft library (includes everything)"
	@echo "  $(GREEN)clean$(RESET)   - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  - Remove object files and library"
	@echo "  $(GREEN)re$(RESET)      - Rebuild everything"
	@echo "  $(GREEN)test$(RESET)    - Compile tests (if available)"
	@echo "  $(GREEN)show$(RESET)    - Show project structure"
	@echo "  $(GREEN)help$(RESET)    - Show this help message"
	@echo ""
	@echo "$(PURPLE)Library includes:$(RESET)"
	@echo "  • String manipulation functions"
	@echo "  • Memory management functions"
	@echo "  • Character classification functions"
	@echo "  • Type conversion functions"
	@echo "  • Output functions"
	@echo "  • Linked list functions"
	@echo "  • ft_printf (formatted output)"
	@echo "  • get_next_line (file reading)"
	@echo "  • Utility functions (digit counting, word counting, array freeing)"

.PHONY: all clean fclean re test show help header footer progress_start