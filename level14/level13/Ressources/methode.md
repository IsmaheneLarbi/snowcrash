##This repository is empty, which tells us the only way we have to get the token is to run gdb on getflag itself 
gdb /bin/getflag
disas main
#   0x08048989 <+67>:	call   0x8048540 <ptrace@plt>
#   0x0804898e <+72>:	test   %eax,%eax
#   0x08048990 <+74>:	jns    0x80489a8 <main+98>
#   0x08048992 <+76>:	movl   $0x8048fa8,(%esp)
#   0x08048999 <+83>:	call   0x80484e0 <puts@plt>
#   0x0804899e <+88>:	mov    $0x1,%eax
#   0x080489a3 <+93>:	jmp    0x8048eb2 <main+1388>
#on line 67, ptrace is called,the return value will be stored in eax, test %eax, %eax puts the value in the ZeroFlag, which is used by jump to determine wheter to jump or not. Here, the command is jns : which means jump if not signed, since ptrace returns -1, the jump won't happen, puts will dosplay "You shouldnt reverse this" , eax is set to one and we exit the program (jmp to line 1338). This means we have to change the return value of ptrace
#we set a breakpoint in 0x0804898e and run from the start
b *0x0804898ei r
start
set $eax=0
stepi
stepi
#we notice a pattern to compare eax with userid and then redirect them to the appropriate block according to the userid 
#=====================================
0x08048b0a <+452>:	cmp    $0xbbe,%eax
   0x08048b0f <+457>:	je     0x8048ccb <main+901>
   0x08048b15 <+463>:	cmp    $0xbbe,%eax
   0x08048b1a <+468>:	ja     0x8048b68 <main+546>
   0x08048b1c <+470>:	cmp    $0xbba,%eax
   0x08048b21 <+475>:	je     0x8048c3b <main+757>
   0x08048b27 <+481>:	cmp    $0xbba,%eax
   0x08048b2c <+486>:	ja     0x8048b4d <main+519>
   0x08048b2e <+488>:	cmp    $0xbb8,%eax
   0x08048b33 <+493>:	je     0x8048bf3 <main+685>
   0x08048b39 <+499>:	cmp    $0xbb8,%eax
   0x08048b3e <+504>:	ja     0x8048c17 <main+721>
   0x08048b44 <+510>:	test   %eax,%eax
   0x08048b46 <+512>:	je     0x8048bc6 <main+640>
   0x08048b48 <+514>:	jmp    0x8048e06 <main+1216>
   0x08048b4d <+519>:	cmp    $0xbbc,%eax
   0x08048b52 <+524>:	je     0x8048c83 <main+829>
   0x08048b58 <+530>:	cmp    $0xbbc,%eax
   0x08048b5d <+535>:	ja     0x8048ca7 <main+865>
   0x08048b63 <+541>:	jmp    0x8048c5f <main+793>
   0x08048b68 <+546>:	cmp    $0xbc2,%eax
   0x08048b6d <+551>:	je     0x8048d5b <main+1045>
   0x08048b73 <+557>:	cmp    $0xbc2,%eax
   0x08048b78 <+562>:	ja     0x8048b95 <main+591>
   0x08048b7a <+564>:	cmp    $0xbc0,%eax
   0x08048b7f <+569>:	je     0x8048d13 <main+973>
   0x08048b85 <+575>:	cmp    $0xbc0,%eax
   0x08048b8a <+580>:	ja     0x8048d37 <main+1009>
   0x08048b90 <+586>:	jmp    0x8048cef <main+937>
   0x08048b95 <+591>:	cmp    $0xbc4,%eax
   0x08048b9a <+596>:	je     0x8048da3 <main+1117>
   0x08048ba0 <+602>:	cmp    $0xbc4,%eax
   0x08048ba5 <+607>:	jb     0x8048d7f <main+1081>
   0x08048bab <+613>:	cmp    $0xbc5,%eax
   0x08048bb0 <+618>:	je     0x8048dc4 <main+1150>
   0x08048bb6 <+624>:	cmp    $0xbc6,%eax
   0x08048bbb <+629>:	je     0x8048de5 <main+1183>
   0x08048bc1 <+635>:	jmp    0x8048e06 <main+1216>
#=====================================
#we get redirected to line main+98
// to be taken with a grain of salt
//we keep moving until line 110 and we jump to main+1183
jump *0x08048de5
token = 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ

#breakpoints used
##3       breakpoint     keep y   0x0804898e <main+72>
#	breakpoint already hit 1 time
#4       breakpoint     keep y   0x080489b4 <main+110>
#6       breakpoint     keep y   0x080489fe <main+184>

##0x08048bb6 <+624>:	cmp    $0xbc6,%eax
##0x08048bbb <+629>:	je     0x8048de5 <main+1183>
##flag14's userid is 3014


==========short==========
disas main
set bp line 72
goto line 72
set $eax=0
set bp line 110
c
jump *0x08048de5