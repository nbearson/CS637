#!/bin/sh
#
# Attempt at an automated install script for 6.828's Bochs version
# Tested on Linux, FreeBSD and MacOS
#
# $Id: bochs-install.sh,v 1.9 2007/09/05 17:03:17 nelhage Exp $
#

YEAR=2007

PDOS=http://pdos.lcs.mit.edu/6.828/$YEAR/src
VERSFILE=bochs-version

echo "-> Asking the PDOS server which version of BOCHS to fetch/install"
BOCHS=`wget -q -O - $PDOS/$VERSFILE`
BOCHS_TGZ="$BOCHS.tar.gz"

echo "-> Installing Bochs Version" $BOCHS
wget -q http://pdos.lcs.mit.edu/6.828/$YEAR/src/$BOCHS_TGZ

echo "-> Untarring file" $BOCHS_TGZ to $BOCHS
tar -xzf $BOCHS_TGZ

echo "-> CD into" $BOCHS
cd $BOCHS

PRFX=
MACOS=

echo `uname -a` | grep -i athena > /dev/null
if test $? -eq 0
then
	PRFX="--prefix=/mit/6.828"
	echo "-> Athena Install Detected"
fi

echo `uname -a` | grep -i darwin > /dev/null
if test $? -eq 0
then
    MACOS="--with-carbon"
    echo "-> Mac Install Detected"
fi

echo "-> Running Configure with Extra Options:" $PRFX $MACOS
./configure --enable-disasm \
            --enable-smp \
            --enable-debugger \
            --enable-new-pit \
            --enable-all-optimizations \
            --enable-4meg-pages \
            --enable-global-pages \
            --enable-pae \
            --enable-all-optimizations \
            --disable-reset-on-triple-fault \
            --with-all-libs \
            --with-x \
            --with-x11 \
            --with-nogui \
            $PRFX $MACOS > configure.out

if test $? -ne 0
then
    echo XXX configured failed
    exit 1
fi

echo "-> Running make"
make
if test $? -ne 0
then
    echo XXX make failed
    exit 1
fi


echo "-> Running make install"
make install
if test $? -ne 0
then
    echo XXX make install failed
fi
