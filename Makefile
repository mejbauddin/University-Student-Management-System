CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LDFLAGS = 
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = $(BINDIR)/usms.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@if not exist $(BINDIR) mkdir $(BINDIR)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if exist $(OBJDIR) rmdir /s /q $(OBJDIR)
	@if exist $(BINDIR) rmdir /s /q $(BINDIR)

run: all
	@$(EXECUTABLE)

.PHONY: all clean run