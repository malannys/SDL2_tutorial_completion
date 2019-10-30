/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:10:31 by malannys          #+#    #+#             */
/*   Updated: 2019/10/30 19:00:33 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include <stdio.h>

#define SCREEN_W 640
#define SCREEN_H 480

int		init(SDL_Window **win, SDL_Surface **surf);
int		load_media(SDL_Surface **surf_image);
void	close_stuff(SDL_Window **win, SDL_Surface **surf_image);

int 	main(int ac, char **av)
{
	SDL_Window		*win = NULL;
	SDL_Surface		*surf_screen = NULL;
	SDL_Surface		*surf_image = NULL;
	SDL_Event		e;

	if (!init(&win, &surf_screen))
		printf("Error: failed to initialize\n");
	else
	{
		if (!load_media(&surf_image))
			printf("Error: failed to load media\n");
		else
		{
			while (1)
			{
				if (SDL_PollEvent(&e))
					if (e.type == SDL_QUIT)
						break ;
			//SDL_FillRect(surf, NULL, SDL_MapRGB(surf->format, 0, 0, 0));
			SDL_BlitSurface(surf_image, NULL, surf_screen, NULL);
			SDL_UpdateWindowSurface(win);
			}
		}
	}
	close_stuff(&win, &surf_image);
	return (0);
}

int		init(SDL_Window **win, SDL_Surface **surf)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return (0);
	}
	if (!(*win = SDL_CreateWindow("Hello there", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
										SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN /*|| 
										SDL_WINDOW_RESIZABLE || SDL_WINDOW_BORDERLESS*/)))
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		return (0);
	}
	if (!(*surf = SDL_GetWindowSurface(*win))) // 2D surfdering context for a window
	{
		printf("SDL_CreateWindowSurface Error: %s\n", SDL_GetError());
		return (0);
	}
	return (1);
}

int		load_media(SDL_Surface **surf_image)
{
	if (!(*surf_image = SDL_LoadBMP("LAND.bmp"))) // load image
	{
		printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
		return (0);
	}
	return (1);
}

void	close_stuff(SDL_Window **win, SDL_Surface **surf_image)
{
	SDL_FreeSurface(*surf_image); // deallocate surface
	*surf_image = NULL;
	SDL_DestroyWindow(*win); // also destroys surface associated with the window
	*win = NULL;
	SDL_Quit(); // quit SDL subsystems
}
