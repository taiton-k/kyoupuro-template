CC = zapcc++
CFLAGS = -std=c++17 -Wall -Wextra -Wno-unused -O0 -DLOCAL -D_GLIBCXX_DEBUG
SANITIZE = undefined,address

TARGET = a.out
SRCS = main.cpp
OBJS    = $(SRCS:.cpp=.o)
INCDIR = ~/Documents/KyouPuro/c++/


$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -I $(INCDIR) $(SRCS)

#$(OBJS): $(SRCS)
#	$(CC) $(CFLAGS) -I$(INCDIR) -c $(SRCS)

sanitize:
	clang++ $(CFLAGS) -I $(INCDIR) $(SRCS) -fsanitize=$(SANITIZE)

gcc:
	g++ $(CFLAGS) -I $(INCDIR) $(SRCS) -fsanitize=$(SANITIZE)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d

test:
	$(CC) $(CFLAGS) -I $(INCDIR) test.cpp
