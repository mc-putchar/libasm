# Libasm

> Assembly yourself!

## About

42 Advanced curriculum project intended as introduction to assembly.  

A small library containing commonly used functions written in x86 64-bit Linux assembly for nasm with Intel syntax.  

## Contents

Mandatory:
- ft_strlen
- ft_strcpy
- ft_strcmp
- ft_write
- ft_read
- ft_strdup

Bonus:
- ft_atoi_base
- ft_list_push_front
- ft_list_size
- ft_list_sort
- ft_list_remove_if

## Usage

Run the command `make`, which will compile both mandatory and bonus functions.  
Compiled library **libasm.a** can then be linked to desired program using flags `-L$(LIBASM_DIR) -lasm`  

You may also run automated tests and verify correct functionality with command `make check`  or use `make help` to checkout other options.  

