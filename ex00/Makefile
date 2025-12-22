NAME = ClapTrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I .
NORELINK = -MMD -MP
RM = rm -rf

BUILDDIR = obj
SRCS = ClapTrap.cpp\
	main.cpp

OBJS = $(SRCS:%.cpp=$(BUILDDIR)/%.o)
DEPS = $(OBJS:.o=.d)

MAKEFLAGS += --no-print-directory

.DEFAULT_GOAL = all  # Set default goal to make all

# Base rule
all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(GREY)🔨 "
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@printf "\n $(GREEN)✅ Build done!$(RESET)\n"

# Relink prevention for linked projects
FORCE:
$(BUILDDIR)/%.o: %.cpp
	@printf "$(GREY)🔨 "
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(NORELINK) -c $< -o $@
	@printf "$(RESET)"

debug: fclean
	@$(MAKE) all CC=g++

clean:
	@printf "$(RED)🗑️  "
	$(RM) $(BUILDDIR)
	@printf "$(RESET)\n"

fclean: clean
	@printf "$(RED)🗑️  "
	$(RM) $(NAME)
	@printf "$(RESET)\n"

re: fclean all

-include $(DEPS)

.PHONY: all FORCE clean fclean re

# COLORS
RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
GREY = \033[1;90m