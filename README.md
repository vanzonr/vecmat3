=====================================================================
  vecmat3 - 3d vector and matrix classes using expression templates
=====================================================================

vecmat3 is a C++ library for 3d vector and matrix manipulation. It is
a header-only implementation that uses expression templates, which
allows most compilers to generate fast code.  The current version in
2.3.1.

vecmat3 is open-source, and is released under the MIT license. This
library is distributed WITHOUT ANY WARRANTY. For details, see the file
named 'LICENSE', and license statements in the source files.

==============
 Installation
==============

To use this header-only library, one merely needs to copy the header
file vecmat3.h to the directory of the source files that include it,
or to a default directory where the compiler will look for header
files (e.g. /usr/local/include). 'make -f Makefile install' would do
this on linux systems, but be aware that the Makefile has not been
extensively tested.

The vecmat3 library has been tested with the GNU g++ compiler version
4.4 and up, the Intel C++ compiler version 11 and up and IBM's XL C++
compiler version 10 and up.

===============
 Documentation
===============

Documentation can be found in the pdf file 'vecmat3_2.3.pdf', which is
generated from the LaTeX file vecmat3_2.3.tex.

================
 Reporting Bugs
================

Under the license, you are not required to report bugs, but are
encouraged to do so.  If you find a bug, you may report it to
vanzonr@gmail.com. Errors or omissions in the documention can be
reported to the same address.

=======
 Files
=======

vecmat3.h:          The header-library
vecmat3.tex:        LaTeX source of the documentation
regressiontest.cc:  regression test suite using Boost.Test
example.cc:         Small example
Makefile:           Makefile to build example, regression test and opdf
WARRANTEE:          File that expresses that there is no warrantee
LICENSE:            Text of the MIT license
AUTHOR:             Name and email address of the author
README:             This file

- 15 May 2013 -
