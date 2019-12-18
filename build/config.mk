
#Compiler and Linker
CC          := g++-7

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
CFLAGS      := -fopenmp -Wall -O3 -g
LIB         := -fopenmp -lm 
INC         := -I$(INCDIR) -I/usr/local/include
INCDEP      := -I$(INCDIR)