BINDIR = bin
SRCDIR = src
INCLUDEDIR = include
APPDIR = application
OBJDIR = build
TESTDIR = test

CC = g++
CFLAGS = -pedantic -std=c++11  -Wall -I $(INCLUDEDIR)

BIN = ${BINDIR}/pet
APP = ${APPDIR}/main.cpp

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
APPOBJ = $(patsubst $(APPDIR)/%.cpp,$(OBJDIR)/%.o,$(APP))

#_TESTS = $(wildcard $(TESTDIR)/*.cpp)
#TESTS = $(patsubst %.cpp,%,$(_TESTS))

$(BIN): $(OBJS) $(APPOBJ)
	$(CC) -g -o $(BIN) $(APPOBJ) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(APPOBJ): $(APP)
	$(CC) -c -o $@ $< $(CFLAGS)
    
${OBJDIR}/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

#test: $(TESTS) 
#	$(info ************  Testes concluídos com sucesso! ************)

#$(TESTDIR)/t_%: $(TESTDIR)/t_%.cpp $(OBJS)
#	$(CC) -o $@ $< $(OBJS) $(CFLAGS) $(LDFLAGS)
#	$@

clean:
	rm -f $(BIN) $(OBJS) $(APPOBJ)
	rm -f $(TESTS)
