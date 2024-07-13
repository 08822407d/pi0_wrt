#!/bin/bash

cd build && cmake .. -DCMAKE_INSTALL_PREFIX=.. && make && make install