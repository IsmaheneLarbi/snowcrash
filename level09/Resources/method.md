le programme level09 prend un seul argument et transforme la chaine de l'argument (chaine[i] += i)

Exemple:

level09@SnowCrash:~$ ./level09 aaaaaaaaaaaaaaaaaaaaaaaaaa
abcdefghijklmnopqrstuvwxyz

Le contenu du fichier token aurait-il subi la même transformation ?
On le reverse chaine[i] -= i

Un petit programme en C pour le faire rapidement:

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

gcc main.c -o reverse && ./reverse token
