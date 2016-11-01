#!/bin/sh
#clang++ -std=c++11 -stdlib=libc++ -Weverything main.cpp
#xcrun clang++ -std=c++11 -stdlib=libc++ -Weverything main.cpp
clang++ -Wall -Wno-c++14-extensions -std=c++0x Decorator_X86_test.cpp
./a.out