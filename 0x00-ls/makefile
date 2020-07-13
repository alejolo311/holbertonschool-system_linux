CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
OBJDIR = obj
SRCDIR = .
SRC := $(shell find $(SRCDIR) -name "*.c")
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	@mkdir -p '$(@D)'
	@$(CC) -c $(CFLAGS) $< -o $@

APP = ls

all: $(APP)

$(APP): $(OBJ)
	@echo "== LINKING EXECUTABLE $(APP)"
	@$(CC) $^ $(CFLAGS) -o $(APP)

%.o: %.c
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	find . -name *.o -delete
	rm -f $(APP)