PRJ_NAME := blinkled

CUR_PATH :=.
BIN_DIR := $(CUR_PATH)/bin 
INC_DIR := $(CUR_PATH)/inc 
SRC_DIR := $(CUR_PATH)/src
OBJ_DIR := $(CUR_PATH)/obj 
LIB_DIR := $(CUR_PATH)/lib 

LIB_SHARE_DIR := $(LIB_DIR)/shared 
LIB_STATIC_DIR := $(LIB_DIR)/static

creat_obj:
	gcc -c -fPIC $(SRC_DIR)/CheckFolderBrightness.c -o $(OBJ_DIR)/CheckFolderBrightness.o
	gcc -c -fPIC $(SRC_DIR)/CheckFolderTrigger.c -o $(OBJ_DIR)/CheckFolderTrigger.o
	gcc -c -fPIC $(CUR_PATH)/blinkled.c -o $(OBJ_DIR)/blinkled.o -I $(INC_DIR)
creat_lib:
	gcc -shared $(OBJ_DIR)/CheckFolderBrightness.o $(OBJ_DIR)/CheckFolderTrigger.o -o $(LIB_SHARE_DIR)/lib$(PRJ_NAME).so

install_lib:
	cp -f $(LIB_SHARE_DIR)/lib$(PRJ_NAME).so /usr/lib

all: creat_obj creat_lib install_lib
	gcc  $(OBJ_DIR)/blinkled.o -L$(LIB_SHARE_DIR) -l$(PRJ_NAME) -o $(BIN_DIR)/use-shared-library

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(LIB_SHARE_DIR)/lib$(PRJ_NAME).so
	rm -rf $(BIN_DIR)/user-shared-library

