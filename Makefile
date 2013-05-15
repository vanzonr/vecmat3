#
# Makefile - makefile that may be useful to install vecmat3 to a
#            standard location, to build the regression suite for
#            vecmat3, contained in 'regressiontest.cc', which requires
#            boost.make, to build the example and create the
#            documentation. The header-only library itself need not be
#            build.  This file has only be tested on linux.
#
# Copyright (c) 2013  Ramses van Zon
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

CXX=g++
CXXFLAGS=-O3
INSTALLDIR=/usr/local

.PHONY: all doc clean install test

all: donothing

donothing:
	@echo "vecmat3.h does not need to be build."
	@echo "To create the documentation, type 'make doc'"
	@echo "To test compilation, type 'make example'"
	@echo "To perform the regression test, type 'make test'"
	@echo "To install to standard location (/usr/local/..), type 'make install'"


example: example.cc
regressiontest: regressiontest.cc

regressiontest-debug: regressiontest.cc
	$(CXX) -DDEBUG -g -O0 -c -o $@ $^

clean:
	rm -f regressiontest regressiontest-debug example vecmat3.pdf test.log

doc:
	pdflatex vecmat3.tex
	pdflatex vecmat3.tex
	pdflatex vecmat3.tex
	rm -f vecmat3.aux vecmat3.toc vecmat3.log

test: regressiontest
	cp -f regressiontest /tmp/regressiontest
	chmod +x /tmp/regressiontest
	/tmp/regressiontest --report_level=detailed 2> test.log
	cat test.log

install: doc
	mkdir -p $(INSTALLDIR)/include
	mkdir -p $(INSTALLDIR)/share/vecmat3
	cp vecmat3.h $(INSTALLDIR)/include
	cp -f vecmat3.pdf $(INSTALLDIR)/share/vecmat3
