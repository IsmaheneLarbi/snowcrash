## level09 take one argument and apply transformation directly to the string

### Example:

### level09@SnowCrash:~$ ./level09 aaaaaaaaaaaaaaaaaaaaaaaaaa
### abcdefghijklmnopqrstuvwxyz

## Maybe it's the same transformation for content of file 'token' ?

### We reverse string[i] -= i

## A little program to reverse transformation of content in file 'token'

int	main(int ac, char **av)
{
	int fd;
	int i = 0;
	char buff[25];

	fd = open(av[1], O_RDONLY);

	read(fd, buff, 25);
	buff[25] = 0;

	while (i < 25)
		buff[i] -= i++;
	printf("%s\n", buff);
	return (0);
}

### gcc main.c -o reverse && ./reverse token

## We reversed transformation of file 'token' and now we have token to authenticate as flag09
