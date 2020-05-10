## le programm level08 n'accepte pas les fichiers dont le nom comporte une sous-expression 'token'
## level08 take a file in argument and read content, but does not accept a file with under-expression 'token' as name
## By the way, there is a file token in this level, which may contain token for authentication as flag08
## So, we create a symbolic link to this file 'token'. This symbolic link has another name which not include 'token' in name
## And we lauch binary file to this symbolic link

### ln -s ~/token /tmp/getflag && ./level08 /tmp/getflag

## The program accept file and displays the passeord of flag08
su flag08
then getflag
