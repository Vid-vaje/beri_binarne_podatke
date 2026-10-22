CC = gcc
CFLAGS = -Wall -Wextra
SOURCES = $(wildcard *.c)
EXECUTABLES = $(SOURCES:.c=)

.PHONY: all clean

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLES)

help:
	@echo "Available targets:"
	@echo "  all     - compile all .c files to executables"
	@echo "  clean   - remove all executables"
	@echo "  help    - show this help message"
	@echo ""
	@echo "To compile a specific file: make filename (without .c extension)"

