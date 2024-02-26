CC = g++

CFLAGS = -Wall -Wextra -Werror

SRCS_C = c_files/main.c\
	   c_files/map.c

SRCS_CPP = cpp_files/main2.cpp\
	   cpp_files/labrador.cpp\
	   cpp_files/dogs.cpp

OBJS_C = $(SRCS_C:.c=.o)
OBJS_CPP = $(SRCS_CPP:.cpp=.o)

EXEC_C = myProgram_c
EXEC_CPP = myProgram_cpp

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

all: $(EXEC_C) $(EXEC_CPP)

$(EXEC_C): $(OBJS_C)
	@echo "$(YELLOW)Linking object files for $(EXEC_C)...$(NC)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Build successful for $(EXEC_C)!$(NC)"

$(EXEC_CPP): $(OBJS_CPP)
	@echo "$(YELLOW)Linking object files for $(EXEC_CPP)...$(NC)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Build successful for $(EXEC_CPP)!$(NC)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	@echo "$(YELLOW)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up...$(NC)"
	rm -f $(OBJS_C) $(OBJS_CPP) $(EXEC_C) $(EXEC_CPP)
	@echo "$(GREEN)Cleanup complete!$(NC)"
