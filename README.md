# Challenger 1P cc65 Test Programs

## Overview

This is an evolving repository for test programs
for the "c1p" target of the cc65 C compiler.

The "c1p" target for cc65 is work in progress. It is being developed
in this [fork of cc65](https://github.com/smuehlst/cc65) on GitHub.

## Quick Start

* Clone the [cc65](https://github.com/smuehlst/cc65) and [this repository](https://github.com/smuehlst/cc65) side-by-side.
* Build the cc65 compiler.
* Build the test program(s) in the [src subdirectory](https://github.com/smuehlst/c1pctest/tree/master/src)
* The C1P object files are the *.c1p files.

The programs are tested in the [C1Pjs JavaScript simulation
of the Challenger 1P](http://www.pcjs.org/docs/c1pjs/).

In theory it should also be possible to upload the *.c1p object files
via the serial port to real Challenger 1Ps in order to run them, but this
has not been tested yet.
