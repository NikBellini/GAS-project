#!/bin/bash

#
# This file is part of cg3lib: https://github.com/cg3hci/cg3lib
# This Source Code Form is subject to the terms of the GNU GPL 3.0
#
# @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
#

#
# This script installs all the dependencies of cg3lib in an 
# ubuntu system.
#
# Tested with Ubuntu 18.04
#
# requires: sudo, apt
#

sudo apt -y update
sudo apt -y install git qt5-default libboost-all-dev libcgal-dev libgmp-dev libqglviewer-dev-qt5 libeigen3-dev
