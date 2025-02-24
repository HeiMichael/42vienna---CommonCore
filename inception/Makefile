# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 15:48:13 by miheider          #+#    #+#              #
#    Updated: 2025/02/19 13:05:29 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME: inception

.PHONY: all build up down

all: build up

build:
	docker-compose -f ./srcs/docker-compose.yml build

up:
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker-compose -f ./srcs/docker-compose.yml down

start:
	docker-compose -f ./srcs/docker-compose.yaml start -d

stop:
	docker-compose -f ./srcs/docker-compose.yaml stop

stats:
	docker ps


