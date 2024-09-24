TARGET = testTask

CC = gcc
DB = gdb

OBJ_DIR = build/obj
OUT_DIR = build/out

SRC = main.c TaylorSin/taylorSin.c
INC = TaylorSin/

OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
vpath %.c $(sort $(dir $(SRC)))

CFLAGS = -Wall -g -O2 -I$(INC) -std=c11 

all: $(TARGET)

$(OBJ_DIR) $(OUT_DIR):
	mkdir -p $(OBJ_DIR) $(OUT_DIR)

$(TARGET): $(OBJ) | $(OUT_DIR)
	$(CC) $(CFLAGS) -o $(OUT_DIR)/$@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)

rebuild: clean all

debug:
	$(DB) $(OUT_DIR)/$(TARGET)

.PHONY: all clean rebuild debug