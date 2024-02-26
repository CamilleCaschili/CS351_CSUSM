CC = g++

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c\
	   map.c

OBJS = $(SRCS:.c=.o)

EXEC = myProgram

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

all: $(EXEC)

$(EXEC): $(OBJS)
	@echo "$(YELLOW)Linking object files...$(NC)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Build successful!$(NC)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up...$(NC)"
	rm -f $(OBJS) $(EXEC)
	@echo "$(GREEN)Cleanup complete!$(NC)"
