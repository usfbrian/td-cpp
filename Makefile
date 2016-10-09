CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/TowerDefense
TESTTARGET := bin/test

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -std=c++14 -g -Wall -Wextra -pedantic
LDFLAGS := -std=c++14
LIB := -L lib
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $(LDFLAGS) $^ -o $(TARGET) $(LIB)"; $(CC) $(LDFLAGS) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " Compiling..."
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) $(TESTTARGET)"; $(RM) -r $(BUILDDIR) $(TARGET) $(TESTTARGET)

test:
	@echo " Generating Test..."
	@echo " $(CC) $(CFLAGS) tests/tests.cpp $(INC) $(LIB) -o $(TESTTARGET)"; $(CC) $(CFLAGS) tests/tests.cpp $(INC) $(LIB) -o $(TESTTARGET)

.PHONY: clean
