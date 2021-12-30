#use hashtag to denote a comment, comment MUST be on a separate line from any code
#use make to call it in the terminal
#must be in the build directory when calling it

#must point to where the source files exist 
SRCDIR=../finalProject/finalProject

INCLUDE=-I/opt/homebrew/include/

# Compilation Flags
CFLAGS=-std=c++11 $(INCLUDE)
# Linking Flags
LFLAGS=-L/opt/homebrew/lib -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

CC=g++

.PHONY : all
all : minecraftSupreme

#when adding more .o files, add a space after main.o and put the newFile.o there
#e.g. OBJS=main.o newFile.o

OBJS=main.o 


#when adding more .o files, copy this formatting 
#newFile.o : $(SRCDIR)/newFile.cpp
#	    $(CC) $(CFLAGS) -c $<

main.o : $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $<

minecraftSupreme : $(OBJS)
	$(CC) $(LFLAGS) -o minecraftSupreme $(OBJS)
