#
# Makefile för kalkylatorn, Nivå G. GNU GCC (g++)
#

# Kompilator
CCC = g++

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS  += -std=c++0x -pedantic -L/sw/gcc-4.5.1/lib -lSDL -lSDL_ttf -lSDL_image -g -O0 `sdl-config --libs --cflags `
#-Wall -Wextra
# -L/sw/gcc-4.5.1/lib

# Objektkodsmoduler som ingår i den kompletta kalkylatorn.
OBJECTS = main.o battle.o card.o game_engine.o player.o territory.o worldmap.o game_ui.o label.o Button.o Clickable.o Image.o
#UI_OBJECTS = game_ui.o label.o Button.o Clickable.o Image.o

# Huvudmål - skapas med kommandot 'make' eller 'make kalkylator'.
main: $(OBJECTS) Makefile
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -o main $(OBJECTS) 
#$(UI_OBJECTS)

# Delmål (flaggan -c avbryter innan länkning)
main.o: main.cc game_engine.h
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c main.cc

battle.o: battle.cc battle.h
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c battle.cc

card.o: card.cc card.h
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c card.cc

game_engine.o: game_engine.cc game_engine.h
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c game_engine.cc

player.o: player.cc player.h
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c player.cc

territory.o: territory.cc territory.h
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c territory.cc

worldmap.o: worldmap.cc worldmap.h
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c worldmap.cc

#risk: $(UI_OBJECTS) Makefile
#	$(CCC) $(CCFLAGS) $(CPPFLAGS) -o risk $(UI_OBJECTS)

game_ui.o: game_ui.h game_ui.cc
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c game_ui.cc

label.o: label.h label.cc
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c label.cc

Button.o: Button.h Button.cc
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c Button.cc

Clickable.o: Clickable.h Clickable.cc
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c Clickable.cc

Image.o: Image.h Image.cc
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c Image.cc



# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core

# 'make zap' tar även bort det körbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf kalkylator *~

# '@' medför att kommandot inte skrivs ut på skärmen då det utförs av make.
# 'rm' är ett alias för 'rm -i' på IDA:s system, '\rm' innebär att "original-
# versionen", utan skyddsnätet '-i', används. Se upp vid ändring, '*' får 
# absolut inte finnas för sig!
