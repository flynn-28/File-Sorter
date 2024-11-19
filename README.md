# Cross Platform File Sorter

## Overview
This is a program written in c++ and can be compiled cross platform. It allows a user to specify a directory and then sort files into directories by filetype.

## Usage
Usage: ./filesort {folderpath}

## Install

### Precompiled Binaries
Precompiled binaries for Windows and Linux found [here](https://github.com/flynn-28/File-Sorter/releases/tag/release)

### Build from source
#### Dependencies
* g++ - linux
* MinGW with g++ - windows

#### Steps
1. Clone repo
```bash
git clone https://github.com/flynn-28/File-Sorter.git
```
2. open directory
```json
cd filesort
```
3. Compile source
```bash
g++ main.cpp -o sorter
```
