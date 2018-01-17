// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   load.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2014/06/20 19:09:27 by abanvill          #+#    #+#             //
//   Updated: 2014/06/20 19:09:27 by abanvill         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <zproject.h>
#include <SDL/SDL.h>

#include <string>
#include <sstream>
#include <iostream>

Mix_Music			*loadMusic(int id)
{
	std::stringstream		idNumber;
	std::string				characters_path(MUSICS_PATH);
	std::string				fname;
	std::string				extension(MUSICS_EXTENSION);
	Mix_Music				*music;

	idNumber << id;
	fname = characters_path + idNumber.str() + extension;
	initSound();
	if (!(music = Mix_LoadMUS((const char *)fname.c_str())))
		exitFailure("Loading error::music file\n");
	else
		std::cout << "Loaded: "<< fname << std::endl;
	return (music);
}

SDL_Surface			*loadCharacter(int id)
{
	std::stringstream		idNumber;
	std::string				characters_path(CHARACTERS_PATH);
	std::string				fname;
	std::string				extension(CHARACTERS_EXTENSION);
	SDL_Surface				*character;

	idNumber << id;
	fname = characters_path + idNumber.str() + extension;
	if (!(character = SDL_LoadBMP(fname.c_str())))
		fprintf(stderr, "Loading error::character file\n");
	else
		std::cout << "Loaded: "<< fname << std::endl;
	return (character);
}

SDL_Surface			*loadFood(int id)
{
	std::stringstream		idNumber;
	std::string				food_path(FOODS_PATH);
	std::string				fname;
	std::string				extension(FOODS_EXTENSION);
	SDL_Surface				*food;

	idNumber << id;
	fname = food_path + idNumber.str() + extension;
	if (!(food = SDL_LoadBMP(fname.c_str())))
		fprintf(stderr, "Loading error::food file\n");
	else
		std::cout << "Loaded: "<< fname << std::endl;
	return (food);
}

SDL_Surface			*loadGem(int id)
{
	std::stringstream		idNumber;
	std::string				gem_path(GEMS_PATH);
	std::string				fname;
	std::string				extension(GEMS_EXTENSION);
	SDL_Surface				*gem;

	idNumber << id;
	fname = gem_path + idNumber.str() + extension;
	if (!(gem = SDL_LoadBMP(fname.c_str())))
		fprintf(stderr, "Loading error::gem file\n");
	else
		std::cout << "Loaded: "<< fname << std::endl;
	return (gem);
}

SDL_Surface			*loadSkill(int id)
{
	std::stringstream		idNumber;
	std::string				skill_path(SKILLS_PATH);
	std::string				fname;
	std::string				extension(SKILLS_EXTENSION);
	SDL_Surface				*skill;

	idNumber << id;
	fname = skill_path + idNumber.str() + extension;
	if (!(skill = SDL_LoadBMP(fname.c_str())))
		fprintf(stderr, "Loading error::skill file\n");
	else
		std::cout << "Loaded: "<< fname << std::endl;
	return (skill);
}

SDL_Surface			*loadGround(int id)
{
	std::stringstream		idNumber;
	std::string				ground_path(GROUNDS_PATH);
	std::string				fname;
	std::string				extension(GROUNDS_EXTENSION);
	SDL_Surface				*ground;

	idNumber << id;
	fname = ground_path + idNumber.str() + extension;
	if (!(ground = SDL_LoadBMP(fname.c_str())))
		fprintf(stderr, "Loading error::ground file\n");
	else
		std::cout << "Loaded: "<< fname << std::endl;
	return (ground);
}

SDL_Surface			*loadGroundHold(int id)
{
	std::stringstream		idNumber;
	std::string				ground_path(GROUNDS_HOLD_PATH);
	std::string				fname;
	std::string				extension(GROUNDS_HOLD_EXTENSION);
	SDL_Surface				*ground;

	idNumber << id;
	fname = ground_path + idNumber.str() + extension;
	if (!(ground = SDL_LoadBMP(fname.c_str())))
		fprintf(stderr, "Loading error::ground hold file\n");
	else
		std::cout << "Loaded: "<< fname << std::endl;
	return (ground);
}
