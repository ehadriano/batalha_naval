# Compilador
CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11

# Diretórios
SRCDIR = scr
OBJDIR = obj
BINDIR = bin

# Arquivos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
TARGET = $(BINDIR)/main.exe

# Regras
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@if not exist $(BINDIR) mkdir $(BINDIR)
	$(CXX) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if exist $(OBJDIR) rmdir /S /Q $(OBJDIR)
	@if exist $(BINDIR) rmdir /S /Q $(BINDIR)
	@if exist Batalha_Naval.lnk del /Q Batalha_Naval.lnk

.PHONY: all clean
