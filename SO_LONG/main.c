#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct t_data
{
	void	*mlx;
	void	*mlx_win;
	void	*grass_;
	void	*wall_;
	char 	*buff;
	int		size;

} s_data;

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

void print_error(char *err)
{
	write(2,err,ft_strlen(err));
	exit(0);
}

void check_map(char *str)
{
	int	len;

	len = ft_strlen(str);
	if(len < 5)
		print_error("error in file name !\n");
	if(str[len-1] != 'r' || str[len-2] != 'e'
		|| str[len-3] != 'b' || str[len-4] != '.')
	print_error("error in file name extention!\n");
}

char	*chkpath(char *path)
{
	int		id;
	int		ret;
	char	*buff;
	
	id = open(path, O_RDONLY);
	if (id == -1)
		print_error("failing open file!\n");

	buff = malloc(sizeof(char) * 1025);
	if (!buff)
		print_error("failed allocating buff !\n");
	ret = read(id, buff, 1024);
	if (ret== -1)
		print_error("failing read file!\n");
	close(id);
	return (buff);
}

void	chkxpm(s_data *data)
{
	int width;
	int height;
	data->grass_ = mlx_xpm_file_to_image(data->mlx, "./sources/grass.xpm",  &width, &height);
	if(!data->grass_)
		print_error("couldn't found grass texture !\n");
	data->wall_ = mlx_xpm_file_to_image(data->mlx, "./sources/wall.xpm",  &width, &height);
	if(!data->wall_)
		print_error("couldn't found wall texture !\n");
	return ;
}

void print2win(s_data *data)
{
	int	x;
	int	y;
	int	index;
	
	x = -1;
	y = -1;
	index = -1; 
	while(data->buff[++index])
	{
		if (data->buff[index] == '\n')
		{
			y += data->size;
			x = 0;
		}
		else if (data->buff[index] == '1')
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->wall_,x,y);
		else if (data->buff[index] == '0')
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,x,y);
			// mlx_pixel_put(data->mlx, data->mlx_win, x, y, 6819277);
		if (data->buff[index] != '\n')
			x += data->size;
	}
}



int main(int argc, char **argv)
{
	s_data  data;
	data.size = 50;
	if (argc != 2)
		print_error("should be two parameters\n");
	check_map(argv[1]);
	data.buff = chkpath(argv[1]);
	data.mlx =	mlx_init(); 
	data.mlx_win = mlx_new_window(data.mlx, 1280, 720, "Hello");
	chkxpm(&data);
	print2win(&data);
	mlx_loop(data.mlx);
}