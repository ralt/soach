#!/bin/bash

rm -rf .*\~ src/*\~ src/*.o src/soach src/Makefile src/Makefile.in autom4te.cache aclocal.m4 compile config.h config.h.in config.log config.status configure depcomp install-sh Makefile Makefile.in missing stamp-h1

autoreconf --install
