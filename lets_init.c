/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:40:26 by imabid            #+#    #+#             */
/*   Updated: 2022/07/27 17:12:48 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    win_init(t_conf *conf)
{
    conf->mlx = mlx_init();
    conf->mlx_win = mlx_new_window(conf->mlx,WIDTH, HEIGHT, "Cub3d");
}

void    img_init(t_conf *conf)
{
    conf->img.img = mlx_new_image(conf->mlx,WIDTH, HEIGHT);
    conf->img.addr = (int *)mlx_get_data_addr(conf->img.img, &conf->img.bits_per_pixel, &conf->img.line_length,&conf->img.endian);
}


t_texture	load_img(char *path, void *mlx)
{
	t_texture temp;

	temp.x = 0;
	temp.y = 0;
	temp.width = 64;
	temp.height = 64;
	temp.img = mlx_xpm_file_to_image(mlx, path, &temp.width, &temp.height);
	if (!temp.img)
		exit(printf("mlx Error : mlx_xpm_file_to_image !\n"));
	temp.addr = (int *)mlx_get_data_addr(temp.img, &temp.bits_per_pixel, &temp.size_line, &temp.endian);
	if (!temp.addr)
		exit(printf("mlx Error : mlx_get_data_addr!\n"));
	return (temp);
}

void    init_all(t_conf *conf)
{
    // zadt hna
    int i;
    char *path[5];
    path[0] = "asset/east.xpm";
    path[1] = "asset/north.xpm";
    path[2] = "asset/south.xpm";
    path[3] = "asset/west.xpm";
    path[4] = "asset/haha.xpm";

	i = -1;
    conf->elem = malloc(sizeof(t_elements) * 5);
	while (++i < 5)
    {
		conf->elem[i].texture = load_img(path[i], conf->mlx);
        
    }
    conf->player.dxx = 0;
    conf->player.dyy = 0;
    ft_get_playerPosition(&conf->player);
    conf->player.py = conf->player.dyy * 64 + 64 / 2;
    conf->player.px = conf->player.dxx * 64 + 64 / 2 ;
    conf->player.rotangle = PI / 2; 
    conf->player.movespeed = 4;
    conf->player.turnspeed = 2 * (PI / 180);
    conf->player.tdirection = 0;
    conf->player.walkdirection = 0;
    conf->player.to_a = 0;
    conf->player.to_w = 0;
    conf->player.to_s = 0;
    conf->player.to_d = 0;
    conf->player.to_back = 0;
    conf->player.to_forward = 0;
    conf->ray.num_rays = WIDTH; 
    conf->player.width = WIDTH;
    conf->player.height = HEIGHT;
    conf->txtnbr = 0;   
}