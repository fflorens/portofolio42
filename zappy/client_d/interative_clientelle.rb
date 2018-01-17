#!/usr/bin/env ruby
require 'socket'

class Reseau
	def initialize(ip, port, team)
		@s = TCPSocket.new ip, port
		@s.puts team
	end

	def	write(msg, *others)
		txt = msg << ' ' << others.join(' ')
		@s.puts txt
	end

	def read()
		@s.gets
	end

	def close
		@s.close
	end

	def avance
		write "avance"
	end
	def droite
		write "droite"
	end
	def gauche
		write "gauche"
	end
	def voir
		write "voir"
	end
	def inventaire
		write "inventaire"
	end
	def prend(gem)
		write "prend", gem
	end
	def pose(gem)
		write "pose", gem
	end
	def expulse
		write "expulse"
	end
	def broadcast msg
		write "broadcast", msg
	end
	def incantation
		write "incantation"
	end
	def fork
		write "fork"
	end
	def connect_nbr
		write "connect_nbr"
	end
end

class Ia
	def initialize(team)
		@team = team
	end
end

def usage
	puts 'Usage: ./client -n <team> -p <port> [-h <hostname>]'
	exit
end

def aff_menus
	puts "menus possible :"
	puts "\t avance      : 1"
	puts "\t droite      : 2"
	puts "\t gauche      : 3"
	puts "\t voir        : 4"
	puts "\t inventaire  : 5"
	puts "\t prend       : 6"
	puts "\t pose        : 7"
	puts "\t expulse     : 8"
	puts "\t broadcast   : 9"
	puts "\t incantation : 10"
	puts "\t fork        : 11"
	puts "\t connect_nbr : 12"
	puts "\t autre       : 13"
	puts "\t snapshot    : 14"
end

begin

	if (ARGV[0] != "-n")
		usage
	end
	team = ARGV[1]
	if (ARGV[2] != "-p")
		usage
	end
	port = ARGV[3]
	if (ARGV[4] == "-h")
		host = ARGV[5]
	else
		host = '127.0.0.1'
	end
	
	puts team
	puts port
	puts host

	r = Reseau.new host, port, team
	Thread.new do |t|
		aff_menus
		while inp = $stdin.gets
			inp = inp.delete! "\n"
			if inp == 1.to_s
				r.avance
			elsif inp == 2.to_s
				r.droite
			elsif inp == 3.to_s
				r.gauche
			elsif inp == 4.to_s
				r.voir
			elsif inp == 5.to_s
				r.inventaire
			elsif inp == 6.to_s
				r.prend $stdin.gets
			elsif inp == 7.to_s
				r.pose $stdin.gets
			elsif inp == 8.to_s
				r.expulse
			elsif inp == 9.to_s
				r.broadcast $stdin.gets
			elsif inp == 10.to_s
				r.incantation
			elsif inp == 11.to_s
				r.fork
			elsif inp == 12.to_s
				r.connect_nbr
			else
				r.write inp, $stdin.gets
			end
			aff_menus
		end
	end

	while line = r.read do
		puts line
	end
r.close
end
