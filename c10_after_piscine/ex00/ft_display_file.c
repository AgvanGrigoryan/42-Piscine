#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void display_file(char *filename)
{
	int	file;
	int	bytes_read;
	char	buffer[1024];

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	while ((bytes_read = read(file, buffer, 1024)) > 0)
	{
		write(1, buffer, bytes_read);
	}

}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		display_file(argv[1]);
	return (0);
}
