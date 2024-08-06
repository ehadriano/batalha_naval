# Compilador
CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11

# Diretórios
SRCDIR = scr
OBJDIR = obj
BINDIR = bin
SCRIPTDIR = scripts

# Arquivos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
TARGET = $(BINDIR)/main.exe

# Regras
all: $(TARGET) create_shortcut

$(TARGET): $(OBJECTS)
	@if not exist $(BINDIR) mkdir $(BINDIR)
	$(CXX) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

create_shortcut:
	@cd $(SCRIPTDIR) && call create_shortcut.bat

clean:
	@if exist $(OBJDIR) del /Q $(OBJDIR)\*.o
	@if exist $(BINDIR) del /Q $(TARGET)
	@if exist Batalha_Naval.lnk del /Q Batalha_Naval.lnk

.PHONY: all clean create_shortcut
