# Challenger 1P cc65 Test Programs

## Overview

This is an evolving repository for test programs
for the "osic1p" target of the cc65 C compiler.

## Quick Start

* Install the [srecord utility](http://srecord.sourceforge.net/), which is needed to convert cc65 object files to a format that can be uploaded via the OSI machine monitor.
* Clone the [cc65](https://github.com/cc65/cc65) and [this repository](https://github.com/smuehlst/cc65) side-by-side.
* Build the cc65 compiler.
* Build the test program(s) in the [src subdirectory](https://github.com/smuehlst/c1pctest/tree/master/src)
* The C1P object files are the *.c1p files.

The programs can be run on real machines or in the [C1Pjs JavaScript simulation
of the Challenger 1P](http://www.pcjs.org/docs/c1pjs/). The c1p target by
default links for machines with 32 kB RAM. Therefore the programs need to
be run in the
[OSI Challenger 1P (32Kb) with Disk Support](http://www.pcjs.org/devices/c1p/machine/32kb/)
machine.

The Makefile can also generate Kansas City Standard WAV files for
upload over the cassette port. For this a modified version of the Python
script kcs_encody.py by [David Beazley](http://www.dabeaz.com/py-kcs/index.html)
is used.
