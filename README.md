# Dotfiles - A minimal Arch Linux Environment
Essentials only Arch Linux setup

## Table of Contents

## Core Philosophy

This setup is built upon the idea of "NO DISTRACTIONS".
Its fast, light and will take you where you need to go in one keystroke.

## Features

- ⚡ **Minimal setup** — no bloat, no unnecessary packages.
- 🛠 **Highly customizable** — every tool can be patched and configured to your liking.
- 🖥 **Lightweight** — low memory and CPU usage.
- ✏  **Developer-friendly** — optimized Neovim configuration with essential plugins.
- 🔒 **Secure** — minimal attack surface by removing unused services.
- 🎨 **Aesthetic** — clean, snappy, distraction-free environment.

## Tools

I am mentioning the major tools in my dotfiles.if its not here that means it desn't need much configuration.

### [Arch Linux](https://archlinux.org/)
- Installed using the Arch install guide, base minimal install with neccesary drivers only.

### [Suckless Tools](https://suckless.org/)
- [DWM](https://dwm.suckless.org/) — Dynamic window manager.
    - Patched with: 
        [always-centre](https://dwm.suckless.org/patches/alwayscenter/) 
        [fibonacci](https://dwm.suckless.org/patches/fibonacci/)
- [ST](https://st.suckless.org/) — Simple terminal emulator.
    - Patched with:
        [scrollback](https://st.suckless.org/patches/scrollback/)
- [slstatus](https://tools.suckless.org/slstatus/) — Status monitor for DWM.
- [slock](https://tools.suckless.org/slock/) — Simple screen locker.
- [dmenu](https://tools.suckless.org/dmenu/) — Dynamic menu for launching apps.
    - This one is installed from pacman as it doesn't need much customization.

### [Neovim](https://github.com/neovim/neovim)
- Used with [vim-plug](https://github.com/junegunn/vim-plug)

## Installation
- To use this configuration you can copy the files manually in thier designated places
    ## OR
- Install stow, (sudo pacman -S stow)
- then run the command: ``` stow <file-name> ```
    for any file that you might need.
