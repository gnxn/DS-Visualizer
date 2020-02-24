
#Compiler and Linker
CC          := g++

#The Target Binary Program
TARGET      := ds_vis

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := $(ENV_DIR)/src
INCDIR      := $(ENV_DIR)/inc
BUILDDIR    := $(ENV_DIR)/obj
TARGETDIR   := $(ENV_DIR)/bin

SRCEXT      := cpp
DEPEXT      := d
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -std=c++14 -Werror=vla -MMD -g
LIB         := -lm 
INC         := -I$(INCDIR) -I/usr/local/include
INCDEP      := -I$(INCDIR)