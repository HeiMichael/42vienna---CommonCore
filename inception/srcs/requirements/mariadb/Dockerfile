FROM debian:bookworm

RUN apt-get update -y && apt-get upgrade -y && apt-get install mariadb-server \
    # && rm -rf /var/lib/apt/lists/* (this removes metadata after APT stores them in there - they are not needed)

#copy mariadb init script
COPY ./tools/init-db.sh /docker-entrypoint-initdb.d/

EXPOSE 3306

CMD ["mysqld"]