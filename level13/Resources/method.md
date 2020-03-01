##This repository contains a binary called level13. Our first instinct is to run it, it displays "UID 2013 started us but we we expect 4242"
#we decide to use gdb to change the userid and run getflag
strings level13 # lists the printable characters in the binary including the functions
gdb
disas main
#set beakpoint when eax is being compared to 4242
b *hexaddr
#change the value of eax
set $eax=4242
c #continue