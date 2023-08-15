# Name of the output file
TARGET = output

# List all the C source files
SOURCES = $(wildcard src/*.c)

# Directories to be searched for header files
INCLUDE_DIRS = -I./include

# Default rule
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(INCLUDE_DIRS) -o $@ $^

# Clean rule to remove the compiled output
clean:
	rm -f $(TARGET)
