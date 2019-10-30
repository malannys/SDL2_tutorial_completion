/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:10:31 by malannys          #+#    #+#             */
/*   Updated: 2019/10/30 17:53:26 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include <stdio.h>

#define SCREEN_W 640
#define SCREEN_H 480


int main(int ac, char **av)
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		e;

	win = NULL;
	ren = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return (1);
	}
	if (!(win = SDL_CreateWindow("Hello there", 100, 100, 
										SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN/*, 
										SDL_WINDOW_RESIZABLE, SDL_WINDOW_BORDERLESS*/)))
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	if (!(ren = SDL_CreateRenderer(win, -1, 0))) // 2D rendering context for a window
	{
		printf("SDL_CreateRender Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		return (1);
	}
	while (1)
	{
		if (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				break ;
	SDL_SetRenderDrawColor(ren, 200, 125, 1, 255);
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
	}
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
