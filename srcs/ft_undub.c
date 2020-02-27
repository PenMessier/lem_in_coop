#include "../includes/lem.h"

void    ft_undub(t_meta *all, t_meta *dub)
{
	int     i;
	int     j;
	int	one = 0;
	int	two = 0;
	int	tri = 0;
	int	fur = 0;
	int	five = 0;

	for(i = 0; i < all->room_count; i++){
		for (j = 0; j < all->room_count; j++){
			one = dub->f[i * 2 * all->room_count * 2 + j  * 2];
			two = dub->f[i * 2 * all->room_count * 2 + j  * 2 + 1];
			tri = dub->f[i * 2 * all->room_count * 2 + j  * 2 + all->room_count * 2];
			fur = dub->f[i * 2 * all->room_count * 2 + j  * 2 + 1 + all->room_count * 2];
			five = one + two + tri + fur;
			all->f[i * all->room_count + j] = five;
		}
	}
}

