#!/bin/bash
make -C ../
# compile test progs
for i in test_*.c ; do gcc -Wall -Wextra -Werror $i ../libfts.a -o `echo ${i} | sed 's/\.c//'` ; done
# execute test progs
for i in test_*.c ; do ./`echo ${i} | sed 's/\.c//'` ; done
# remove compiled binaries
for i in test_*.c ; do rm `echo ${i} | sed 's/\.c//'` ; done
