#!/bin/bash
obj-m += platform_device_test.o 

#KDIR := /home/topeet/android4.0/iTop4412_Kernel_3.0
KVERS = $(shell uname -r)

PWD ?= $(shell pwd)

#all:
#	make -C $(KDIR) M=$(PWD) modules
build: kernel_modules

kernel_modules:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules
		
clean:
	rm -rf *.o
