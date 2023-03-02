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
	void	*cllect_;
	void	*wall_;
	char 	*buff;
	int		block_size;
	int		height;
	int		width;

} s_data;

int	ft_strlen(char *str, char c)
{
	int	index;

	index = 0;
	if (!str)
		return 0;
	while (str[index] != c && str[index])
		index++;
	return (index);
}

void print_error(char *err)
{
	write(2,err,ft_strlen(err,'\0'));
	exit(0);
}

void check_map_extention(char *str)
{
	int	len;

	len = ft_strlen(str,'\0');
	if(len < 5)
		print_error("error in file name !\n");
	if(str[len-1] != 'r' || str[len-2] != 'e'
		|| str[len-3] != 'b' || str[len-4] != '.')
	print_error("error in file name extention!\n");
}

char	*check_path_and_get_buff(char *path)
{
	int		id;
	int		ret;
	char	*buff;
	
	id = open(path, O_RDONLY);
	if (id == -1)
		print_error("failing open file!\n");

	buff = malloc(sizeof(char) * 1024);
	if (!buff)
		print_error("failed allocating buff !\n");
	ret = read(id, buff, 1024);
	if (ret == -1)
		print_error("failing read file!\n");
	buff[ret] = '\0';
	close(id);
	return (buff);
}

void	check_texture(s_data *data)
{
	int width;
	int height;
	data->grass_ = mlx_xpm_file_to_image(data->mlx, "./sources/Blocks/dirt.xpm",  &width, &height);
	if(!data->grass_)
		print_error("couldn't found grass texture !\n");
	data->cllect_ = mlx_xpm_file_to_image(data->mlx, "./sources/Collectibles/ender_eye.xpm",  &width, &height);
	if(!data->cllect_)
		print_error("couldn't found Collectible texture !\n");
	data->wall_ = mlx_xpm_file_to_image(data->mlx, "./sources/Blocks/stone_wall.xpm",  &width, &height);
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
			y += data->block_size;
			x = 0;
		}
		else if (data->buff[index] == '1')
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->wall_,x,y);
		else if (data->buff[index] == '0')
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,x,y);
		else if (data->buff[index] == 'C')
		{
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->grass_,x,y);
			mlx_put_image_to_window(data->mlx,data->mlx_win,data->cllect_,x+7,y+7);
			// mlx_pixel_put(data->mlx, data->mlx_win, x, y, 6819277);
		}
		if (data->buff[index] != '\n')
			x += data->block_size;
	}
}

void	get_map_size(s_data *data)
{
	int	index;
	
	index = -1;
	while(data->buff[++index] && data->buff[index] != '\n')
		data->height += 1;
	index = -1;
	while(data->buff[++index])
		if(data->buff[index] == '\n')
			data->width += 1;
	if(data->buff[index] == '\0')
		data->width += 1;
}

void	check_lines_map_length(s_data *data)
{
	int	index;
	int count;
	int count_2;

	count = ft_strlen(data->buff,'\n');
	count_2 = 0;
	index = 0;
	while (data->buff[index])
	{
		if(data->buff[index] != '\n')
			count_2++;
		else
		{
			if (count != count_2)
				print_error("lines length doesn't matches !\n");
			count_2 = 0;
		}
		index++;
	}
	if (count != count_2)
		print_error("lines length doesn't matches !\n");
}

void	check_map_border(s_data *data)
{
	int	index;

	index = -1;
	while (data->buff[++index] && data->buff[index] != '\n')
		if (data->buff[index] != '1')
			print_error("invalid top map's border\n");
	index = -1;
	while(data->buff[++index])
		if (data->buff[index] == '\n' && index > 0)
			if (data->buff[index - 1] != '1' || (data->buff[index + 1] != '1' && data->buff[index + 1] != '\0'))
				print_error("invalid center map's border\n");
	while(data->buff[--index] != '\n' && index > 0)
		if (data->buff[index] != '1')
			print_error("invalid bottom map's border\n");
}

int main(int argc, char **argv)
{
	s_data  data;
	data.height = 0;
	data.width = 0;
	data.block_size = 50;
	if (argc == 2)
	{
		check_map_extention(argv[1]);
		data.buff = check_path_and_get_buff(argv[1]);
		check_lines_map_length(&data);
		check_map_border(&data);
		get_map_size(&data);
		data.mlx =	mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, data.height * data.block_size, data.width * data.block_size, "Hello");
		check_texture(&data);
		print2win(&data);
		mlx_loop(data.mlx);
	}
	else
		print_error("should be two parameters\n");
}