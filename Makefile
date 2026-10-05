CC ?= cc
CFLAGS ?= -std=c99 -Wall -Wextra -Werror -pedantic -Iinclude

BUILD := build
LIBOBJ := $(BUILD)/reference_renderer.o
TEST := $(BUILD)/test_reference

.PHONY: all test clean

all: $(TEST)

$(BUILD):
	mkdir -p $(BUILD)

$(LIBOBJ): src/reference_renderer.c include/ami3d/renderer.h include/ami3d/scene.h include/ami3d/reference_renderer.h | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST): tests/test_reference.c $(LIBOBJ) | $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@

test: $(TEST)
	./$(TEST)
	test -s m0-reference.ppm

clean:
	rm -rf $(BUILD) m0-reference.ppm
