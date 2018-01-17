#!/usr/bin/env ruby
require 'socket'
require 'thread'

class Reseau
	def initialize(ip, port, team, ia)
		@ia = ia
		puts "ip :#{ip}, port :#{port}, team :#{team}, ia :#{ia}"
		@s = TCPSocket.new ip, port
		@s.puts team
	end

	def	write(msg, *others)
		txt = msg << ' ' << others.join(' ')
		@s.puts txt
	end

	def read
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

	def boucle
		while true
			txt = self.read.split
			puts txt
			case txt[0]
			when 'connecter_nbclient'
				@ia.connect_nbr txt[1]
			when 'connecter_taille_map'
				@ia.taille_map txt[1], txt[2]
			when 'ok'
				@ia.ok txt[1]
			when 'ko'
				@ia.ko
			when 'mort'
				@ia.dead
			when 'niveau'
				@ia.end_elevation(txt[3])
			when 'elevation'
				@ia.debut_elevation
			when 'message'
				@ia.broadcast(txt)
			else
				puts "commande inconue #{txt[0]}"
			end
		end
	end

end

class Ia

	#action = liste des future action voulue
	
	def initialize(team, r, ip, port = nil)
		@action = Array.new
		@lvl = 1
		@vu = nil
		@inventaire = nil
		@team = team
		@map_x = -1
		@map_y = -1
		@r = r
		@ip = ip
		@port = port
	end

	def connect_nbr(nb)
#		if nb.to_i > 0
#			@r = Reseau.new @ip, @port, @team, self
#			ia = Ia.new(@team, r, @ip, @port)
#			tr = Thread.new{@r.boucle}
#			ti = Thread.new{ia.boucle}
#			tr.join
#			ti.join
#		end
	end

	def boucle
		Thread.pass
		while (@map_x == -1 || @map_y == -1)
		end
		self.do :incantation
		while true
			if (@action.length < 10)
				if (@action.last == :avance)
					@action.push({:name => :prend, :param => 'nourriture'})
				else
					@action.push :avance
				end
			end
		end
	end
	
	def set_reseau(r)
		@r = r
	end

	def do(act)
		@current_act = act
		case act
		when :avance
			@r.avance
		when :droite
			@r.droite
		when :gauche
			@r.gauche
		when :voir
			@r.voir
		when :inventaire
			@r.inventaire
		when :expulse
			@r.expulse
		when :incantation
			@r.incantation
		when :fork
			@r.fork
		when :connect_nbr
			@r.connect_nbr
		when Hash
			case act[:name]
			when :prend
				@r.prend act[:param]
			when :pose
				@r.pose act[:param]
			when :broadcast
				@r.broadcast act[:param]
			end
		when nil
			# action a faire ?
		end
	end

	def ok(param)
		case @current_act
		when :avance
			self.do @action.shift
		when :droite
			self.do @action.shift
		when :gauche
			self.do @action.shift
		when :voir
			@vu = param
			self.do @action.shift
		when :inventaire
			@invantaire = param
			self.do @action.shift
		when :incantation
			self.do @action.shift
		when :fork
			self.do @action.shift
		when :connect_nbr
			#new connect
			self.do @action.shift
		when Hash
			case @current_act[:name]
			when :prend
				self.do @action.shift
			when :pose
				self.do @action.shift
			when :broadcast
				self.do @action.shift
			end
		end
	end

	def ko
		case @current_act
		when :avance
			self.do @action.shift
		when :droite
			self.do @action.shift
		when :gauche
			self.do @action.shift
		when :voir
			self.do @action.shift
		when :inventaire
			self.do @action.shift
		when :incantation
			self.do @action.shift
		when :fork
			self.do @action.shift
		when :connect_nbr
			self.do @action.shift
		when Hash
			case @current_act[:name]
			when :prend
				self.do @action.shift
			when :pose
				self.do @action.shift
			when :broadcast
				self.do @action.shift
			end
		end
	end

	def debut_elevation
		@current_act = :incantation
	end

	def dead
		puts 'dead'
		@r.exit
		Thread.exit
	end

	def broadcast(param)
		# gestion du broadcast
	end

	def end_elevation(lvl)
		@lvl = lvl
	end

	def taille_map(x, y)
		@map_x = x.to_i
		@map_y = y.to_i
	end

	def est_expulser(direction)
		#reaction ?
	end

end

def usage
	puts 'Usage: ./client -n <team> -p <port> [-h <hostname>]'
	exit
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
	
	ia = Ia.new(team, host, port)
	r = Reseau.new host, port, team, ia
	ia.set_reseau r
	tr = Thread.new{r.boucle}
	ti = Thread.new{ia.boucle}
	tr.join
	ti.join
	#r = Reseau.new host, port, team
	#Thread.new do |t|
	#	aff_menus
	#	while inp = $stdin.gets
	#		inp = inp.delete! "\n"
	#		end
	#		aff_menus
	#	end
	#end
#
#	while line = r.read do
#		puts line
	#end
#r.close
end
