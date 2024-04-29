NAME = ttt_cmwq
ttt_cmwq-objs = simrupt.o game.o negamax.o zobrist.o mt19937-64.o
obj-m := ${NAME}.o

ccflags-y := -std=gnu99 -Wno-declaration-after-statement
KDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

GIT_HOOKS := .git/hooks/applied
all: $(GIT_HOOKS) simrupt.c 
	$(MAKE) -C $(KDIR) M=$(PWD) modules

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo


clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
