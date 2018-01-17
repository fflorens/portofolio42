-- -------------------------------------------------------------------------- --
--                                                                            --
--                                                        :::      ::::::::   --
--   premake4.lua                                       :+:      :+:    :+:   --
--                                                    +:+ +:+         +:+     --
--   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        --
--                                                +#+#+#+#+#+   +#+           --
--   Created: 2014/01/02 16:48:37 by jzak              #+#    #+#             --
--   Updated: 2014/01/02 16:48:37 by jzak             ###   ########.fr       --
--                                                                            --
-- -------------------------------------------------------------------------- --

solution "Solutions"
	configurations	{ "Release", "Debug" }
	targetdir "bin"
	language "C"
	version = "0.1.1"
	inc = { "includes", "libft/includes", "../libft/includes" }

	-- Build option
	configuration "Release"
		buildoptions { "-Wall -Wextra -Werror" }
		flags { "Optimize" }
	configuration "Debug"
		buildoptions { "-Wall -Wextra" }
		flags { "Symbols" }

	-- libnboon
	project "42sh"
		kind "ConsoleApp"
		prebuildcommands { "cd libft; make", "cd nboon; make" }
		libdirs { "libft", "nboon/bin" }
		files {
				"src/*.c",
				"src/builtins/*.c",
				"src/exec/*.c",
				"src/lexer/*.c",
				"src/parser/*.c",
				"src/structs/*.c",
				"src/utils/*.c"
			}
		links { "ft", "nboon" }
		includedirs { "includes", "libft/includes" }
