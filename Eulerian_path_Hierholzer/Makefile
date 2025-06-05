.PHONY: clean tests main

MAKE_PATH=$(CURDIR)
SRC=$(MAKE_PATH)/src
LIB=$(MAKE_PATH)/build

CFLAG1=-g -Wall -Wextra -rdynamic
CFLAG2=-O1
CFLAGS= $(CFLAG1) $(CFLAG2)

SOURCES=$(wildcard $(SRC)/*.c)
OOBJ=$(patsubst $(SRC)/%.c,$(LIB)/%.o,$(SOURCES))

A_TARGET=$(LIB)/libsrc.a
SO_TARGET=$(patsubst %.a,%.so,$(A_TARGET))

all:build $(A_TARGET) $(SO_TARGET) main
	@echo "-----------all-Done-----------"

$(A_TARGET):CFLAGS += -fPIC
$(A_TARGET):build $(OOBJ)
	ar rcs $@ $(OOBJ)
	ranlib $@

$(SO_TARGET):CFLAGS += -shared
$(SO_TARGET):$(A_TARGET) $(OOBJ)
	ccache gcc $(CFLAGS) -o $@ $(OOBJ)

$(LIB)/%.o: $(SRC)/%.c	
	gcc $(CFLAGS) -c $< -o $@

main:$(OOBJ)
	gcc $(CFLAGS) -o $@ $^

build:
	@mkdir -p build
	@mkdir -p bin

clean:
	rm -f build/*
	rm -f tests/tests.log tests/vgcore.*	