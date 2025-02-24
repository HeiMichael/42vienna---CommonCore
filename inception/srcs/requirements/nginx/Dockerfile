FROM debian:bookworm

RUN apt-get update -y && apt-get upgrade -y && apt-get install -y nginx

#create SSL dir
RUN mkdir -p /etc/nginx/ssl

#generate self-signed SSL certificate
RUN

#copy custom nginx certificate
COPY conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]




# Generate a self-signed SSL certificate
#RUN openssl req -x509 -nodes -days 365 \
#    -subj "/C=AT/ST=Vienna/L=Vienna/O=42Vienna/CN=localhost" \
#    -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.key \
#    -out /etc/nginx/ssl/nginx.crt