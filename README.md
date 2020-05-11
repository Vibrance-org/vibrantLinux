# vibrantLinux
Main Program:

![Main program](assets/program.png)

Program entry editor:

![Program vibrance editor](assets/entryeditor.png)

## Overview

vibrantLinux is a GUI tool that serves the same purpose as [VibranceGUI](https://vibrancegui.com/) for Windows, which is to modify the saturation of any given screen whenever certain programs are launched or are in focus.

It currently only supports Nvidia and other GPUs that implement the Color Transformation Matrix (CMT) property. If you find a way to add this support to any other GPUs, please inform me so that vibrantLinux can support those GPUs.

## Requirements

The required packages are:

- git
- qt
- libXNVCtrl
- libxcb
- libxcb-ewmh
- libX11
- libXrandr
- libvibrant

## Installation

```bash
git clone https://gitlab.com/zee220/vibrantlinux ~/vibrantlinux
cd ~/vibrantlinux
./update.sh
```

## Updates

Head to your installation folder. In our case, it is located at `~/vibrantLinux`. Then, run:

```bash
./update.sh
```
